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

#if 0
static void explore_threat_space(board_cell_t **succ,
                                 int num_succ) {
    board_cell_t **max_cell;
    board_cell_t **min_cell;
    board_cell_t *move;
    player_t foobar;
    ordered_cell_seq_t max_succ;
    ordered_cell_seq_t min_succ;

    for(; num_succ-- && NULL != *succ; ++succ) {
        move = *succ;

        /* undo ratings pivoted at move */
        unrate_pivoted_seqs(move);

        /* rate the sequences pivoted at move */
        move->player_id = _opponent_id;
        rate_pivoted_seqs(move);

        /* order the sequences according to ratings for us and for our
         * opponent. */
        gen_successors(game_board, &max_succ, _player_id);
        gen_successors(game_board, &min_succ, _opponent_id);

        /* if an optimal move exists then we won't search any deeper. */
        move = optimal_move(*max_cell, *min_cell, &foobar);

        if(NULL != move) {
            return move;
        }

        printf("hello.\n");

        /* undo the new ratings that were pivoted at move and re-do the
         * old ones */
        unrate_pivoted_seqs(move);
        move->player_id = NO_PLAYER;
        rate_pivoted_seqs(move);
    }
}
#endif


/**
 * Make a move.
 */
board_cell_t *make_move(board_t *board,
                        const player_t player_id,
                        const player_t opponent_id,
                        player_t *winner_id) {

    ordered_cell_seq_t max_succ;
    ordered_cell_seq_t min_succ;
    /*
    ordered_cell_seq_t max_move_succ;
    ordered_cell_seq_t min_move_succ;
    */
    board_cell_t **max_cell;
    board_cell_t **min_cell;


    board_cell_t *max_move;
    board_cell_t *min_move;
    board_cell_t *move; /*
    board_cell_t *result_move;

    int best = 0;
    int result_best;
    */
    int num_succ;

    /* we won't waste processing power needlessly making a move. */
    if(matched_win()) {
        return NULL;
    }

    gen_successors(board, &max_succ, player_id);
    gen_successors(board, &min_succ, opponent_id);

    max_cell = &(max_succ.cells[0]);
    min_cell = &(min_succ.cells[0]);

    D( printf("checking for optimal move... \n"); )

    /* try to choose an optimal move */
    move = optimal_move(
        *max_cell,
        *min_cell,
        player_id,
        opponent_id,
        winner_id
    );

    /* an optimal move was found, take it */
    if(NULL != move) {
        D( printf("optimal move chosen. \n"); )
        return move;

    /* we can only make 1 move so take it. */
    } else if(1 == max_succ.len) {
        D( printf("only move chosen. \n"); )
        return *max_cell;
    }

    /* no immediate optimal move exists, lets try to choose the next
     * best move. The idea we want to express is as follows: if the best move
     * that our opponent can make leaves them better off then what our best
     * move does then we will choose their best move, otherwise our best
     * move. */

    D( printf("searching for next best move... \n"); )

    /* order the moves according to their total importance
     * (weight + player 1 rating + player 2 rating), and then simulate null
     * moves on those cells. */
    num_succ = MIN(max_succ.len, min_succ.len);
    for(; num_succ--; ++max_cell, ++min_cell) {

        max_move = *max_cell;
        min_move = *min_cell;

        /* make our opponents move */
        unrate_pivoted_seqs(min_move, IGNORE_CHIPS);
        min_move->player_id = opponent_id;
        rate_pivoted_seqs(min_move, RATE_CHIPS);

        D( printf("\t looking for opponent best move. \n"); )

        /* find the opponents best follow-up move */
        /*gen_successors(board, &min_move_succ, NO_PLAYER);
        result_move = min_move_succ.cells[0];
        result_best = result_move->rating[0]
                    + result_move->rating[1]
                    + result_move->rating[2];
        if(result_best > best) {
            move = min_move;
            best = result_best;
            D( printf("new best (MIN) score: %d \n", best); )
        }

        D( printf("\t\t opponent move analyzed. \n"); )
        */
        /* undo our opponents move and now make ours */
        unrate_pivoted_seqs(min_move, IGNORE_CHIPS);
        min_move->player_id = NO_PLAYER;

        /* only undo/redo if the cells are not the same */
        if(max_move != min_move) {
            rate_pivoted_seqs(min_move, IGNORE_CHIPS);
            unrate_pivoted_seqs(max_move, IGNORE_CHIPS);
        }

        max_move->player_id = player_id;
        rate_pivoted_seqs(max_move, RATE_CHIPS);

        D( printf("\t looking for AIs best move. \n"); )

        /* find our best follow-up move */
        /*gen_successors(board, &max_move_succ, NO_PLAYER);
        result_move = max_move_succ.cells[0];
        result_best = result_move->rating[0]
                    + result_move->rating[1]
                    + result_move->rating[2];
        if(result_best > best) {
            move = max_move;
            best = result_best;
            D( printf("new best (MAX) score: %d \n", best); )
        }

        D( printf("\t\t AI move analyzed. \n"); )
        */
        /* undo our move */
        unrate_pivoted_seqs(max_move, IGNORE_CHIPS);
        max_move->player_id = NO_PLAYER;
        rate_pivoted_seqs(max_move, IGNORE_CHIPS);
    }

    D( printf("move chosen. \n"); )

    /* take the maximum rated future chip */
    gen_successors(board, &max_succ, NO_PLAYER);

    return max_succ.cells[0];

#if 0
    gen_successors(board, &min_succ, opponent_id);
    num_succ = MIN(MAX_SUCCESSORS_TO_SEARCH, min_succ.len);
    *max_cell = min_succ.cells[0];

    for(; num_succ-- && NULL != *min_cell; ++min_cell) {
        succ = *min_cell;

        /* undo ratings pivoted at move */
        unrate_pivoted_seqs(succ);

        /* rate the sequences pivoted at move */
        succ->player_id = opponent_id;
        rate_pivoted_seqs(succ);
        succ_importance = succ->rating[0] + succ->rating[1] + succ->rating[2];

        /* after placing the enemy chip at this position, we want to get a sense
         * for how much better off they are, not (necessarily) how much better
         * off the cell that we placed out chip at is. */
        gen_successors(board, &max_succ, opponent_id);
        move = max_succ.cells[0];
        succ_importance = move->rating[0] + move->rating[opponent_id];

        /* if the opponent can make a win from their new position then we want
         * to stop them from that. */
        if(succ_importance >= dt_score && succ_importance > max_importance) {
            max_importance = succ_importance;
            *max_cell = succ;
        }

        /* undo the new ratings that were pivoted at move and re-do the
         * old ones */
        unrate_pivoted_seqs(succ);
        succ->player_id = NO_PLAYER;
        rate_pivoted_seqs(succ);
    }
    return *max_cell;
#endif

}
