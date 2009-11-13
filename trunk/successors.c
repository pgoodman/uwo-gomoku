/*
 * ocs.c
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "successors.h"

static player_t which_player;

/**
 * Compare the importance ratings of two cells.
 */
static int compare_cell(const void *a, const void *b) {
    board_cell_t *bb = (*(board_cell_t **) b);
    board_cell_t *aa = (*(board_cell_t **) a);
    return (bb->rating[0] + bb->rating[which_player])
         - (aa->rating[0] + aa->rating[which_player]);
}

/**
 * Compare the importance ratings of two cells.
 */
static int compare_cell_ratings(const void *a, const void *b) {
    board_cell_t *bb = (*(board_cell_t **) b);
    board_cell_t *aa = (*(board_cell_t **) a);
    return (bb->rating[0] + bb->rating[1] + bb->rating[2])
         - (aa->rating[0] + aa->rating[1] + aa->rating[2]);
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
    int len = 0;
    board_cell_t **each = &(seq->cells[0]);
    board_cell_t *cell = &(board->cells[0][0]);
    board_cell_t *cell_max = cell + BOARD_NUM_CELLS;

    /* get pointers to all cells in the board */
    for(; cell < cell_max; ++cell) {
        if(NO_PLAYER == cell->player_id) {
            *(each++) = cell;
            ++len;
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
