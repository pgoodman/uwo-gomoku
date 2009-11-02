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
    int i; /* row */
    int j; /* column */
    int k = 0; /* buffer index */
    char buffer[BOARD_BUFFER_SIZE]; /* text buffer for file contents */
    char c; /* current character in the buffer */
    /*const int K = pow(BOARD_CENTER, 2) * 2;*/
    board_cell_t *cell; /* current cell in the board */
    DYNAMIC_ASSERT(NULL != board);

    /* read the board in from the file */
    i = file_get_contents(
        BOARD_DIR BOARD_FILE,
        &(buffer[0]),
        BOARD_MIN_BUFFER_SIZE - 1,
        BOARD_BUFFER_SIZE
    );

    /* file read failed */
    if(!i) {
        return 0;
    }

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++k) {

            c = buffer[k];
            cell = &(board->cells[i][j]);

            if('0' == c) {
                cell->player_id = NO_PLAYER;

                /* set the default importance/threat rating. this is a weighting
                 * that trends toward the center of the board. This helps as a
                 * tie breaker between same ranked cells and also it makes the
                 * algorithm prefer cells closer to the center as there is less
                 * space to make diagonal wins around the corners. */
                cell->weight = 0; /*= (
                    (K - (
                        pow(i - BOARD_CENTER, 2) +
                        pow(j - BOARD_CENTER, 2))
                    ) / 4
                );*/
                cell->threat = 0;
                cell->benefit = 0;

                ++board->num_empty_cells;

            } else if('1' == c) {
                cell->weight = 0;
                cell->threat = 0;
                cell->benefit = 0;
                cell->player_id = PLAYER_1;

            } else if('2' == c) {
                cell->weight = 0;
                cell->threat = 0;
                cell->benefit = 0;
                cell->player_id = PLAYER_2;

            /* non-cell */
            } else {
                continue;
            }

            ++j;
        }
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
    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {

            cell = &(board->cells[i][j]);

            /* type safety is fun :D */
            if(cell->player_id == NO_PLAYER) {
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

    /* write the buffer to a file. */
    i = file_put_contents(
        BOARD_DIR BOARD_FILE,
        &(buffer[0]),
        BOARD_MIN_BUFFER_SIZE
    );

    return i;
}
