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
        match_seq(&(seq->cells[0]), 1, IGNORE_CHIPS);
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

/**
 * Clear the ratings (not the weights!!).
 */
void clear_ratings(board_t *board) {
    board_cell_t *cell = &(board->cells[0][0]);
    board_cell_t *bound = cell + BOARD_NUM_CELLS;

    for(; cell < bound; ++cell) {
        cell->rating[PLAYER_1] = cell->rating[PLAYER_2] = 0;
    }
}

/**
 * Rate the sequences that intersect a given cell.
 */
static void rate_seq(board_cell_t *pivot_cell,
                     const int mult,
                     const int rate_chips) {
    int i;
    for(i = 0; i < 4; ++i) {
        match_seq(cell_sequence(pivot_cell, i), mult, rate_chips);
    }
}

/**
 * Rate the cell sequences pivoted at a given cell.
 */
void rate_pivoted_seqs(board_cell_t *pivot_cell, const int rate_chips) {
    rate_seq(pivot_cell, 1, rate_chips);
}

/**
 * Un-rate the cell sequences pivoted at a given cell.
 */
void unrate_pivoted_seqs(board_cell_t *pivot_cell, const int rate_chips) {
    rate_seq(pivot_cell, -1, rate_chips);
}
