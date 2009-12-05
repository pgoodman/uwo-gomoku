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
static board_cell_t *match_optimal_move(board_cell_t *max_cell,
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
 * Perform a search that also rates the board.
 */
static board_cell_t *rated_search(board_t *board,
                                  ordered_cell_seq_t *successors,
                                  const player_t player_id,
                                  const player_t opponent_id) {

    gen_successors(board, successors, NO_PLAYER);

    search_cell_order(
        board,
        &(successors->cells[0]),
        player_id,
        opponent_id,
        SEARCH_DEPTH
    );

    /* rate the cells according to their new chip ratings, as well as weights
     * and prior pattern ratings. */
    gen_successors(board, successors, NO_PLAYER);

    return successors->cells[0];
}

/**
 * Choose a move to make.
 */
board_cell_t *choose_move(board_t *board,
                          const player_t player_id,
                          const player_t opponent_id) {

    ordered_cell_seq_t max_succ;
    ordered_cell_seq_t min_succ;
    board_cell_t *optimal_move = NULL;

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
    optimal_move = match_optimal_move(
        max_succ.cells[0],
        min_succ.cells[0],
        player_id,
        opponent_id
    );

    if(1 == max_succ.len) {
        D( printf("only move chosen. \n"); )
        return max_succ.cells[0];
    }

    D( printf("searching for next best move... \n"); )

    clear_ratings(board);
    bound_successors(board);

    /* no optimal move, lets search for our move */
    if(NULL == optimal_move) {

        if(ENABLE_HISTORY) {
            import_board_history(board, player_id);
        }

        optimal_move = rated_search(
            board,
            &max_succ,
            player_id,
            opponent_id
        );

        clear_ratings(board);
        clear_matches();
    }

    /* lets try to figure out where our opponent is going and construct the
     * board history based on that. */
    if(ENABLE_HISTORY && 1 < max_succ.len) {
        optimal_move->player_id = player_id;

        import_board_history(board, player_id);

        rated_search(
            board,
            &max_succ,
            opponent_id,
            player_id
        );

        optimal_move->player_id = NO_PLAYER;
        export_board_history(board, player_id);
        clear_ratings(board);
        clear_matches();
    }

    /* return the best rated cell */
    return optimal_move;
}
