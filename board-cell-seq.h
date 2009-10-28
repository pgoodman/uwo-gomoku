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

/* type representing a single character sequence of board cells and a
 * generator for the next sequence. */
typedef struct {
    int id; /* the id of last string that was generated */
    int dir; /* direction that we are generating strings from */
    int len;
    int only_one;
    board_cell_t wall; /* wall on either side of the sequence */
    board_cell_t *cells[BOARD_LENGTH + 2]; /* sequence of cells with dummies */
    board_t *board; /* the board from which the strings come */
} board_cell_seq_t;

void init_bcs(board_t *board, board_cell_seq_t *seq, const player_t player_id);

int generate_bcs(board_cell_seq_t *seq);
int generate_nth_bcs(board_cell_seq_t *seq, const int n, const int dir);

void change_bcs_player(board_cell_seq_t *seq, const player_t player_id);

#endif /* BOARDCELLSEQ_H_ */
