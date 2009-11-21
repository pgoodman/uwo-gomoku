/*
 * parse.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "board.h"

/**
 * Read in the board from memory. This goes straight to file descriptors
 * instead of file pointers to avoid needlessly passing the board from
 * buffer to buffer.
 */
int read_board(board_t *board) {

    char buffer[BOARD_BUFFER_SIZE]; /* text buffer for file contents */
    char *c = &(buffer[0]); /* current character in the buffer */
    int num_cells_left = BOARD_NUM_CELLS;
    board_cell_t *cell; /* current cell in the board */

    DYNAMIC_ASSERT(NULL != board);

    board->num_empty_cells = 0;

    /* read the board in from the file */
    *c = '\0';
    file_get_contents(
        BOARD_DIR BOARD_FILE,
        c,
        BOARD_MIN_BUFFER_SIZE - 1,
        BOARD_BUFFER_SIZE
    );

    /* file read failed */
    if(!*c) {
        return 0;
    }

    /* go character-by-character in the filled text buffer */
    for(cell = &(board->cells[0][0]); num_cells_left; ++c) {

        /* deal with the character */
        switch(*c) {
            case '0':
                cell->player_id = NO_PLAYER;
                ++(board->num_empty_cells);
                break;
            case '1': cell->player_id = PLAYER_1; break;
            case '2': cell->player_id = PLAYER_2; break;
            default: continue;
        }

        /* initialize the default values for this cell */
        cell->chip_rating = 0;
        cell->rating[NO_PLAYER] = 0; /* weight */
        cell->rating[PLAYER_1] = 0; /* cell rating */
        cell->rating[PLAYER_2] = 0;

        --num_cells_left;
        ++cell;
    }

    return 1;
}

/**
 * Output the board back into the board file.
 */
int put_board(board_t *board) {
    int i; /* row */
    int j; /* column */
    int k = -1; /* buffer index */
    char buffer[BOARD_MIN_BUFFER_SIZE]; /* character buffer for game board */
    board_cell_t *cell; /* current cell in game board */

    DYNAMIC_ASSERT(NULL != board);

    /* fill the buffer */
    for(i = 0, cell = &(board->cells[0][0]); i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j, ++cell) {
            switch(cell->player_id) {
                case NO_PLAYER: buffer[++k] = '0'; break;
                case PLAYER_1: buffer[++k] = '1'; break;
                case PLAYER_2: buffer[++k] = '2'; break;
                default: continue; /* shouldn't happen */
            }
            buffer[++k] = ' ';
        }
        buffer[k] = '\n'; /* replaces trailing space on current line */
    }

    /* write the buffer to a file. */
    i = file_put_contents(
        BOARD_DIR BOARD_FILE,
        &(buffer[0]),
        BOARD_MIN_BUFFER_SIZE
    );

    return i;
}
