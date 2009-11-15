/*
 * move.c
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "move.h"

#define D(x)

static const cell_rating_t win_score = MIN(IT_BROKEN_4, IT_STRAIGHT_4);
static const cell_rating_t dt_score = MIN(IT_BROKEN_3, IT_EXTENDED_3);

/**
 * Can we choose an optimal move, given the generated successors?
 */
static board_cell_t *optimal_move(board_cell_t *max_cell,
                                  board_cell_t *min_cell,
                                  const player_t player_id,
                                  const player_t opponent_id,
                                  player_t *winner_id) {

    /* can we make a winning move immediately? */
    if(max_cell->rating[player_id] >= win_score) {
        *winner_id = player_id;
        return max_cell;

    /* can we block a win? */
    } else if(min_cell->rating[opponent_id] >= win_score) {
        return min_cell;

    /* can we make a double threat? */
    } else if(max_cell->rating[player_id] >= dt_score) {
        return max_cell;

    /* can we block a double threat? */
    } else if(min_cell->rating[opponent_id] >= dt_score) {
        return min_cell;
    }

    return NULL;
}

/**
 * Choose a move to make.
 */
board_cell_t *make_move(board_t *board,
                        const player_t player_id,
                        const player_t opponent_id,
                        player_t *winner_id) {

    ordered_cell_seq_t max_succ;
    ordered_cell_seq_t min_succ;

    board_cell_t **max_cell;
    board_cell_t *max_move;

    board_cell_t **min_cell;
    board_cell_t *min_move;

    int num_succ;

    /* rate all of the empty cells according to which patterns they belong.
     * Also give them a default weight, and construct the sequence space. */
    init_ratings(board);

    /* we won't waste processing power needlessly making a move. */
    if(matched_win()) {
        return NULL;
    }

    /* order the cells according to the best rated empty cells that fit as
     * patterns. */
    gen_successors(board, &max_succ, player_id);
    gen_successors(board, &min_succ, opponent_id);

    D( printf("checking for optimal move... \n"); )

    /* try to choose an optimal move */
    max_move = optimal_move(
        max_succ.cells[0],
        min_succ.cells[0],
        player_id,
        opponent_id,
        winner_id
    );

    /* an optimal move was found, take it */
    if(NULL != max_move) {
        D( printf("optimal move chosen. \n"); )
        return max_move;

    /* we can only make 1 move so take it. */
    } else if(1 == max_succ.len) {
        D( printf("only move chosen. \n"); )
        return max_succ.cells[0];
    }

    /* no immediate optimal move exists, lets try to choose the next
     * best move. The idea is that we want to choose the empty cell that has
     * the highest rating as a future chip placement and not as a future empty
     * cell. In order to do so, we must consider the chips all at once and
     * not in isolation. Thus, we must simulate making a chip placement, and
     * if it belongs to a matched pattern, then we want to rate that chip
     * placement and all other possible placements of it. To do things all at
     * once, the rating must be incremental and not undone after each
     * simulated chip placement. */

    D( printf("searching for next best move... \n"); )

    /* order the moves according to their total importance
     * (weight + player 1 rating + player 2 rating), and then simulate null
     * moves on those cells. */
    for(max_cell = &(max_succ.cells[0]); (max_succ.len)--; ++max_cell) {
        max_move = *max_cell;

        /* make our opponents move */
        max_move->player_id = opponent_id;
        rate_pivoted_seqs(max_move, RATE_CHIPS);

        /* generate the empties once a chip has been placed. we don't actually
         * care what order we look at them because we look at all of them. */
        gen_successors(board, &min_succ, NO_PLAYER);
        { /* go down to the second ply */
            num_succ = min_succ.len;
            for(min_cell = &(min_succ.cells[0]); num_succ--; ++min_cell) {
                min_move = *min_cell;
                min_move->player_id = opponent_id;
                rate_pivoted_seqs(min_move, RATE_CHIPS);
                min_move->player_id = player_id;
                rate_pivoted_seqs(min_move, RATE_CHIPS);
                min_move->player_id = NO_PLAYER;
            }
        }

        /* now make our move */
        max_move->player_id = player_id;
        rate_pivoted_seqs(max_move, RATE_CHIPS);

        { /* go down to the second ply */
            num_succ = min_succ.len;
            for(min_cell = &(min_succ.cells[0]); num_succ--; ++min_cell) {
                min_move = *min_cell;
                min_move->player_id = opponent_id;
                rate_pivoted_seqs(min_move, RATE_CHIPS);
                min_move->player_id = player_id;
                rate_pivoted_seqs(min_move, RATE_CHIPS);
                min_move->player_id = NO_PLAYER;
            }
        }

        max_move->player_id = NO_PLAYER;
    }

    clear_ratings(board);

    /* rate the cells according to their new chip ratings, as well as weights
     * and prior pattern ratings. */
    gen_successors(board, &max_succ, NO_PLAYER);

    D( printf("move chosen. \n"); )

    /* return the best rated cell */
    return max_succ.cells[0];
}
