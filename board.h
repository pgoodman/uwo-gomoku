/*
 * parse.h
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "common.h"

/* board cell type */
typedef struct {
    player_t player_id;
    unsigned int is_nothing:1;
} board_cell_t;

/* board type */
typedef struct {
    board_cell_t cells[BOARD_LENGTH][BOARD_LENGTH];
    int num_empty_cells;
    int left; /* bounding box */
    int top;
    int right;
    int bottom;
} board_t;

/* type representing a single character sequence of board cells and a
 * generator for the next sequence. */
typedef struct {
    int id; /* the id of last string that was generated */
    int dir; /* direction that we are generating strings from */
    char str[BOARD_LENGTH + 1]; /* the string */
    board_t *board; /* the board from which the strings come */
} board_cell_string_t;

int read_board(board_t *);
int put_board(board_t *);

void reset_board_string(cont board_t *board, board_cell_string_t *seq);
int generate_board_string(board_cell_string_t *seq);

#endif /* BOARD_H_ */
