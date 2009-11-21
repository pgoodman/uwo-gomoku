/*
 * ocs
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef SUCCESSORS_H_
#define SUCCESSORS_H_

#include <stdlib.h>

#include "common.h"
#include "board.h"

typedef struct {
    board_cell_t *cells[BOARD_NUM_CELLS + 1]; /* trailing null */
    int len;
} ordered_cell_seq_t;

void generate_successors(board_t *board,
                         ordered_cell_seq_t *seq,
                         const player_t player_id);

void bound_successors(board_t *board);

#endif /* SUCCESSORS_H_ */
