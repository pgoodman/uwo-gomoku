/*
 * status.c
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "status.h"

/* defines a state machine transition, guarantees a total state machine */
#define PLAYER_CASE(s, s_max_player, s_min_player, s_no_player) \
        {case (s): \
            if(player_id==max_player){return (s_max_player);}\
            else if(player_id==min_player){return (s_min_player);}\
            else {return (s_no_player);}\
            break;}

/* a bit of ugly use of globals, but they are nicely confined and this is
 * not a multi-threaded game :D */
static board_t *game_board;
static player_t max_player;
static player_t min_player;
static int terminal_state_seen = -1;

/**
 * Hand coded state machine to recognize wins or losses.
 */
static int next_state(const int prev_state, const int i, const int j) {
    player_t player_id = game_board->cells[i][j].player_id;

    switch(prev_state) {
        PLAYER_CASE(0, 1, 6, 0)

        /* max player */
        PLAYER_CASE(1, 2, 6, 0)
        PLAYER_CASE(2, 3, 6, 0)
        PLAYER_CASE(3, 4, 6, 0)
        PLAYER_CASE(4, 5, 6, 0)
        PLAYER_CASE(5, 5, 5, 5) /* win */

        /* min player */
        PLAYER_CASE(6, 1, 7, 0)
        PLAYER_CASE(7, 1, 8, 0)
        PLAYER_CASE(8, 1, 9, 0)
        PLAYER_CASE(9, 1, 10, 0)
        PLAYER_CASE(10, 10, 10, 10) /* loss */
    }

    return 0;
}

/**
 * Iterate over sequences of sequences of cells.
 */
static void it_seqs(int i_start,
                    int j_start,
                    const int i_incr,
                    const int j_incr,
                    const int i_start_incr,
                    const int j_start_incr,
                    const int k_max) {
    int i;
    int j;
    int k = 0;
    int state = 0;
    const int len = BOARD_LENGTH;

    /* game has been won or lost */
    if(-1 != terminal_state_seen) {
        return;
    }

    /* iterate over several sequences of cells and activate a state machine */
    do {
        for(i = i_start, j = j_start;
            i >= 0 && i < len && j >= 0 && j < len;
            i += i_incr, j += j_incr, ++k) {

            state = next_state(state, i, j);
        }

        /* final states */
        if(5 == state || 10 == state) {
            terminal_state_seen = state;
            return;
        }

        i_start = MIN(MAX(0, i_start + i_start_incr), len - 1);
        j_start = MIN(MAX(0, j_start + j_start_incr), len - 1);

    } while(k < k_max);
}

static game_status_t status(board_t *board) {
    switch(terminal_state_seen) {
        case -1:
            if(!board->num_empty_cells) {
                return GAME_DRAW;
            } else {
                return GAME_PLAY;
            }
        case 5:
            return GAME_WON;
        case 10:
            return GAME_LOST;
    }

    return GAME_PLAY;
}

/**
 * Figure out the current status of the game after a given move.
 */
game_status_t global_status(board_t *board, const player_t player_id) {

    /* information related to sequencing diagonals */
    const int diag_big_max = (BOARD_NUM_CELLS / 2) - BOARD_LENGTH;
    const int diag_small_max = diag_big_max - 2;
    const int diag_off = (BOARD_LENGTH - WINNING_SEQ_LENGTH);

    /* initialize the global vars */
    terminal_state_seen = -1;
    max_player = player_id;
    min_player = OPPONENT(player_id);
    game_board = board;

    /* horizontals and verticals */
    it_seqs(0, 0, 0, 1, 1, 0, BOARD_NUM_CELLS);
    it_seqs(0, 0, 1, 0, 0, 1, BOARD_NUM_CELLS);

    /* left diagonals */
    it_seqs(0, diag_off, 1, 1, 0, -1, diag_big_max);
    it_seqs(diag_off, 0, 1, 1, -1, 0, diag_small_max);

    /* right diagonals */
    it_seqs(0, WINNING_SEQ_LENGTH + 1, 1, -1, 0, 1, diag_big_max);
    it_seqs(BOARD_LENGTH - 1, diag_off, -1, 1, 0, -1, diag_small_max);

    /* figure out the game status */
    return status(board);
}

