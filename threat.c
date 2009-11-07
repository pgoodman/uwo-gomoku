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
static void update_cell_threats(board_cell_t **cells,
                                const player_t player_id) {
    threat_rating_t threat = 0;
    threat_rating_t benefit = 0;
    threat_rating_t middle_threat = 0;
    threat_rating_t incr_threat = 0;
    threat_rating_t incr_benefit = 0;
    threat_rating_t incr_weight = 0;
    board_cell_t **cell = cells;
    board_cell_t **max = cells + WINNING_SEQ_LENGTH;
    player_t cell_player_id;

    /* empty cell space */
    if(NULL == *cells) {
        return;
    }

    /* go through the local space and determine the threat and benefit scores */
    for(; cell < max; ++cell) {

        cell_player_id = (*cell)->player_id;

        if(cell_player_id == NO_PLAYER) {
            continue;
        }

        if(cell_player_id == player_id) {
            benefit += 1;
        } else {
            if(cell > cells && cell < (max - 1)) {
                middle_threat += 1;
            } else {
                threat += 1;
            }
        }
    }

    threat += middle_threat;

    if(threat && benefit) {
        threat = benefit = 0;

    } else if(threat || benefit) {

        incr_weight = 0;

        /* make winning moves most important */
        if((WINNING_SEQ_LENGTH - 1) == benefit && !threat) {
            benefit = WINNING_SEQ_LENGTH + 1;

        /* make blocking losses important */
        } else if((WINNING_SEQ_LENGTH - 1)  == threat && !benefit) {
            ++threat;

        /* three opponent chips with no barriers on either side. */
        } else if((WINNING_SEQ_LENGTH - 2) == middle_threat && !benefit) {
            incr_weight = 2;
        }
    } else {
        incr_weight = 1;
    }

    if(benefit) { incr_benefit = pow(BENEFIT_BASE, benefit); }
    if(threat) { incr_threat = pow(THREAT_BASE, threat); }

    /* increment the threat level of all cells in this subsequence of the
     * local threat space. */
    if(threat || benefit) {
        for(cell = cells; cell < max; ++cell) {
            if((*cell)->player_id == NO_PLAYER) {

                (*cell)->threat += incr_threat;
                (*cell)->benefit += incr_benefit;
                (*cell)->weight += incr_weight;
            }
        }
    }
}

/**
 * Calculate increment the importance values on all cells within the local
 * threat space of the cell positioned at (row, col) in the game board.
 */
static void update_local_space(cell_space_t *cell_space,
                               const player_t player_id) {
    update_cell_threats(&(cell_space->horizontals[0]), player_id);
    update_cell_threats(&(cell_space->verticals[0]), player_id);
    update_cell_threats(&(cell_space->left_diags[0]), player_id);
    update_cell_threats(&(cell_space->right_diags[0]), player_id);
}

/**
 * Clear all the threats in the board.
 */
void clear_threats(local_space_t *local_space) {
    board_cell_t *cell = local_space->first_cell;
    board_cell_t *max_cell = cell + BOARD_NUM_CELLS;

    /* clear all values */
    for(; cell < max_cell; ++cell) {
        cell->threat = 0;
        cell->benefit = 0;
        cell->weight = 0;
    }
}

/**
 * Calculate the threat levels of every cell in the game board for player_id.
 */
void calculate_threats(local_space_t *local_space, const player_t player_id) {

    cell_space_t *space = &(local_space->cell_space[0]);
    const cell_space_t *max_space = space + BOARD_NUM_CELLS;

    /* calculate each space */
    for(; space < max_space; ++space) {
        update_local_space(space, player_id);
    }
}

/**
 * Add a position on the board and update the threat scores.
 */
void add_threat(local_space_t *local_space,
                board_cell_t *cell,
                const player_t player_id) {

    cell->player_id = player_id;
    clear_threats(local_space);
    calculate_threats(local_space, player_id);
}

/**
 * Remove a position from the board and update the threat scores. Note that
 * the threat scores are not re-caculated as that would be unnecessary. Any
 * future additions to the board as threats will be re-calculated anyway.
 */
void remove_threat(local_space_t *local_space,
                   board_cell_t *cell,
                   const player_t player_id) {

    cell->player_id = NO_PLAYER;
}
