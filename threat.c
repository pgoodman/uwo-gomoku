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
void compute_threat_ratings(board_t *board,
                            const int top,
                            const int right,
                            const int bottom,
                            const int left) {
    int i;
    int j;
    board_cell_t *cell;

    for(i = top; i < bottom; ++i) {
        for(j = left; j < right; ++j) {
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

/**
 * Create (or reuse) and apply a threat patch around the cell. This assumes
 * that the cell being patched has a coin on it.
 */
void patch_threat_ratings(board_t *board,
                          board_cell_t *cell,
                          const player_t player_id) {

    board_cell_t *cells = &(board->cells[0][0]);
    board_cell_seq_t seq;

    int row;
    int col;
    int ldiag;
    int rdiag;
    const int bounds = WINNING_SEQ_LENGTH - 1;

    /* re-use or allocate a patch */
    /*
    if(NULL == patch) {
        patch = malloc(sizeof(threat_patch_t));
        if(NULL == patch) {
            DIE("Unable to allocate new threat patch.\n");
        }
    }*/

    /* configure the patch */
    /*
    patch->board = board;
    patch->player_id = player_id;
    patch->threat_benefit[THREAT] = cell->threat_benefit[THREAT];
    patch->threat_benefit[BENEFIT] = cell->threat_benefit[BENEFIT];
    */

    /* change the cell */
    cell->threat_benefit[THREAT] = DEFAULT_THREAT;
    cell->threat_benefit[BENEFIT] = DEFAULT_BENEFIT;

    /* configure the cell sequence */
    init_bcs(board, &seq, player_id);

    /* figure out where in the playing board this cell is */
    col = (int) ((cell - cells) % BOARD_LENGTH);
    row = (int) ((cell - cells) - col) / BOARD_LENGTH;

    ldiag = col >= row ? BOARD_LENGTH - (col - row) : BOARD_LENGTH + (row - col);
    rdiag = row >= col ? (row - col) : (col - row);

    /*printf("row:%d col:%d ldiag:%d rdiag:%d \n", row, col, ldiag, rdiag);*/

    /*
    printf("sequence: ");
    for(i = 1; i <= seq.len; ++i) {
        printf("%d ", seq.cells[i]->is_nothing ? 0 : (int) seq.cells[i]->player_id);
    }
    printf("\n");
     */

    /* apply the threat levels to the sequences */
    if(generate_nth_bcs(&seq, 0, D_LEFT_RIGHT)) {
        update_threats_with_seq(board, &seq);
    }

    if(generate_nth_bcs(&seq, col, D_TOP_BOTTOM)) {
        update_threats_with_seq(board, &seq);
    }

    if(ldiag >= BOARD_LENGTH
    && ldiag < (BOARD_LENGTH * 2 - WINNING_SEQ_LENGTH)
    && generate_nth_bcs(&seq, ldiag - WINNING_SEQ_LENGTH, D_LEFT_DIAG)) {
        update_threats_with_seq(board, &seq);
    }

    if(rdiag >= BOARD_LENGTH
    && rdiag < (BOARD_LENGTH * 2 - WINNING_SEQ_LENGTH)
    && generate_nth_bcs(&seq, rdiag - WINNING_SEQ_LENGTH, D_RIGHT_DIAG)) {
        update_threats_with_seq(board, &seq);
    }

    /* update the threat scores in the bounding box */
    compute_threat_ratings(
        board,
        MIN(row, MAX(0, row - bounds)), /* top */
        MAX(col, MIN(BOARD_LENGTH, col + bounds)), /* right */
        MAX(row, MIN(BOARD_LENGTH, row + bounds)), /* bottom */
        MIN(col, MAX(0, col - bounds))
    );
}
