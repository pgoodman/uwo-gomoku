/*
 * parse.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "board.h"

#ifndef O_BINARY
#define O_BINARY 0
#endif

#define D_LEFT_RIGHT 0
#define D_TOP_BOTTOM 1
#define D_LEFT_DIAG 2
#define D_RIGHT_DIAG 3

/**
 * Read in the board from memory. This goes straight to file descriptors
 * instead of file pointers to avoid needlessly passing the board from
 * buffer to buffer.
 */
int read_board(board_t *board) {
    ssize_t got; /* number of characters read into the buffer */
    int fd; /* file descriptor */
    int i; /* row */
    int j; /* column */
    int k = 0; /* buffer index */
    int top = BOARD_LENGTH; /* binding box */
    int left = BOARD_LENGTH;
    int bottom = 0;
    int right = 0;
    char buffer[BOARD_BUFFER_SIZE]; /* text buffer for file contents */
    char c; /* current character in the buffer */
    board_cell_t *cell; /* current cell in the board */

    /* open the file */
    fd = open(BOARD_DIR BOARD_FILE, O_RDONLY | O_BINARY);
    if(-1 == fd) {
        return 0;
    }

    /* get the game board, include any possible \n's or \r's and spaces. */
    got = read(fd, buffer, BOARD_BUFFER_SIZE * sizeof(char));
    close(fd);

    if(got < (BOARD_MIN_BUFFER_SIZE - 1)) {
        return 0;
    }

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++k) {

            c = buffer[k];
            cell = &(board->cells[i][j]);

            /* ignore non-number values */
            if('0' != c && '1' != c && '2' != c) {
                continue;
            }

            /* empty cell */
            if('0' == c) {
                cell->is_nothing = 1;
                ++board->num_empty_cells;

            /* played cell */
            } else {
                cell->is_nothing = 0;

                /* find the exact bounding box of the elements */
                left = MIN(j, left);
                right = MAX(j, right);
                top = MAX(i, top);
                bottom = MIN(i, bottom);

                /* bring in the other elements */
                if('1' == c) {
                    cell->player_id = PLAYER_1;
                } else {
                    cell->player_id = PLAYER_2;
                }
            }

            ++j;
        }
    }

    /* find the extended bounding box */
    board->left = MIN(left, MAX(0, left - SEARCH_BOUNDS));
    board->top = MIN(top, MAX(0, top - SEARCH_BOUNDS));
    board->right = MAX(right, MIN(BOARD_LENGTH, right + SEARCH_BOUNDS));
    board->top = MAX(top, MIN(BOARD_LENGTH, top + SEARCH_BOUNDS));

    return 1;
}

/**
 * Output the board back into the board file.
 */
int put_board(board_t *board) {
    int i; /* row */
    int j; /* column */
    int k = -1; /* buffer index */
    int fd; /* file descriptor */
    char buffer[BOARD_MIN_BUFFER_SIZE]; /* character buffer for game board */
    board_cell_t *cell; /* current cell in game board */
    ssize_t put; /* number of characters put into the file from the buffer */

    /* fill the buffer */
    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {

            cell = &(board->cells[i][j]);

            /* type safety is fun :D */
            if(cell->is_nothing) {
                buffer[++k] = '0';
            } else if(cell->player_id == PLAYER_1) {
                buffer[++k] = '1';
            } else if(cell->player_id == PLAYER_2) {
                buffer[++k] = '2';
            }

            buffer[++k] = ' ';
        }
        buffer[k] = '\n'; /* replaces trailing space on current line */
    }

    /* open the file and directly transfer the buffer */
    fd = open(BOARD_DIR BOARD_FILE, O_TRUNC | O_CREAT | O_WRONLY);
    if(-1 == fd) {
        return 0;
    }

    put = write(fd, &(buffer[0]), BOARD_MIN_BUFFER_SIZE * sizeof(char));
    close(fd);

    if(put < BOARD_MIN_BUFFER_SIZE) {
        return 0;
    }

    return 1;
}

/**
 * Initialize a board sequence generator.
 */
void reset_board_string(const board_t *board, board_cell_string_t *seq) {
    seq->board = board;
    seq->id = -1;
    seq->dir = D_LEFT_RIGHT;
}

/**
 * Update which sequence to get and the current sequence direction.
 */
static void update_board_string(board_cell_string_t *seq) {
    ++(seq->id);

    /* should we switch direction or are we done generating sequences? */
    switch(seq->dir) {
        case D_LEFT_RIGHT:
        case D_TOP_BOTTOM:
            if(seq->id > BOARD_LENGTH) {
                seq->id = 0;
                ++seq->dir;
            }
            break;
        case D_LEFT_DIAG:
        case D_RIGHT_DIAG:
            if(seq->id > BOARD_NUM_DIAGONALS) {
                seq->id = 0;
                ++seq->dir;
            }
            break;
        default:
            seq->dir = -1;
            break;
    }
}

/**
 * Generate a single board string. A board sequence is one which has:
 *
 *   i)   at least one unused board position;
 *   ii)  at least one used board positions
 *   iii) comes from a horizontal, vertical, or diagonal.
 *   iv)  has length at least WINNING_SEQUENCE_LENGTH and at most BOARD_LENGTH
 *
 * Each board string has as zero representing an empty cell, a 1 representing
 * a cell played by player 1, and a 2 representing a cell played by player 2.
 * There are no spaces between the cells (i.e. characters) and each generated
 * string is null-terminated.
 */
int generate_board_string(board_cell_string_t *seq) {

    int empty_board_pos_found;
    int non_empty_board_pos_found;
    int i = 0;
    int j = 0;
    int i_incr = 0;
    int j_incr = 0;
    int k = 0;
    int offset;
    board_cell_t *cell;

    do {
        empty_board_pos_found = 0;
        non_empty_board_pos_found = 0;

        /* advance to the next sequence */
        update_board_string(seq);

        if(seq->dir < 0) {
            return 0;
        }

        /* the offset for diagonal queries */
        offset = WINNING_SEQUENCE_LENGTH + seq->id;

        /* configurations for how to loop over the game board */
        switch(seq->dir) {
            case D_LEFT_RIGHT:
                i = seq->id;
                j_incr = 1;
                break;
            case D_TOP_BOTTOM:
                j = seq->id;
                i_incr = 1;
                break;
            case D_LEFT_DIAG:
                i = MAX(0, offset - BOARD_LENGTH);
                j = MAX(0, BOARD_LENGTH - offset);
                i_incr = 1;
                j_incr = 1;
                break;
            case D_RIGHT_DIAG:
                i = BOARD_LENGTH - 1 - MAX(0, offset - BOARD_LENGTH);
                j = BOARD_LENGTH - 1 - MAX(0, BOARD_LENGTH - offset);
                i_incr = -1;
                j_incr = -1;
                break;
        }

        /* fill the string */
        for(; i >= 0 && i < BOARD_LENGTH && j >= 0 && j < BOARD_LENGTH; ++k) {
            cell = &(seq->board[i][j]);

            /* set the string values */
            if(cell->is_nothing) {
                seq->str[k] = '0';
                empty_board_pos_found = 1;
            } else if(cell->player_id == PLAYER_1) {
                seq->str[k] = '1';
                non_empty_board_pos_found = 1;
            } else {
                seq->str[k] = '2';
                non_empty_board_pos_found = 1;
            }

            i += i_incr;
            j += j_incr;
        }

        seq->str[k] = '\0'; /* null terminate */

    } while(!(empty_board_pos_found && non_empty_board_pos_found));
}
