/*
 * negamax.h
 *
 *  Created on: Nov 1, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "negamax.h"

/**
 * Evaluate a game state.
 */
static int evaluate(board_t *board) {
    board_cell_t *cell = &(board->cells[0][0]);
    board_cell_t *max = cell + BOARD_NUM_CELLS;
    int max_threat = 0;
    int max_benefit = 0;
    int max_weight = 0;

    for(; cell < max; ++cell) {
        if(cell->player_id == NO_PLAYER) {
            max_threat = MAX(max_threat, cell->threat);
            max_benefit = MAX(max_benefit, cell->benefit);
            max_weight = MAX(max_weight, cell->weight);
        }
    }
    ++max_weight;
    return (max_threat > max_benefit ? -1 : 1) * max_weight;
}

/**
 * Recursively calculate an approximation of the Negamax value of a the
 * successors of a given game state. This function yields the chosen next
 * move by means of max_cell.
 */
int negamax(board_t *board,
            local_space_t *local_space,
            board_cell_t *prev_cell,
            board_cell_t **max_cell,
            player_t player_id,
            const int color,
            const int depth,
            const int num_empty_cells) {

    ordered_cell_seq_t successors;
    board_cell_t **cell;
    board_cell_t **max;
    int max_val = -1 * (1 << 15); /* should be lower than any eval result */
    int curr_val;

    /* reach the depth, game won, or no chips left to place */
    if(!depth
    || (NULL != prev_cell && NO_PLAYER != local_winner(local_space, prev_cell))
    || !num_empty_cells) {
        return (color ? -1 : 1) * evaluate(board);
    }

    /* generate the initial successor states */
    gen_successors(board, &successors);

    cell = &(successors.cells[0]);
    max = cell + successors.len;

    /* go over the successors and choose the best one */
    for(; cell < max; ++cell) {
        add_threat(local_space, *cell, player_id);

        /* calculate the negamax value for this node. */
        curr_val = -1 * negamax(
            board,
            local_space,
            *cell,
            NULL,
            OPPONENT(player_id),
            1 - color,
            depth - 1,
            num_empty_cells - 1
        );

        /* have we found a new best negamax value? */
        if(max_val < curr_val) {
            max_val = curr_val;

            /* only update the top level one, ignore all lower levels */
            if(NULL != max_cell) {
                *max_cell = *cell;
            }
        }

        remove_threat(local_space, *cell, player_id);
    }

    return max_val;
}
