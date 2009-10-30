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
#include <math.h>

#include "common.h"


/* board cell type */
typedef struct {
    player_t player_id;
    threat_rating_t importance;
} board_cell_t;

/* board type */
typedef struct {
    board_cell_t cells[BOARD_LENGTH][BOARD_LENGTH];
    int num_empty_cells;
    game_status_t status;
} board_t;

int read_board(board_t *);
int put_board(board_t *);

#endif /* BOARD_H_ */
