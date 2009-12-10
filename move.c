/*
 * move.c
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "move.h"

#define D(x) x

static const cell_rating_t win_score = IT_STRAIGHT_4;
static const cell_rating_t dt_score = IT_BROKEN_3;

/**
 * See if a learned move exists and if so take the best learned move.
 */
static board_cell_t *get_insightful_move(board_t *board,
                                         ordered_cell_seq_t *successors,
                                         const player_t player_id) {

    board_cell_t *insightful_cell = NULL;
    board_cell_t *cell = NULL;

    int curr_insight;
    int max_insight = 0;
    int i;

    char board_hash[33];

    if(!USE_LEARNED_MOVES) {
        return NULL;
    }

    /* find the learned winning scores, if any, for the board positions */
    D( printf("looking to see if move has been learned... \n"); )

    /* choose the best one. if they all have zero or none are in the db then
     * fall through. */
    for(i = 0; i < successors->len; ++i) {

        cell = successors->cells[i];

        /* hash of the move we *might* make */
        cell->player_id = player_id;
        hash_board(board, &(board_hash[0]));
        cell->player_id = NO_PLAYER;

        if(PLAYER_1 == player_id) {
            curr_insight = player1_score(&(board_hash[0]), 32);
        } else {
            curr_insight = player2_score(&(board_hash[0]), 32);
        }

        /* ignore this board position and kill the successor */
        if(-1 == curr_insight) {
            continue;
        }

        D( printf("insight score %d of %s \n", curr_insight, board_hash); )

        /* this looks like it might be aood choice :D */
        if(curr_insight > max_insight) {
            max_insight = curr_insight;
            insightful_cell = cell;
        }
    }

    if(max_insight > MIN_INSIGHT && NULL != insightful_cell) {
        D( printf("using learned move. \n"); )
        return insightful_cell;
    }

    D( printf("no learned move exists. \n"); )

    return NULL;
}

/**
 * Figure out if we should choose the optimal move, or an insightful optimal
 * move.
 */
static board_cell_t *choose_optimal_or_insightful(board_cell_t *optimal_move,
                                                  board_cell_t *insightful_move,
                                                  const cell_rating_t bound,
                                                  const player_t player_id) {
    if(NULL == insightful_move) {
        return optimal_move;
    } else if(insightful_move->rating[player_id] >= bound) {
        return insightful_move;
    }
    return optimal_move;
}

/**
 * Can we choose an optimal move, given the generated successors?
 */
static board_cell_t *match_optimal_move(board_t *board,
                                        ordered_cell_seq_t *max_succ,
                                        ordered_cell_seq_t *min_succ,
                                        const player_t player_id,
                                        const player_t opponent_id) {

    board_cell_t *max_cell = max_succ->cells[0];
    board_cell_t *min_cell = min_succ->cells[0];

    const cell_rating_t max_rating = max_cell->rating[player_id];
    const cell_rating_t min_rating = min_cell->rating[opponent_id];

    /* can we make a winning move immediately? */
    if(max_rating >= win_score) {
        return max_cell;

    /* can we block a win? */
    } else if(min_rating >= win_score) {
        printf("forced move. \n");
        return min_cell;

    /* can we make a double threat? */
    } else if(max_rating >= dt_score) {
        return choose_optimal_or_insightful(
            max_cell,
            get_insightful_move(board, max_succ, player_id),
            dt_score,
            player_id
        );

    /* can we block a double threat? */
    } else if(min_rating >= dt_score) {
        printf("forced move. \n");
        return choose_optimal_or_insightful(
            min_cell,
            get_insightful_move(board, min_succ, player_id),
            win_score,
            opponent_id
        );

    }

    return NULL;
}

/**
 * Perform a depth-first search that calculates the incremental future chip
 * rating for each cell for each type of chip.
 */
static void search_successors(board_t *board,
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
            search_successors(
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
            search_successors(
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
static ordered_cell_seq_t *rate_successors(board_t *board,
                                           ordered_cell_seq_t *successors,
                                           const player_t player_id,
                                           const player_t opponent_id) {
    gen_successors(board, successors, NO_PLAYER);
    search_successors(
        board,
        &(successors->cells[0]),
        player_id,
        opponent_id,
        PATTERN_SEARCH_DEPTH
    );
    gen_successors(board, successors, NO_PLAYER);

    return successors;
}

/**
 * Choose one of the top-rated successors. We've search and rated the moves
 * and now we have a sequence of successors ordered by their ratings. It might
 * be the case, however, that the top rated one is not the one we really want
 * to choose. This can happen for a number of reasons, but we will more
 * generally refer to the problem as disturbance by noise (i.e. signal vs.
 * noise). Thus, we want to look at the best few and then evaluate them in a
 * different way.
 */
static board_cell_t *choose_succesor(board_t *board,
                                     ordered_cell_seq_t *successors,
                                     const player_t player_id) {

    const cell_rating_t max_score = successors->cells[0]->chip_rating;
    const cell_rating_t min_rand_score = max_score - IT_STRAIGHT_4;
    cell_rating_t chip_rating;
    board_cell_t *move = get_insightful_move(board, successors, player_id);

    int rand_val;
    int i = 0;
    int rand_choice = 1;

    if(NULL != move) {
        return move;
    }

    srand((unsigned int) time(NULL));
    rand_val = rand();

    /* look at the successors and count how many are within range of a random
     * choice and how many are within range of using out insight scores. */
    if(USE_RANDOM_MOVES) {
        if(max_score > (4 * IT_STRAIGHT_4)) {
            for(i = 0; i < successors->len; ++i) {
                if((successors->cells[i])->chip_rating >= min_rand_score) {
                    ++rand_choice;
                    continue;
                }
                break;
            }
            ++i;
        }
    }

    D( printf("making random choice from %d nodes. \n", rand_choice - 1); )

    return successors->cells[rand_val % rand_choice];
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

    if(1 == max_succ.len) {
        D( printf("only move chosen. \n"); )
        optimal_move = max_succ.cells[0];
    }

    D( printf("checking for optimal move... \n"); )

    /* try to choose an optimal move, this can be a forced move a lot of
     * the time. */
    optimal_move = match_optimal_move(
        board,
        &max_succ,
        &min_succ,
        player_id,
        opponent_id
    );

    if(NULL != optimal_move) {
        return optimal_move;
    }

    D( printf("searching for next best move... \n"); )

    clear_ratings(board);
    bound_successors(board);

    srand((unsigned int) time(NULL));

    /* find the next best move */
    optimal_move = choose_succesor(board, rate_successors(
        board,
        &max_succ,
        player_id,
        opponent_id
    ), player_id);

    clear_ratings(board);
    clear_matches();

    /* return the best rated cell */
    return optimal_move;
}
