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
 */
static void update_cell_threats(board_t *board,
                                const player_t player_id,
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

        /* our own chip */
        } else if(cell->player_id == player_id) {
            benefit += 1;

        /* opponent */
        } else {
            threat += 1;
        }
    }

    /* calculate threat value */
    if(!threat) { importance += pow(BENEFIT_BASE, benefit); }
    if(!benefit) { importance += pow(THREAT_BASE, threat); }
    importance *= imp_multiplier;

    /* increment the threat level of all cells in the local space */
    if(threat || benefit) {
        for(i = i_start, j = j_start;
            i >= i_min && i <= i_max && j >= j_min && j <= j_max;
            i += i_incr, j += j_incr) {

            cell = &(board->cells[i][j]);
            if(cell->player_id == NO_PLAYER) {
                cell->threat_rating += importance;
            }
        }
    }
}

/**
 * Calculate the threat levels for each threat space anchored at a cell.
 */
static void update_local_space(board_t *board,
                               const player_t player_id,
                               const int row,
                               const int col,
                               const int imp_multiplier) {

    update_cell_threats(board, player_id, row, col, 0, 1, imp_multiplier);
    update_cell_threats(board, player_id, row, col, 1, 0, imp_multiplier);
    update_cell_threats(board, player_id, row, col, 1, 1, imp_multiplier);
    update_cell_threats(board, player_id, row, col, 1, -1, imp_multiplier);
}

/**
 * Calculate the threat levels of every cell in the game board for player_id.
 */
void calculate_threats(board_t *board, const player_t player_id) {
    int i = 0;
    int j = 0;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            update_local_space(board, player_id, i, j, 1);
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
                                    const player_t player_id,
                                    const int imp_multiplier) {

    const board_cell_t *cells = &(board->cells[0][0]);
    const int col = (int) ((cell - cells) % BOARD_LENGTH);
    const int row = (int) ((cell - cells) - col) / BOARD_LENGTH;
#if 0
    const int i_max = MIN(BOARD_LENGTH - 1, row + LOCAL_SPACE);
    const int j_max = MIN(BOARD_LENGTH - 1, col + LOCAL_SPACE);
    const int i_min = MAX(0, row - LOCAL_SPACE);
    const int j_min = MAX(0, col - LOCAL_SPACE);
    threat_cell_patch_t *cell_patch = &(patch->changes[0]);

    int i;
    int j;

    /* make the threat patch */
    for(i = i_min; i <= i_max ; ++i) {
        for(j = j_min; j <= j_max; ++j, ++cell_patch) {
            cell = &(board->cells[i][j]);
            cell_patch->cell = cell;
            cell_patch->threat_rating = cell->threat_rating;
        }
    }

    /* add trailing null */
    cell_patch->cell = NULL;
#endif
    /* update the threat scores of each threat space that contains the cell */
    update_local_space(board, player_id, row, col, imp_multiplier);
}

/**
 * Add a position on the board and update the threat scores.
 */
void add_threat(board_t *board,
                board_cell_t *cell,
                const player_t player_id,
                const player_t add_player_id) {

    cell->player_id = add_player_id;
    recalculate_local_space(board, cell, player_id, 1);
}

/**
 * Remove a position from the board and update the threat scores.
 */
#if 0
void remove_threat(threat_space_patch_t *patch) {
    threat_cell_patch_t *cell_patch = &(patch->changes[0]);
    while(NULL != cell_patch->cell) {
        cell_patch->cell->threat_rating = cell_patch->threat_rating;
        ++cell_patch;
    }
    patch->cell->player_id = NO_PLAYER;
}
#endif
void remove_threat(board_t *board,
                   board_cell_t *cell,
                   const player_t player_id) {
    recalculate_local_space(board, cell, player_id, -1);
    cell->player_id = NO_PLAYER;
}
