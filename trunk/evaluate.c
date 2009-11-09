/*
 * evaluate.c
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "evaluate.h"

/* a bit of ugly use of globals, but they are nicely confined and this is
 * not a multi-threaded game :D */
static board_t *game_board;

static int num_fours_player[2] = {0, 0};
static int num_threes_player[2] = {0, 0};

/* keep track of winning cells */
static board_cell_t *winning_empty_cell[2] = {NULL, NULL};

/* keep track of blocking cells */
static board_cell_t *blocking_empty_cell[2] = {NULL, NULL};

/**
 * Recognize either a 4-threat or a 3-threat. That is, all 5-tuples with 4 chips
 * and 1 empty cell, or all 5 or 6-tuples with 3 chips and at least 2 empties.
 */
static void eval_threat(const int num_since_start,
                        const int num_in_line,
                        const int num_consecutive_empty,
                        board_cell_t *last_empty_cell) {

    /* yield a match of four nearby cells in a row */
    if(num_since_start >= 5 && (num_since_start - num_in_line) > 0) {
        if(num_in_line >= 4 && num_in_line >= (num_since_start - 2)) {
            ++num_fours_player[0];
            if(NULL == winning_empty_cell[0]) {
                winning_empty_cell[0] = last_empty_cell;
            }
        } else if(num_in_line <= -4
               && (num_in_line + num_since_start) <= 2) {
            ++num_fours_player[1];
            if(NULL == winning_empty_cell[1]) {
                winning_empty_cell[1] = last_empty_cell;
            }
        }
    }

    /* yield a match of three nearby cells in a row */
    if(num_since_start > 4 && num_consecutive_empty == 1) {
        if(num_in_line == 3) {
            ++num_threes_player[0];
            if(NULL == blocking_empty_cell[0]) {
                blocking_empty_cell[0] = last_empty_cell;
            }
        } else if(num_in_line == -3) {
            ++num_threes_player[1];
            if(NULL == blocking_empty_cell[1]) {
                blocking_empty_cell[1] = last_empty_cell;
            }
        }
    }
}

/**
 * Iterate over sequences of sequences of cells and incrementally perform
 * multiple pattern matching on the cells in linear time and constant space.
 */
static void eval_seqs(int i_start,
                      int j_start,
                      const int i_incr,
                      const int j_incr,
                      const int i_start_incr,
                      const int j_start_incr,
                      const int k_max) {
    int i;
    int j;
    int k = 0;
    const int len = BOARD_LENGTH;
    board_cell_t *cell;
    board_cell_t *last_empty_cell = NULL;

    int num_since_start = 0; /* number of same-color chips+empties in the seq */
    int num_in_line = 0; /* number of same-color chips in the sequence */
    int num_consecutive_empty = 0; /* number of consecutive empty cells */

    /* iterate over several sequences of cells and activate a state machine */
    do {
        num_since_start = 0;
        num_in_line = 0;
        num_consecutive_empty = 0;

        for(i = i_start, j = j_start;
            i >= 0 && i < len && j >= 0 && j < len;
            i += i_incr, j += j_incr, ++k) {

            cell = &(game_board->cells[i][j]);

            eval_threat(
                num_since_start,
                num_in_line,
                num_consecutive_empty,
                last_empty_cell
            );

            if(cell->player_id == NO_PLAYER) {
                ++num_since_start;
                ++num_consecutive_empty;

                last_empty_cell = cell;

                if(num_consecutive_empty > 1) {
                    num_in_line = 0;
                    num_since_start = 1;
                } else if(num_since_start > 6 && num_in_line < 4) {
                    num_since_start = 1;
                }

            /* current player chip, will either continue a line or break one */
            } else if(cell->player_id == PLAYER_1) {
                if(num_in_line < 0) {
                    num_in_line = 1;
                    num_since_start = num_consecutive_empty > 0 ? 2 : 1;
                } else {
                    ++num_in_line;
                    ++num_since_start;
                }

                num_consecutive_empty = 0;

            /* opponent chip, will either continue a line or break one */
            } else {
                if(num_in_line > 0) {
                    num_in_line = -1;
                    num_since_start = num_consecutive_empty > 0 ? 2 : 1;
                } else {
                    --num_in_line;
                    ++num_since_start;
                }

                num_consecutive_empty = 0;
            }
        }

        eval_threat(
            num_since_start,
            num_in_line,
            num_consecutive_empty,
            last_empty_cell
        );

        i_start = MIN(MAX(0, i_start + i_start_incr), len - 1);
        j_start = MIN(MAX(0, j_start + j_start_incr), len - 1);

    } while(k < k_max);
}

/**
 * Min/max evaluation function.
 */
int minmax_evaluate(board_t *board,
                    const player_t max_player_id,
                    const player_t curr_player_id,
                    const player_t winner_id,
                    int *num_wins,
                    int *num_losses) {

    /* information related to sequencing diagonals */
    const int diag_big_max = (BOARD_NUM_CELLS / 2) - BOARD_LENGTH;
    const int diag_small_max = diag_big_max - 2;
    const int diag_off = (BOARD_LENGTH - WINNING_SEQ_LENGTH);
    const int p = !(PLAYER_1 != max_player_id);

    /* there was a winner, return the score */
    if(NO_PLAYER != winner_id) {
        if(max_player_id == winner_id) {
            ++(*num_wins);
            return INT_MAX;
        } else {
            ++(*num_losses);
            return INT_MIN;
        }
    }

    /* initialize the global vars */
    game_board = board;
    num_fours_player[0] = 0;
    num_fours_player[1] = 0;
    num_threes_player[0] = 0;
    num_threes_player[1] = 0;
    winning_empty_cell[0] = NULL;
    winning_empty_cell[1] = NULL;

    /* find all the winning threats on the game board. given the design of
     * eval_seqs, when iterating over diagonal sequences, this can only do half
     * of the board (exercise of the reader to figure out why) and so each
     * needs to be called twice, one for the big half, the other for the small
     * half. It should be noted that all can be done in one fell swoop if we
     * consider thinking about which diagonal we are currently on, and said code
     * exists in an earlier revision of the AI, but it wasn't as sexy as the
     * above code and made it difficult to do what I need to do. */
    eval_seqs(0, 0, 0, 1, 1, 0, BOARD_NUM_CELLS); /* - */
    eval_seqs(0, 0, 1, 0, 0, 1, BOARD_NUM_CELLS); /* | */
    eval_seqs(0, diag_off, 1, 1, 0, -1, diag_big_max); /* \ */
    eval_seqs(diag_off, 0, 1, 1, -1, 0, diag_small_max); /* \ */
    eval_seqs(0, WINNING_SEQ_LENGTH + 1, 1, -1, 0, 1, diag_big_max); /* / */
    eval_seqs(BOARD_LENGTH - 1, diag_off, -1, 1, 0, -1, diag_small_max); /* / */

    if(num_fours_player[p] >= 2) { /* we have created a double threat */
        ++(*num_wins);
        return INT_MAX;
    } else if(num_fours_player[p] >= 2) { /* opponent has created a d.t. */
        ++(*num_losses);
        return INT_MIN;
    } else {
        return (int) (
            pow(3, num_threes_player[p]) + pow(4, num_fours_player[p])
        );
    }

    return 0;
}

/**
 * Yield a best move if there is one for the current player. This will look to
 * see if we can immediately win, block an immediate win, block the construction
 * of a double threat, or block the construction of a double threat created by
 * the intersection of two double threats.
 */
board_cell_t *yield_best_move(board_t *board, const player_t player_id) {

    int foobar = 0;
    board_cell_t *cell = NULL;
    board_cell_t *max_cell = &(board->cells[BOARD_LENGTH - 1][BOARD_LENGTH - 1]);
    const int p = !(PLAYER_1 == player_id);
    const int op = 1 - p;
    const player_t opponent_id = OPPONENT(player_id);

    board_cell_t *best_cell = NULL;
    int best_cell_importance = INT_MIN;
    int importance;

    minmax_evaluate(
        board,
        player_id,
        player_id,
        NO_PLAYER,
        &foobar,
        &foobar
    );

    if(NULL != winning_empty_cell[p]) { /* take win */
        return winning_empty_cell[p];
    } else if(NULL != winning_empty_cell[op]) { /* defend loss */
        return winning_empty_cell[op];
    } else if(NULL != blocking_empty_cell[p]) { /* make double threat */
        return blocking_empty_cell[p];
    } else if(NULL != blocking_empty_cell[op]) { /* block soon-to-be D.T. */
        return blocking_empty_cell[op];
    }

    /* we haven't seen an immediate best move, so lets look to see if any of
     * the total possible successors will create a double threat construction.
     * Note: they won't win because otherwise we would have seen that!
     */
    for(cell = &(board->cells[0][0]); cell <= max_cell; ++cell) {
        if(NO_PLAYER != cell->player_id) {
            continue;
        }

        cell->player_id = opponent_id;

        /* evaluate the cell as if the opponent placed their chip there */
        minmax_evaluate(
            board,
            player_id,
            opponent_id,
            NO_PLAYER,
            &foobar,
            &foobar
        );

        /* undo the chip placement */
        cell->player_id = NO_PLAYER;

        /* look to see if the opponent can construct a double threat or win
         * from this sequence. */
        if(num_threes_player[op] || num_fours_player[op]) {
            importance = (int) (
                pow(3, num_threes_player[op]) + pow(4, num_fours_player[op])
            );
            if(importance > best_cell_importance) {
                best_cell_importance = importance;
                best_cell = cell;
            }
        }
    }

    return best_cell;
}
