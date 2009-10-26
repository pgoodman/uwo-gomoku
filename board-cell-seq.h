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

/* type representing a single character sequence of board cells and a
 * generator for the next sequence. */
typedef struct {
    int id; /* the id of last string that was generated */
    int dir; /* direction that we are generating strings from */
    int len;
    board_cell_t *cells[BOARD_LENGTH]; /* the string */
    board_t *board; /* the board from which the strings come */
} board_cell_seq_t;

void init_bcs(board_t *board, board_cell_seq_t *seq);
int generate_bcs(board_cell_seq_t *seq);

#endif /* BOARDCELLSEQ_H_ */
