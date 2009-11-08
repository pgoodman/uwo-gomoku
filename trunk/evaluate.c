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

static int num_fours_player_1 = 0;
static int num_fours_player_2 = 0;

static int num_threes_player_1 = 0;
static int num_threes_player_2 = 0;

/* keep track of winning cells */
static board_cell_t *winning_empty_cell_1 = NULL;
static board_cell_t *winning_empty_cell_2 = NULL;

/* keep track of blocking cells */
static board_cell_t *blocking_empty_cell_1 = NULL;
static board_cell_t *blocking_empty_cell_2 = NULL;

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
            ++num_fours_player_1;
            if(NULL == winning_empty_cell_1) {
                winning_empty_cell_1 = last_empty_cell;
            }
        } else if(num_in_line <= -4
               && (num_in_line + num_since_start) <= 2) {
            ++num_fours_player_2;
            if(NULL == winning_empty_cell_2) {
                winning_empty_cell_2 = last_empty_cell;
            }
        }
    }

    /* yield a match of three nearby cells in a row */
    if(num_since_start > 4 && num_consecutive_empty == 1) {
        if(num_in_line == 3) {
            ++num_threes_player_1;
            if(NULL == blocking_empty_cell_1) {
                blocking_empty_cell_1 = last_empty_cell;
            }
        } else if(num_in_line == -3) {
            ++num_threes_player_2;
            if(NULL == blocking_empty_cell_2) {
                blocking_empty_cell_2 = last_empty_cell;
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
    num_fours_player_1 = 0;
    num_fours_player_2 = 0;
    num_threes_player_1 = 0;
    num_threes_player_2 = 0;
    winning_empty_cell_1 = NULL;
    winning_empty_cell_2 = NULL;

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

    /* score the current game board in terms of threats and double threats */
    if(PLAYER_1 == max_player_id) {
        if(num_fours_player_1 >= 2) { /* we have created a double threat */
            ++(*num_wins);
            return INT_MAX;
        } else if(num_fours_player_2 >= 2) { /* opponent has created a d.t. */
            ++(*num_losses);
            return INT_MIN;
        } else {
            return (int) (
                (pow(5, num_fours_player_1) -
                pow(5, num_fours_player_2)) +
                pow(3, num_threes_player_1)
            );
        }
    } else if(PLAYER_2 == max_player_id) {
        if(num_fours_player_2 >= 2) { /* we have created a d.t. */
            ++(*num_wins);
            return INT_MAX;
        } else if(num_fours_player_1 >= 2) { /* opponent created a d.t. */
            ++(*num_losses);
            return INT_MAX;
        } else {
            return (int) (
                (pow(5, num_fours_player_2) -
                 pow(5, num_fours_player_1)) +
                 pow(3, num_threes_player_2)
            );
        }
    }

    return 0;
}

/**
 * Yield a best move if there is one for the current player. Note: this *must*
 * be called after minimax_evaluate(). If no best move exists then NULL is set
 * as the value of the cell pointer pointed to.
 */
void yield_best_move(board_cell_t **cell, const player_t player_id) {

    *cell = NULL;

    /* player 1's best move */
    if(PLAYER_1 == player_id) {
        if(NULL != winning_empty_cell_1) { /* take win */
            *cell = winning_empty_cell_1;
        } else if(NULL != winning_empty_cell_2) { /* defend loss */
            *cell = winning_empty_cell_2;
        } else if(NULL != blocking_empty_cell_1) { /* make double threat */
            *cell = blocking_empty_cell_1;
        } else if(NULL != blocking_empty_cell_2) { /* block soon-to-be D.T. */
            *cell = blocking_empty_cell_2;
        }

    /* player 2's best move */
    } else if(PLAYER_2 == player_id) {

        if(NULL != winning_empty_cell_2) { /* take win */
            *cell = winning_empty_cell_2;
        } else if(NULL != winning_empty_cell_1) { /* defend loss */
            *cell = winning_empty_cell_1;
        } else if(NULL != blocking_empty_cell_2) { /* make double threat */
            *cell = blocking_empty_cell_2;
        } else if(NULL != blocking_empty_cell_1) { /* block soon-to-be D.T. */
            *cell = blocking_empty_cell_1;
        }
    }
}
