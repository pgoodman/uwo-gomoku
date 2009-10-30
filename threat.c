/*
 * threat.c
 *
 *  Created on: Oct 27, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "threat.h"

/**
 * Score the cells within the local space of each cell in some cell sequence.
 * Note: cell importance is independent of the current player because a threat
 *       for one player is a benefit for the other.
 */
static void update_cell_threats(board_t *board,
                                const int i_init,
                                const int j_init,
                                const int i_incr,
                                const int j_incr,
                                const int imp_multiplier) {
    threat_rating_t threat = 0;
    threat_rating_t benefit = 0;
    threat_rating_t importance = 0;
    board_cell_t *cell;

    int i;
    int j;

    const int N = LOCAL_SPACE;
    const int i_start = i_init - (i_incr * N);
    const int j_start = j_init - (j_incr * N);
    const int i_min = MIN(i_start, i_init + (i_incr * N));
    const int i_max = MAX(i_init - (i_incr * N), i_init + (i_incr * N));
    const int j_min = MIN(j_start, j_init + (j_incr * N));
    const int j_max = MAX(j_init - (j_incr * N), j_init + (j_incr * N));

    /* ignore a cell that meets these conditions */
    if(i_min < 0 || i_max >= BOARD_LENGTH
    || j_min < 0 || j_max >= BOARD_LENGTH) {
        return;
    }

    /* go through the local space and determine the threat and benefit scores */
    for(i = i_start, j = j_start;
        i >= i_min && i <= i_max && j >= j_min && j <= j_max;
        i += i_incr, j += j_incr) {

        cell = &(board->cells[i][j]);
        if(cell->player_id == NO_PLAYER) {
            continue;

        } else if(cell->player_id == PLAYER_1) {
            benefit += 1;

        } else {
            threat += 1;
        }
    }

    /* calculate the incremental threat and benefit */
    if(!threat) { importance += pow(BENEFIT_BASE, benefit); }
    if(!benefit) { importance += imp_multiplier * pow(THREAT_BASE, threat); }
    importance *= imp_multiplier;

    /* increment the threat level of all cells in this subsequence of the
     * local threat space. */
    if(threat || benefit) {
        for(i = i_start, j = j_start;
            i >= i_min && i <= i_max && j >= j_min && j <= j_max;
            i += i_incr, j += j_incr) {

            cell = &(board->cells[i][j]);
            if(cell->player_id == NO_PLAYER) {
                cell->importance += importance;
            }
        }
    }
}

/**
 * Calculate increment the importance values on all cells within the local
 * threat space of the cell positioned at (row, col) in the game board.
 */
static void update_local_space(board_t *board,
                               const int row,
                               const int col,
                               const int imp_multiplier) {
    update_cell_threats(board, row, col, 0, 1, imp_multiplier);
    update_cell_threats(board, row, col, 1, 0, imp_multiplier);
    update_cell_threats(board, row, col, 1, 1, imp_multiplier);
    update_cell_threats(board, row, col, 1, -1, imp_multiplier);
}

/**
 * Calculate the threat levels of every cell in the game board for player_id.
 */
void calculate_threats(board_t *board) {
    int i = 0;
    int j = 0;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            update_local_space(board, i, j, 1);
        }
    }
}

/**
 * Recalculate the local threat space around a cell. Note: this assumes that
 * the cell has changed state, i.e. it has gone from empty to having a piece
 * in it.
 */
static void recalculate_local_space(board_t *board,
                                    board_cell_t *cell,
                                    const int imp_multiplier) {

    const board_cell_t *cells = &(board->cells[0][0]);
    const int col = (int) ((cell - cells) % BOARD_LENGTH);
    const int row = (int) ((cell - cells) - col) / BOARD_LENGTH;

    /* update the threat scores of each threat space that contains the cell */
    update_local_space(board, row, col, imp_multiplier);
}

/**
 * Add a position on the board and update the threat scores.
 */
void add_threat(board_t *board,
                board_cell_t *cell,
                const player_t add_player_id) {

    cell->player_id = add_player_id;
    recalculate_local_space(board, cell, 1);
}

/**
 * Remove a position from the board and update the threat scores.
 */
void remove_threat(board_t *board,
                   board_cell_t *cell) {
    recalculate_local_space(board, cell, -1);
    cell->player_id = NO_PLAYER;
}
