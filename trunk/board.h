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
#include "md5/md5.h"

/* board cell type */
typedef struct {
    player_t player_id;
    cell_rating_t rating[3];
    cell_rating_t chip_rating;
} board_cell_t;

/* board type */
typedef struct {
    board_cell_t cells[BOARD_LENGTH][BOARD_LENGTH];
    int num_empty_cells;
} board_t;

int read_board(board_t *);
int put_board(board_t *);
void hash_board(board_t *board, char hash[33]);

#endif /* BOARD_H_ */
