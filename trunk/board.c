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

    DYNAMIC_ASSERT(NULL != board);

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

    DYNAMIC_ASSERT(NULL != board);

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
