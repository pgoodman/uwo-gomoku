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

/* functions */
void init_seqs(board_t *board);
board_cell_t **nth_cell_seq_at_cell(board_cell_t *cell, const int n);
board_cell_seq_t *nth_cell_seq(const int n);

#endif /* SEQ_H_ */
