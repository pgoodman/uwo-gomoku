/*
 * seq.h
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef SEQ_H_
#define SEQ_H_

#include "common.h"
#include "board.h"

/* types */
typedef struct {
    board_cell_t *cells[BOARD_LENGTH + 1]; /* trailing null */
} board_cell_seq_t;

/* globals */
board_cell_seq_t board_cell_seqs[BOARD_NUM_SEQS];

/* functions */
void init_seqs(board_t *board);
board_cell_t **cell_sequence(board_cell_t *cell, const int i);

#endif /* SEQ_H_ */
