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
    threat_rating_t threat_benefit[2];
    threat_rating_t threat_rating;
    unsigned int is_nothing:1;
} board_cell_t;

/* board type */
typedef struct {
    board_cell_t cells[BOARD_LENGTH][BOARD_LENGTH];
    int num_empty_cells;
    /*int left;
    int top;
    int right;
    int bottom;*/
} board_t;

int read_board(board_t *);
int put_board(board_t *);

#endif /* BOARD_H_ */
