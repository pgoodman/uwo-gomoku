/*
 * move.c
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "move.h"

#define D(x)

static const cell_rating_t win_score = IT_STRAIGHT_4;
static const cell_rating_t dt_score = IT_BROKEN_3;

/**
 * Can we choose an optimal move, given the generated successors?
 */
static board_cell_t *optimal_move(board_cell_t *max_cell,
                                  board_cell_t *min_cell,
                                  const player_t player_id,
                                  const player_t opponent_id) {

    /* can we make a winning move immediately? */
    if(max_cell->rating[player_id] >= win_score) {
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
 * Perform a depth-first search that calculates the incremental future chip
 * rating for each cell for each type of chip.
 */
static void search_cell_order(board_t *board,
                              board_cell_t **first_cell,
                              const player_t player_id,
                              const player_t opponent_id,
                              const int depth) {

    board_cell_t **seq_cell;
    board_cell_t *cell;
    int next_depth = depth - 1;

    /* go over all empty cells within the bounding box and calculate their
     * future chip ratings. */
    for(seq_cell = first_cell; *seq_cell != NULL; ++seq_cell) {
        cell = *seq_cell;

        if(NO_PLAYER != cell->player_id) {
            continue;
        }

        /* make our opponents move */
        cell->player_id = opponent_id;
        clear_matches();
        rate_seqs_at_cell(cell);

        if(next_depth > 0 && !matched_win(NO_PLAYER)) {
            search_cell_order(
                board,
                first_cell,
                player_id,
                opponent_id,
                next_depth
            );
        }

        /* now make our move */
        cell->player_id = player_id;
        clear_matches();
        rate_seqs_at_cell(cell);

        if(next_depth > 0 && !matched_win(NO_PLAYER)) {
            search_cell_order(
                board,
                first_cell,
                player_id,
                opponent_id,
                next_depth
            );
        }

        cell->player_id = NO_PLAYER;
    }
}

/**
 * Choose a move to make.
 */
board_cell_t *choose_move(board_t *board,
                          const player_t player_id,
                          const player_t opponent_id) {

    ordered_cell_seq_t max_succ;
    ordered_cell_seq_t min_succ;
    board_cell_t *max_move;

    /* rate all of the empty cells according to which patterns they belong.
     * Also give them a default weight, and construct the sequence space. */
    init_ratings(board);

    /* we won't waste processing power needlessly making a move. */
    if(matched_win(NO_PLAYER)) {
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
        opponent_id
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

    clear_ratings(board);
    bound_successors(board);
    gen_successors(board, &max_succ, NO_PLAYER);

    search_cell_order(
        board,
        &(max_succ.cells[0]),
        player_id,
        opponent_id,
        SEARCH_DEPTH
    );

    /* rate the cells according to their new chip ratings, as well as weights
     * and prior pattern ratings. */
    gen_successors(board, &max_succ, NO_PLAYER);

    /* we went and did some pretty sloppy ratings and matches so lets put
     * the ratings and matcher back into a nice state. */
    clear_ratings(board);
    clear_matches();

    D( printf("move chosen. \n"); )

    /* return the best rated cell */
    return max_succ.cells[0];
}
