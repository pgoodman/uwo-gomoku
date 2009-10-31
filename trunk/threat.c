/*
 * threat.c
 *
 *  Created on: Oct 27, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "threat.h"

static int imp_multiplier = 1; /* threat importance multiplier */
static player_t curr_player_id = PLAYER_1;

/**
 * Score the cells within the local space of each cell in some cell sequence.
 * Note: cell importance is independent of the current player because a threat
 *       for one player is a benefit for the other.
 */
static void update_cell_threats(board_cell_t **cells) {
    threat_rating_t threat = 0;
    threat_rating_t benefit = 0;
    threat_rating_t incr_threat = 0;
    threat_rating_t incr_benefit = 0;
    board_cell_t **cell = cells;
    board_cell_t **max = cells + WINNING_SEQ_LENGTH;
    player_t player_id;

    /* empty cell space */
    if(NULL == *cells) {
        return;
    }

    /* go through the local space and determine the threat and benefit scores */
    for(; cell < max; ++cell) {

        player_id = (*cell)->player_id;
        if(player_id == NO_PLAYER) {
            continue;

        } else if(player_id == curr_player_id) {
            benefit += 1;

        } else {
            threat += 1;
        }
    }

    /* calculate the incremental threat and benefit */
    if(!threat) { incr_benefit += imp_multiplier * pow(BENEFIT_BASE, benefit); }
    if(!benefit) { incr_threat += imp_multiplier * pow(THREAT_BASE, threat); }
    /*importance *= imp_multiplier;*/

    /* increment the threat level of all cells in this subsequence of the
     * local threat space. */
    if(threat || benefit) {
        for(cell = cells; cell < max; ++cell) {

            if((*cell)->player_id == NO_PLAYER) {
                (*cell)->threat += incr_threat;
                (*cell)->benefit += incr_benefit;
                /*(*cell)->importance += importance;*/
            }
        }
    }
}

/**
 * Calculate increment the importance values on all cells within the local
 * threat space of the cell positioned at (row, col) in the game board.
 */
static void update_local_space(cell_space_t *cell_space) {
    update_cell_threats(&(cell_space->horizontals[0]));
    update_cell_threats(&(cell_space->verticals[0]));
    update_cell_threats(&(cell_space->left_diags[0]));
    update_cell_threats(&(cell_space->right_diags[0]));
}

/**
 * Recalculate the local threat space around a cell. Note: this assumes that
 * the cell has changed state, i.e. it has gone from empty to having a piece
 * in it.
 */
static void recalculate_local_space(local_space_t *local_space,
                                    board_cell_t *cell) {
    update_local_space(
        &(local_space->cell_space[cell - local_space->first_cell])
    );
}

/**
 * Calculate the threat levels of every cell in the game board for player_id.
 */
void calculate_threats(local_space_t *local_space, const player_t player_id) {
    cell_space_t *space = &(local_space->cell_space[0]);
    const cell_space_t *max = space + BOARD_NUM_CELLS;

    curr_player_id = player_id;
    imp_multiplier = 1;

    for(; space < max; ++space) {
        update_local_space(space);
    }
}

/**
 * Add a position on the board and update the threat scores.
 */
void add_threat(local_space_t *local_space,
                board_cell_t *cell,
                const player_t add_player_id) {

    cell->player_id = add_player_id;
    imp_multiplier = 1;
    recalculate_local_space(local_space, cell);
}

/**
 * Remove a position from the board and update the threat scores.
 */
void remove_threat(local_space_t *local_space,
                   board_cell_t *cell) {
    imp_multiplier = -1;
    recalculate_local_space(local_space, cell);
    cell->player_id = NO_PLAYER;
}
