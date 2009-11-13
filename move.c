/*
 * move.c
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "move.h"

static ordered_cell_seq_t max_succ;
static ordered_cell_seq_t min_succ;

static const cell_rating_t win_score = MIN(IT_BROKEN_4, IT_STRAIGHT_4);
static const cell_rating_t dt_score = MIN(IT_BROKEN_3, IT_EXTENDED_3);

static board_cell_t **max_cell;
static board_cell_t **min_cell;

/**
 * Can we choose an optimal move, given the generated successors?
 */
static board_cell_t *optimal_move(const player_t player_id,
                                  const player_t opponent_id,
                                  player_t *winner_id) {

    /* can we make a winning move immediately? */
    if((*max_cell)->rating[player_id] >= win_score) {
        *winner_id = player_id;
        return *max_cell;

    /* can we block a win? */
    } else if((*min_cell)->rating[opponent_id] >= win_score) {

        /* doesn't matter, we have lost anyway */
        if((*(min_cell + 1))->rating[opponent_id] >= dt_score) {
            *winner_id = opponent_id;
        }

        return *min_cell;

    /* can we make a double threat? */
    } else if((*max_cell)->rating[player_id] >= dt_score) {
        return *max_cell;

    /* can we block a double threat? */
    } else if((*min_cell)->rating[opponent_id] >= dt_score) {
        return *min_cell;
    }
    return NULL;
}

/**
 * Make a move.
 */
board_cell_t *make_move(board_t *board,
                        const player_t player_id,
                        const player_t opponent_id,
                        player_t *winner_id) {
    board_cell_t *move = NULL;
    int i = MAX_SUCCESSORS_TO_SEARCH;

    init_ratings(board);

    /* we won't waste processing power needlessly making a move. */
    if(matched_win()) {
        return NULL;
    }

    gen_successors(&board, &max_succ, player_id);
    gen_successors(&board, &min_succ, opponent_id);

    max_cell = &(max_succ.cells[0]);
    min_cell = &(min_succ.cells[0]);

    /* try to choose an optimal move */
    move = optimal_move(player_id, opponent_id, winner_id);
    if(NULL != move) {
        return move;
    }

    /* no immediate optimal move exists, lets try to choose the next
     * best move */

    /* order the moves according to their total importance
     * (weight + player 1 rating + player 2 rating), and then simulate null
     * moves on those cells. */
    gen_successors(board, &max_succ, NO_PLAYER);

    for(; i-- && NULL != *max_cell; ++max_cell) {
        move = *max_cell;

    }

    return *max_cell;
}
