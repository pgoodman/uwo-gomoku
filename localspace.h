/*
 * localspace.h
 *
 *  Created on: Oct 30, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef LOCALSPACE_H_
#define LOCALSPACE_H_

#include <stdio.h>
#include "common.h"
#include "board.h"

typedef struct {
    board_cell_t *horizontals[WINNING_SEQ_LENGTH];
    board_cell_t *verticals[WINNING_SEQ_LENGTH];
    board_cell_t *left_diags[WINNING_SEQ_LENGTH];
    board_cell_t *right_diags[WINNING_SEQ_LENGTH];
} cell_space_t;

typedef struct {
    board_cell_t *first_cell;
    cell_space_t cell_space[BOARD_NUM_CELLS];
} local_space_t;

void init_local_space(board_t *board, local_space_t *space);

#endif /* LOCALSPACE_H_ */
