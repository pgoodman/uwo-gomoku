/*
 * winner.h
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "winner.h"

/* a bit of ugly use of globals, but they are nicely confined and this is
 * not a multi-threaded game :D */
static board_t *game_board;

/**
 * Iterate over sequences of sequences of cells.
 */
static int it_seqs(int i_start,
                    int j_start,
                    const int i_incr,
                    const int j_incr,
                    const int i_start_incr,
                    const int j_start_incr,
                    const int k_max) {
    int i;
    int j;
    int k = 0;
    int num_in_line = 0;
    const int len = BOARD_LENGTH;
    board_cell_t *cell;

    /* iterate over several sequences of cells and activate a state machine */
    do {
        num_in_line = 0;

        for(i = i_start, j = j_start;
            i >= 0 && i < len && j >= 0 && j < len;
            i += i_incr, j += j_incr, ++k) {

            /* simpler implementation of an 11 state DFA that matches five
             * cells in a row of either max_player or min_player. */
            cell = &(game_board->cells[i][j]);
            if(cell->player_id == NO_PLAYER) {
                num_in_line = 0;

            /* current player chip, will either continue a line or break one */
            } else if(cell->player_id == PLAYER_1) {
                if(num_in_line >= 0) {
                    ++num_in_line;
                } else {
                    num_in_line = 1;
                }

            /* opponent chip, will either continue a line or break one */
            } else {
                if(num_in_line <= 0) {
                    --num_in_line;
                } else {
                    num_in_line = -1;
                }
            }

            /* matched a win or loss */
            if(5 == num_in_line || -5 == num_in_line) {
                return num_in_line;
            }
        }

        i_start = MIN(MAX(0, i_start + i_start_incr), len - 1);
        j_start = MIN(MAX(0, j_start + j_start_incr), len - 1);

    } while(k < k_max);

    return 0;
}

/**
 * Figure out the current status of the game after a move has been made. This
 * goes over all board positions in every direction until it finds a sequence
 * of WINNING_SEQ_LENGTH chips by either player.
 */
player_t global_winner(board_t *board) {

    /* information related to sequencing diagonals */
    const int diag_big_max = (BOARD_NUM_CELLS / 2) - BOARD_LENGTH;
    const int diag_small_max = diag_big_max - 2;
    const int diag_off = (BOARD_LENGTH - WINNING_SEQ_LENGTH);
    int status;

    /* initialize the global vars */
    game_board = board;

    /* figure out the game status */
    status = (
        it_seqs(0, 0, 0, 1, 1, 0, BOARD_NUM_CELLS) || /* h */
        it_seqs(0, 0, 1, 0, 0, 1, BOARD_NUM_CELLS) || /* v */
        it_seqs(0, diag_off, 1, 1, 0, -1, diag_big_max) || /* ld */
        it_seqs(diag_off, 0, 1, 1, -1, 0, diag_small_max) || /* ld */
        it_seqs(0, WINNING_SEQ_LENGTH + 1, 1, -1, 0, 1, diag_big_max) || /* rd */
        it_seqs(BOARD_LENGTH - 1, diag_off, -1, 1, 0, -1, diag_small_max) /* rd */
    );

    if(status < 0) { return PLAYER_2; }
    if(status > 0) { return PLAYER_1; }
    return NO_PLAYER;
}

/**
 * Returns 1 if a player won in the cellspace and sets *winner_id to the player
 * id; returns 0 otherwise.
 */
static int cell_space_winner(cell_space_t *cell_space, player_t *winner_id) {

    board_cell_t **cells = &(cell_space->horizontals[0]);
    board_cell_t **max;

    int num_player_1;
    int num_player_2;
    int i = 5;

    while(--i) {

        /* what cell space should we look at? */
        switch(i) {
            case 3: cells = &(cell_space->verticals[0]); break;
            case 2: cells = &(cell_space->left_diags[0]); break;
            case 1: cells = &(cell_space->right_diags[0]); break;
        }

        /* look over the cells in this cell space */
        if((*cells) != NULL) {

            num_player_1 = 0;
            num_player_2 = 0;
            max = cells + WINNING_SEQ_LENGTH;

            /* count how many of each chip type in this vector */
            for(; cells < max; ++cells) {
                if(NO_PLAYER == (*cells)->player_id) {
                    continue;
                } else if(PLAYER_1 == (*cells)->player_id) {
                    ++num_player_1;
                } else {
                    ++num_player_2;
                }
            }

            /* was their five in a row of either player? */
            if(5 == num_player_1) { *winner_id = PLAYER_1; return 1; }
            if(5 == num_player_2) { *winner_id = PLAYER_2; return 1; }
        }
    }

    /* no player won in this turn */
    return 0;
}

/**
 * Returns the player id of the player that won in the current local space, or
 * NO_PLAYER if no player won in the current local space.
 */
player_t local_winner(local_space_t *local_space, const board_cell_t *cell) {

    player_t winner_id = NO_PLAYER;
    board_cell_t *cells = local_space->first_cell;
    const int col = (int) ((cell - cells) % BOARD_LENGTH);
    const int row = (int) ((cell - cells) - col) / BOARD_LENGTH;
    const int i_max = MIN(BOARD_LENGTH - 1, row + LOCAL_SPACE);
    const int j_max = MIN(BOARD_LENGTH - 1, col + LOCAL_SPACE);
    const int i_min = MAX(0, row - LOCAL_SPACE);
    const int j_min = MAX(0, col - LOCAL_SPACE);
    int i;
    int j;
    int someone_won;

    for(i = i_min; i <= i_max; ++i) {
        for(j = j_min; j <= j_max; ++j) {

            someone_won = cell_space_winner(&(local_space->cell_space[
                (i * BOARD_LENGTH) + j
            ]), &winner_id);

            if(someone_won) {
                goto done;
            }
        }
    }

    done:
    return winner_id;
}

