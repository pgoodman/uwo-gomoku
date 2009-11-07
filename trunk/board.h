/*
 * parse.h
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "common.h"
#include "file.h"

/* board cell type */
typedef struct {
    player_t player_id;
    cell_rating_t rating;
    /*cell_rating_t player_1;
    cell_rating_t player_2;
    cell_rating_t weight;*/
} board_cell_t;

/* board type */
typedef struct {
    board_cell_t cells[BOARD_LENGTH][BOARD_LENGTH];
    int num_empty_cells;
} board_t;

int read_board(board_t *);
int put_board(board_t *);

#endif /* BOARD_H_ */
