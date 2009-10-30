/*
 * ocs.c
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "ocs.h"

/**
 * Compare the importance ratings of two cells.
 */
static int compare_cell(const void *a, const void *b) {
    return (
        (*(board_cell_t **) b)->importance - (*(board_cell_t **) a)->importance
    );
}

/**
 * Fill an ordered cell sequence with the most import MAX_SUCCESSORS_TO_SEARCH
 * cells in the board.
 *
 * This function also returns the average of all importance ratings.
 */
int fill_ocs(board_t *board, ordered_cell_seq_t *seq) {

    int len = 0;
    /*double total = 0.0;*/
    board_cell_t *all[BOARD_NUM_CELLS];
    board_cell_t **each = &(all[0]);

    board_cell_t **cells = &(seq->cells[0]);
    board_cell_t *cell = &(board->cells[0][0]);
    board_cell_t *cell_max = cell + BOARD_NUM_CELLS;

    /* get pointers to all cells in the board */
    for(; cell < cell_max; ++cell) {
        if(NO_PLAYER == cell->player_id) {
            /*total += cell->importance;*/
            *(each++) = cell;
            ++len;
        }
    }

    /*total /= len;*/

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

    return seq->len > 0 ? seq->cells[0]->importance : 0; /*(int) total;*/
}
