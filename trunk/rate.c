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
    int i = -1;
    board_cell_seq_t *seq;
    while(NULL != (seq = nth_cell_seq(++i))) {
        match_seq(&(seq->cells[0]));
    }
}

/**
 * How to rate a match of 5 chips in a row.
 */
static void rate5(board_cell_t *c1,
                  board_cell_t *c2,
                  board_cell_t *c3,
                  board_cell_t *c4,
                  board_cell_t *c5) {

    c1->chip_rating += IT_STRAIGHT_5;
    c2->chip_rating += IT_STRAIGHT_5;
    c3->chip_rating += IT_STRAIGHT_5;
    c4->chip_rating += IT_STRAIGHT_5;
    c5->chip_rating += IT_STRAIGHT_5;
}

/**
 * How to rate a match of 4 chips with an empty cell on one side and two empties
 * on another side.
 */
static void rate4_extended(board_cell_t *c1,
                           board_cell_t *c2,
                           board_cell_t *c3,
                           board_cell_t *c4,
                           board_cell_t *e1,
                           board_cell_t *e2) {
    const player_t pid = c1->player_id;
    c1->chip_rating += IT_EXTENDED_4;
    c2->chip_rating += IT_EXTENDED_4;
    c3->chip_rating += IT_EXTENDED_4;
    c4->chip_rating += IT_EXTENDED_4;

    e1->rating[pid] += IT_EXTENDED_4;
    e2->rating[pid] += IT_EXTENDED_4;
}

/**
 * How to rate a match of 4 chips with either an empty on one of the side or an
 * empty somewhere in the middle.
 */
static void rate4_straight_broken(board_cell_t *c1,
                                  board_cell_t *c2,
                                  board_cell_t *c3,
                                  board_cell_t *c4,
                                  board_cell_t *e1) {
    const player_t pid = c1->player_id;
    c1->chip_rating += IT_STRAIGHT_4;
    c2->chip_rating += IT_STRAIGHT_4;
    c3->chip_rating += IT_STRAIGHT_4;
    c4->chip_rating += IT_STRAIGHT_4;

    e1->rating[pid] += IT_STRAIGHT_4;
}

/**
 * How to rate a match of 3 chips with two empties on each side.
 */
void rate3_straight(board_cell_t *c1,
                    board_cell_t *c2,
                    board_cell_t *c3,
                    board_cell_t *e1,
                    board_cell_t *e2) {
    const player_t pid = c1->player_id;
    c1->chip_rating += IT_STRAIGHT_3;
    c2->chip_rating += IT_STRAIGHT_3;
    c3->chip_rating += IT_STRAIGHT_3;

    e1->rating[pid] += IT_STRAIGHT_3;
    e2->rating[pid] += IT_STRAIGHT_3;
}

/**
 * How to rate 3 cells, with an empty in the middle of 3 chips, and two empties
 * on each side.
 */
void rate3_broken(board_cell_t *c1,
                  board_cell_t *c2,
                  board_cell_t *c3,
                  board_cell_t *e1,
                  board_cell_t *e2,
                  board_cell_t *e3) {
    const player_t pid = c1->player_id;
    c1->chip_rating += IT_BROKEN_3;
    c2->chip_rating += IT_BROKEN_3;
    c3->chip_rating += IT_BROKEN_3;

    e1->rating[pid] += IT_BROKEN_3;
    e2->rating[pid] += IT_BROKEN_3_MID;
    e3->rating[pid] += IT_BROKEN_3;
}

/**
 * How to rate a match of 3 chips with an empty on one side and two empties on
 * another.
 */
void rate3_extended(board_cell_t *c1,
                    board_cell_t *c2,
                    board_cell_t *c3,
                    board_cell_t *e1,
                    board_cell_t *e2,
                    board_cell_t *e3) {
    const player_t pid = c1->player_id;
    c1->chip_rating += IT_EXTENDED_3;
    c2->chip_rating += IT_EXTENDED_3;
    c3->chip_rating += IT_EXTENDED_3;

    e1->rating[pid] += IT_EXTENDED_3;
    e2->rating[pid] += IT_EXTENDED_3_MID;
    e3->rating[pid] += IT_EXTENDED_3;
}

/**
 * Initialize board weights and ratings.
 */
void init_ratings(board_t *board) {
    weight_board(board);
    init_seqs(board);
    init_matcher(
        &rate5,
        &rate4_straight_broken,
        &rate4_straight_broken,
        &rate4_extended,
        &rate3_straight,
        &rate3_broken,
        &rate3_extended
    );
    rate_board();
}

/**
 * Clear the ratings (not the weights!!).
 */
void clear_ratings(board_t *board) {
    board_cell_t *cell = &(board->cells[0][0]);
    board_cell_t *bound = cell + BOARD_NUM_CELLS;

    for(; cell < bound; ++cell) {
        cell->rating[PLAYER_1] = cell->rating[PLAYER_2] = cell->chip_rating = 0;
    }
}

/**
 * Rate the sequences that intersect a given cell.
 */
void rate_seqs_at_cell(board_cell_t *pivot_cell) {
    int i;
    for(i = 0; i < 4; ++i) {
        match_seq(nth_cell_seq_at_cell(pivot_cell, i));
    }
}
