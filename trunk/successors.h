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
    board_cell_t *cells[MAX_SUCCESSORS_TO_SEARCH];
    int len;
} ordered_cell_seq_t;

void gen_successors(board_t *board, ordered_cell_seq_t *seq);

#endif /* SUCCESSORS_H_ */
