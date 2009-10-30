/*
 * localspace.c
 *
 *  Created on: Oct 30, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "localspace.h"

/**
 * Fill up the cell space. Each cell space is a vector in the local space of
 * the cell pivoted at (i_init, j_init).
 */
static void fill_cell_space(board_t *board,
                            board_cell_t **local_cells,
                            const int i_init, /* row */
                            const int j_init, /* column */
                            const int i_incr,
                            const int j_incr) {

    /* figure out the looping bounds */
    const int N = LOCAL_SPACE;
    const int i_start = i_init - (i_incr * N);
    const int i_end = i_init + (i_incr * N);

    const int j_end = j_init + (j_incr * N);
    const int j_start = j_init - (j_incr * N);

    const int i_min = MIN(i_start, i_end);
    const int i_max = MAX(i_start, i_end);
    const int j_min = MIN(j_start, j_end);
    const int j_max = MAX(j_start, j_end);

    int i;
    int j;

    /* ignore a cell that meets these conditions */
    if(i_min < 0 || i_max >= BOARD_LENGTH
    || j_min < 0 || j_max >= BOARD_LENGTH) {
        *(local_cells) = NULL;
        return;
    }

    /* fill this local space */
    for(i = i_start, j = j_start;
        i >= i_min && i <= i_max && j >= j_min && j <= j_max;
        i += i_incr, j += j_incr) {

        *(local_cells++) = &(board->cells[i][j]);
    }
}

/**
 * Fill up the local space. The local space is used for figuring out the
 * importance of each cell.
 */
void init_local_space(board_t *board, local_space_t *space) {
    int i;
    int j;
    cell_space_t *cell_space = &(space->cell_space[0]);

    /* fill up the local space */
    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            fill_cell_space(board, &(cell_space->horizontals[0]), i, j, 0, 1);
            fill_cell_space(board, &(cell_space->verticals[0]), i, j, 1, 0);
            fill_cell_space(board, &(cell_space->left_diags[0]), i, j, 1, 1);
            fill_cell_space(board, &(cell_space->right_diags[0]), i, j, 1, -1);
            ++cell_space;
        }
    }

    /* store a pointer to the first cell of the board */
    space->first_cell = &(board->cells[0][0]);
}
