/*
 * ocs.c
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "successors.h"

static player_t which_player;

static int top = 0;
static int bottom = BOARD_LENGTH - 1;
static int right = BOARD_LENGTH - 1;
static int left = 0;

/**
 * Compare the importance ratings of two empty cells.
 */
static int compare_cell(const void *a, const void *b) {
    board_cell_t *bb = (*(board_cell_t **) b);
    board_cell_t *aa = (*(board_cell_t **) a);
    return (bb->rating[0] + bb->rating[which_player] + bb->chip_rating)
         - (aa->rating[0] + aa->rating[which_player] + aa->chip_rating);
}

/**
 * Compare the importance ratings of two empty cells.
 */
static int compare_cell_ratings(const void *a, const void *b) {
    board_cell_t *bb = (*(board_cell_t **) b);
    board_cell_t *aa = (*(board_cell_t **) a);
    return (bb->rating[0] + bb->rating[1] + bb->rating[2] + bb->chip_rating)
         - (aa->rating[0] + aa->rating[1] + aa->rating[2] + aa->chip_rating);
}

/**
 * Add a bounding to the successors.
 */
void bound_successors(board_t *board) {

    int i;
    int j;
    const int max_bound = BOUND_BOX_EXTEND;

    board_cell_t *cell;

    top = BOARD_LENGTH;
    right = 0;
    bottom = 0;
    left = BOARD_LENGTH;

    /* get the bounding box */
    for(cell = &(board->cells[0][0]), i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j, ++cell) {
            if(NO_PLAYER != cell->player_id) {
                top = MIN(i, top);
                right = MAX(j, right);
                bottom = MAX(i, bottom);
                left = MIN(i, left);
            }
        }
    }

    /* extend the bounding box by BOUND_BOX_EXTEND cells on each side */
    top = MAX(0, top - max_bound);
    right = MIN(BOARD_LENGTH - 1, right + max_bound);
    bottom = MIN(BOARD_LENGTH - 1, bottom + max_bound);
    left = MAX(0, left - max_bound);
}

/**
 * Fill an ordered cell sequence with the most import MAX_SUCCESSORS_TO_SEARCH
 * cells in the board.
 *
 * This function also returns the average of all importance ratings.
 */
void gen_successors(board_t *board,
                    ordered_cell_seq_t *seq,
                    const player_t player_id) {
    int i;
    int j;
    int len = 0;

    board_cell_t **each = &(seq->cells[0]);
    board_cell_t *cell;

    /* get pointers to all empty cells within the extended bounded box. */
    for(cell = &(board->cells[0][0]), i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j, ++cell) {
            if(NO_PLAYER == cell->player_id
            && i <= bottom && i >= top
            && j <= right && j >= left) {
                *(each++) = cell;
                ++len;
            }
        }
    }

    /* sort the cell pointers according to the cell importance rating */
    which_player = player_id;
    qsort(
        &(seq->cells[0]),
        (size_t) len,
        sizeof(board_cell_t *),
        (NO_PLAYER == player_id) ? &compare_cell_ratings : &compare_cell
    );

    seq->len = len;
    seq->cells[len] = NULL; /* add in the trailing null */
}
