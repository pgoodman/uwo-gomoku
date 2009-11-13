/*
 * rate.c
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "rate.h"

/**
 * Add in the default board weightings.
 */
static void weight_board(board_t *board) {
    int i;
    int j;

    const cell_rating_t o = BOARD_CENTER;
    const cell_rating_t t = (cell_rating_t) ((o * o) / 2);
    board_cell_t *cell = &(board->cells[0][0]);

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j, ++cell) {

            /* weight according to the circle formula, x^2 + y^2 */
            cell->rating[NO_PLAYER] = (cell_rating_t) (
                t - ((((i - o) * (i - o)) + ((j - o) * (j - o))) / 4)
            );
        }
    }
}

/**
 * Use pattern-matching to rate the board. This must be performed after the
 * sequences have actually been initialized.
 */
static void rate_board(void) {
    extern board_cell_seq_t board_cell_seqs[BOARD_NUM_SEQS];
    int i = BOARD_NUM_SEQS;
    board_cell_seq_t *seq;

    for(seq = &(board_cell_seqs[0]); i--; ++seq) {
        match_seq(&(seq->cells[0]));
    }
}

/**
 * Initialize board weights and ratings.
 */
void init_ratings(board_t *board) {
    weight_board(board);
    init_seqs(board);
    rate_board();
}
