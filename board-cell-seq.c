/*
 * board-cell-seq.c
 *
 *  Created on: Oct 25, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "board-cell-seq.h"

/**
 * Update which sequence to get and the current sequence direction.
 */
static void update_bcs(board_cell_seq_t *seq) {
    DYNAMIC_ASSERT(NULL != seq);

    ++(seq->id);

    /* should we switch direction or are we done generating sequences? */
    switch(seq->dir) {
        case D_LEFT_RIGHT:
        case D_TOP_BOTTOM:
            if(seq->id > BOARD_LENGTH) {
                seq->id = 0;
                ++seq->dir;
                printf("\n");
            }
            break;
        case D_LEFT_DIAG:
        case D_RIGHT_DIAG:
            if(seq->id > BOARD_NUM_DIAGONALS) {
                seq->id = 0;
                ++seq->dir;
                printf("\n");
            }
            break;
        default:
            seq->dir = -1;
            break;
    }
}

/**
 * Initialize a board sequence generator.
 */
void init_bcs(board_t *board, board_cell_seq_t *seq, const player_t player_id) {
    DYNAMIC_ASSERT(NULL != board);
    DYNAMIC_ASSERT(NULL != seq);

    seq->board = board;
    seq->id = -1;
    seq->dir = D_LEFT_RIGHT;
    seq->only_one = 0;

    /* make the wall, this is a dummy cell */
    seq->wall.player_id = player_id;
    seq->wall.is_nothing = 0;
    seq->wall.threat_benefit[THREAT] = DEFAULT_THREAT;
    seq->wall.threat_benefit[BENEFIT] = DEFAULT_BENEFIT;
    seq->wall.threat_rating = 0;
    seq->cells[0] = &(seq->wall);
}

/**
 * Change the wall of a board cell sequence.
 */
void change_bcs_player(board_cell_seq_t *seq, const player_t player_id) {
    DYNAMIC_ASSERT(NULL != seq);
    seq->wall.player_id = player_id;
}

/**
 * Generate a single board sequence. A board sequence is one which has:
 *
 *   i)   at least one unused board position;
 *   ii)  at least one used board positions
 *   iii) comes from a horizontal, vertical, or diagonal.
 *   iv)  has length at least WINNING_SEQUENCE_LENGTH and at most BOARD_LENGTH
 *
 * Each board string has as zero representing an empty cell, a 1 representing
 * a the current player, and a 2 representing the opponent player. There are
 * no spaces between the cells (i.e. characters) and each generated string is
 * null-terminated.
 *
 * Each board string is bounded on either side by a 1, representing our own
 * chip.
 */
int generate_bcs(board_cell_seq_t *seq) {

    int empty_board_pos_found;
    int non_empty_board_pos_found;
    int i; /* row */
    int j; /* column */
    int i_incr; /* how much to increment i by at each iteration */
    int j_incr; /* how much to increment j by at each iteration */
    int k; /* the index into the current sequence */
    int offset; /* figure out where to initialize i and j for diagonals */
    int has_sequence;
    board_cell_t *cell;

    DYNAMIC_ASSERT(NULL != seq);

    do {
        /* advance to the next sequence */
        update_bcs(seq);

        i = j = i_incr = j_incr = 0;
        k = 1;
        empty_board_pos_found = 0;
        non_empty_board_pos_found = 0;
        offset = WINNING_SEQ_LENGTH + seq->id;
        seq->len = 0;

        /* configurations for how to loop over the game board */
        switch(seq->dir) {

            /* left to right, starts from the left */
            case D_LEFT_RIGHT:
                i = seq->id;
                j_incr = 1;
                break;

            /* top to bottom, starts from the left */
            case D_TOP_BOTTOM:
                j = seq->id;
                i_incr = 1;
                break;

            /* top left to bottom right, starts from the right */
            case D_LEFT_DIAG:
                i = MAX(0, offset - BOARD_LENGTH);
                j = MAX(0, BOARD_LENGTH - offset);
                i_incr = 1;
                j_incr = 1;
                break;

            /* top right to bottom left, starts from the left */
            case D_RIGHT_DIAG:
                i = MAX(0, offset - BOARD_LENGTH);
                j = MIN(offset - 1, BOARD_LENGTH - 1);
                i_incr = 1;
                j_incr = -1;
                break;

            /* done generating */
            default:
                return 0;
        }

        /* cut off any final diagonals that are too short. force a change of
         * direction or termination of the generator. */
        if(seq->dir > 1 && i > (BOARD_LENGTH - WINNING_SEQ_LENGTH)) {
            seq->id = BOARD_LENGTH * 2;
            has_sequence = 0;
            continue;
        }

        /* fill the sequence */
        for(; i >= 0 && i < BOARD_LENGTH && j >= 0 && j < BOARD_LENGTH; ++k) {

            cell = &(seq->board->cells[i][j]);

            /*
            printf(
                "cell(%d,%d) is %d.\n",
                i,
                j,
                (int)(cell->is_nothing ? 0 : cell->player_id)
            );*/

            /* fill up the string and also keep track of what we've seen. */
            if(cell->is_nothing) {
                empty_board_pos_found = 1;
            } else {
                non_empty_board_pos_found = 1;
            }

            /* record the cell pointer and continue */
            seq->cells[k] = cell;
            ++(seq->len);
            i += i_incr;
            j += j_incr;
        }

        has_sequence = empty_board_pos_found && non_empty_board_pos_found;

    } while(!seq->only_one && !has_sequence);

    /* move the trailing wall */
    seq->cells[seq->len + 1] = &(seq->wall);

    return has_sequence;
}

/**
 * Generate the nth board cell sequence and then reset the generator to its
 * previous state.
 */
int generate_nth_bcs(board_cell_seq_t *seq, const int n, const int dir) {

    seq->dir = dir;
    seq->id = n - 1;
    seq->only_one = 1;

    return generate_bcs(seq);
}
