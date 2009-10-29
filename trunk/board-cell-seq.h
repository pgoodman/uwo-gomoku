/*
 * board-cell-seq.h
 *
 *  Created on: Oct 25, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef BOARDCELLSEQ_H_
#define BOARDCELLSEQ_H_

#include "common.h"
#include "board.h"

#define D_LEFT_RIGHT 0
#define D_TOP_BOTTOM 1
#define D_LEFT_DIAG 2
#define D_RIGHT_DIAG 3

/* type representing a generator to generate all board cells in sequence in
 * all directions. */
typedef struct {
    int prev; /* the id of previous cell generated */
    board_t *board; /* the board from which the strings come */
} board_cell_generator_t;

void init_bcs(board_t *board, board_cell_generator_t *seq);
int generate_bcs(board_cell_generator_t *seq, board_cell_t **cell);

#endif /* BOARDCELLSEQ_H_ */
