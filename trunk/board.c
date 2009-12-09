/*
 * parse.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "board.h"

/**
 * Read in the board from memory.
 */
int read_board(board_t *board) {

    int i; /* row */
    int j; /* column */
    int k = 0; /* buffer index */
    char buffer[BOARD_BUFFER_SIZE]; /* text buffer for file contents */
    char c; /* current character in the buffer */
    board_cell_t *cell; /* current cell in the board */

    DYNAMIC_ASSERT(NULL != board);

    board->num_empty_cells = 0;

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
                ++(board->num_empty_cells);

            } else if('1' == c) {
                cell->player_id = PLAYER_1;

            } else if('2' == c) {
                cell->player_id = PLAYER_2;

            /* non-cell */
            } else {
                continue;
            }

            /* add default null chip and empty cell ratings in */
            cell->chip_rating = 0;
            cell->rating[NO_PLAYER] = 0;
            cell->rating[PLAYER_1] = 0;
            cell->rating[PLAYER_2] = 0;

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
    for(i = 0, cell = &(board->cells[0][0]); i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j, ++cell) {

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

/**
 * Return the md5 hash of the game board when we toggle a specific board
 * position.
 */
void hash_board(board_t *board, char hash[33]) {

    board_cell_t *cell = &(board->cells[0][0]);
    char board_str[BOARD_NUM_CELLS + 1];
    char *c = &(board_str[0]);
    int i = BOARD_NUM_CELLS;

    for(; i--; ++cell, ++c) {
        switch(cell->player_id) {
            case NO_PLAYER: *c = '0'; continue;
            case PLAYER_1: *c = '1'; continue;
            case PLAYER_2: *c = '2'; continue;
        }
    }
    *c = '\0';

    md5(&(board_str[0]), &(hash[0]));
}

