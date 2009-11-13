/*
 * ocs.c
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "successors.h"

/**
 * Compare the importance ratings of two cells.
 */
static int compare_cell(const void *a, const void *b) {
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
void gen_successors(board_t *board, ordered_cell_seq_t *seq) {

    int len = 0;
    board_cell_t *all[BOARD_NUM_CELLS];
    board_cell_t **each = &(all[0]);

    board_cell_t **cells = &(seq->cells[0]);
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
    qsort(
        &(all[0]),
        (size_t) len,
        sizeof(board_cell_t *),
        &compare_cell
    );

    /* copy a few cell pointers into the ordered sequence. */
    len = seq->len = MIN(len, MAX_SUCCESSORS_TO_SEARCH);
    each = &(all[0]);
    for(; len; --len) {
        *(cells++) = *(each++);
    }
}
