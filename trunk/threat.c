/*
 * threat.c
 *
 *  Created on: Oct 27, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "threat.h"

/**
 * For each cell, score the cells to the left and right in the current
 * sequence of cells.
 */
static void update_cell_threats(board_cell_t **cells,
                                const int curr_cell,
                                const int threat_benefit,
                                const player_t player_id) {
    int j;

    /* go to the left in the sequence */
    for(j = curr_cell - 1; j > curr_cell - WINNING_SEQ_LENGTH; --j) {
        if(cells[j]->is_nothing) {
            ++(cells[j]->threat_benefit[threat_benefit]);

        /* we hit a wall, stop */
        } else if(cells[j]->player_id == player_id) {
            break;
        }
    }

    /* go to the right */
    for(j = curr_cell + 1; j < curr_cell + WINNING_SEQ_LENGTH; ++j) {
        if(cells[j]->is_nothing) {
            ++(cells[j]->threat_benefit[threat_benefit]);

        /* we hit a wall, stop */
        } else if(cells[j]->player_id == player_id) {
            break;
        }
    }
}

/**
 * Given a sequence of adjacent cells from the game board, increase the threat
 * rating of each empty cell that is near an opponent chip and increase the
 * benefit rating of each empty cell that is near our chips.
 */
void update_threats_with_seq(board_t *board, board_cell_seq_t *seq) {
    int i; /* current cell */
    board_cell_t **cells = seq->cells;
    const player_t player_id = cells[0]->player_id; /* the threatened player */
    const player_t opponent_id = OPPONENT(player_id);

    /* look at each cell in the sequence */
    for(i = 1; i <= seq->len; ++i) {

        /* empty cell or one of our chips */
        if(cells[i]->is_nothing) {
            continue;

        /* us */
        } else if(cells[i]->player_id == player_id) {
            change_bcs_player(seq, opponent_id);
            update_cell_threats(cells, i, BENEFIT, opponent_id);
            change_bcs_player(seq, player_id);

        /* opponent */
        } else {
            update_cell_threats(cells, i, THREAT, player_id);
        }
    }
}

/**
 * Calculate the threat rating of each cell.
 */
void compute_threat_ratings(board_t *board) {
    int i;
    int j;
    board_cell_t *cell;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(board->cells[i][j]);

            /* calculate the threat rating from the number of nearby threats
             * and the number of nearby opportunities. */
            cell->threat_rating = (threat_rating_t) (
                powf((float) cell->threat_benefit[THREAT], THREAT_EXPONENT) +
                powf((float) cell->threat_benefit[BENEFIT], BENEFIT_EXPONENT)
            );
        }
    }
}
#if 0
/**
 * Create (or reuse) and apply a threat patch around the cell. This assumes
 * that the cell being patched has a coin on it.
 */
threat_patch_t *apply_threat_patch(board_t *board,
                                   board_cell_t *cell,
                                   threat_patch_t *unused_patch) {

    const player_t player_id = cell->player_id;
    const player_t opponent_id = OPPONENT(player_id);
    board_cell_t *cells = &(board->cells[0][0]);
    threat_patch_t *patch = unused_patch;
    int row;
    int col;
    int ldiag;
    int rdiag;

    /* re-use or allocate a patch */
    if(NULL == patch) {
        patch = malloc(sizeof(threat_patch_t));
        if(NULL == patch) {
            DIE("Unable to allocate new threat patch.\n");
        }
    }

    /* configure the patch */
    patch->board = board;
    patch->player_id = player_id;
    patch->threat_benefit[THREAT] = cell->threat_benefit[THREAT];
    patch->threat_benefit[BENEFIT] = cell->threat_benefit[BENEFIT];

    /* change the cell */
    cell->threat_benefit[THREAT] = DEFAULT_THREAT;
    cell->threat_benefit[BENEFIT] = DEFAULT_BENEFIT;

    /* figure out where in the playing board this cell is */
    col = (int) ((cell - cells) % BOARD_LENGTH);
    row = (int) ((cell - cells) - col) / BOARD_LENGTH;

    ldiag = col >= row ? BOARD_LENGTH - (col - row) : BOARD_LENGTH + (row - col);


    return patch;
}
#endif
