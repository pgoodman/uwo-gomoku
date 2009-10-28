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
static void update_cell_threats(board_cell_t **cells,
                                const int left,
                                const int right,
                                const player_t player_id) {
    int i;
    threat_rating_t threat = 0;
    threat_rating_t benefit = 0;

    /* go to the left in the sequence */
    for(i = left + 1; i < right; ++i) {

        /* empty */
        if(cells[i]->is_nothing) {

        /* our own chip */
        } else if(benefit >= 0 && cells[i]->player_id == player_id) {
            threat = -1;
            benefit += 1;

        /* opponent */
        } else if(threat >= 0 && cells[i]->player_id != player_id) {
            benefit = -1;
            threat += 1;
        }
    }

    threat = (threat > 0) ? pow(THREAT_BASE, threat) : 0;
    benefit = (benefit > 0) ? pow(BENEFIT_BASE, benefit) : 0;
    threat += benefit;

    if(threat > 0) {
        for(i = left + 1; i < right; ++i) {
            if(cells[i]->is_nothing) {
                cells[i]->threat_rating += threat;
            }
        }
    }
}

/**
 * Clear all the threat ratings except for the ignore cell in a sequence.
 */
static void clear_threats_with_seq(board_cell_seq_t *seq,
                                   board_cell_t *ignore_cell) {
    int i = 0;
    for(; i < seq->len; ++i) {
        if(seq->cells[i] == ignore_cell) {
            continue;
        }
        seq->cells[i]->threat_rating = DEFAULT_THREAT;
    }
}


/**
 * Given a sequence of adjacent cells from the game board, increase the threat
 * rating of each empty cell that is near an opponent chip and increase the
 * benefit rating of each empty cell that is near our chips.
 */
void update_threats_with_seq(board_t *board,
                             board_cell_seq_t *seq,
                             player_t player_id) {
    int i; /* current cell */
    board_cell_t **cells = seq->cells;

    /* look at each cell in the sequence */
    for(i = 0; i < seq->len; ++i) {
        update_cell_threats(
            cells,
            MAX(i - (LOCAL_SPACE + 1), -1), /* left bound, exclusive */
            MIN(i + (LOCAL_SPACE + 1), seq->len), /* right bound, exclusive */
            player_id
        );
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

    /* change the cell */
    cell->threat_rating = DEFAULT_THREAT;

    /* configure the cell sequence */
    init_bcs(board, &seq);

    /* figure out where in the playing board this cell is */
    col = (int) ((cell - cells) % BOARD_LENGTH);
    row = (int) ((cell - cells) - col) / BOARD_LENGTH;

    ldiag = col >= row ? BOARD_LENGTH - (col - row) : BOARD_LENGTH + (row - col);
    rdiag = row >= col ? (row - col) : (col - row);

    /* apply the threat levels to the sequences */
    if(generate_nth_bcs(&seq, 0, D_LEFT_RIGHT)) {
        clear_threats_with_seq(&seq, cell);
        update_threats_with_seq(board, &seq, player_id);
    }

    if(generate_nth_bcs(&seq, col, D_TOP_BOTTOM)) {
        clear_threats_with_seq(&seq, cell);
        update_threats_with_seq(board, &seq, player_id);
    }

    if(ldiag >= BOARD_LENGTH
    && ldiag < (BOARD_LENGTH * 2 - WINNING_SEQ_LENGTH)
    && generate_nth_bcs(&seq, ldiag - WINNING_SEQ_LENGTH, D_LEFT_DIAG)) {
        clear_threats_with_seq(&seq, cell);
        update_threats_with_seq(board, &seq, player_id);
    }

    if(rdiag >= BOARD_LENGTH
    && rdiag < (BOARD_LENGTH * 2 - WINNING_SEQ_LENGTH)
    && generate_nth_bcs(&seq, rdiag - WINNING_SEQ_LENGTH, D_RIGHT_DIAG)) {
        clear_threats_with_seq(&seq, cell);
        update_threats_with_seq(board, &seq, player_id);
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
