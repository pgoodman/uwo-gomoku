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

            /* yield a match of four nearby cells in a row */
            if(num_since_start >= 5) {
                if(num_in_line >= 4) {
                    ++num_fours_player_1;
                } else if(num_in_line <= -4) {
                    ++num_fours_player_2;
                }

            /* yield a match of three nearby cells in a row */
            } else if(num_since_start >= 4) {
                if(num_in_line >= 3) {
                    ++num_threes_player_1;
                } else if(num_in_line <= -3) {
                    ++num_threes_player_2;
                }
            }

            if(cell->player_id == NO_PLAYER) {
                ++num_since_start;
                ++num_consecutive_empty;

                if(num_consecutive_empty > 1) {
                    num_in_line = 0;
                    num_since_start = 1;
                } else if(num_since_start >= 6 && num_in_line < 4) {
                    num_since_start = 1;
                }

            /* current player chip, will either continue a line or break one */
            } else if(cell->player_id == PLAYER_1) {
                num_consecutive_empty = 0;

                if(num_in_line < 0) {
                    num_in_line = 1;
                    num_since_start = 1;
                } else {
                    ++num_in_line;
                    ++num_since_start;
                }

            /* opponent chip, will either continue a line or break one */
            } else {
                num_consecutive_empty = 0;

                if(num_in_line > 0) {
                    num_in_line = -1;
                    num_since_start = 1;
                } else {
                    --num_in_line;
                    ++num_since_start;
                }
            }
        }

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
                    const player_t winner_id) {

    /* information related to sequencing diagonals */
    const int diag_big_max = (BOARD_NUM_CELLS / 2) - BOARD_LENGTH;
    const int diag_small_max = diag_big_max - 2;
    const int diag_off = (BOARD_LENGTH - WINNING_SEQ_LENGTH);

    /* there was a winner, return the score */
    if(NO_PLAYER != winner_id) {
        return (max_player_id == winner_id) ? INT_MAX : INT_MIN;
    }

    /* initialize the global vars */
    game_board = board;
    num_fours_player_1 = 0;
    num_fours_player_2 = 0;
    num_threes_player_1 = 0;
    num_threes_player_2 = 0;

    /* find all the winning threats on the game board */
    eval_seqs(0, 0, 0, 1, 1, 0, BOARD_NUM_CELLS); /* - */
    eval_seqs(0, 0, 1, 0, 0, 1, BOARD_NUM_CELLS); /* | */
    eval_seqs(0, diag_off, 1, 1, 0, -1, diag_big_max); /* \ */
    eval_seqs(diag_off, 0, 1, 1, -1, 0, diag_small_max); /* \ */
    eval_seqs(0, WINNING_SEQ_LENGTH + 1, 1, -1, 0, 1, diag_big_max); /* / */
    eval_seqs(BOARD_LENGTH - 1, diag_off, -1, 1, 0, -1, diag_small_max); /* / */

    /* score the current game board in terms of threats and double threats */
    if(PLAYER_1 == max_player_id) {
        if(num_fours_player_1 >= 2) {
            return INT_MAX;
        } else if(num_fours_player_2 >= 2) {
            return INT_MIN;
        } else {
            return (int) (
                (pow(5, num_fours_player_1) -
                pow(5, num_fours_player_2)) +
                pow(3, num_threes_player_1)
            );
        }
    } else {
        if(num_fours_player_2 >= 2) {
            return INT_MAX;
        } else if(num_fours_player_1 >= 2) {
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
