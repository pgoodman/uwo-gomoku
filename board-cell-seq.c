/*
 * board-cell-seq.c
 *
 *  Created on: Oct 25, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "board-cell-seq.h"

#define D_LEFT_RIGHT 0
#define D_TOP_BOTTOM 1
#define D_LEFT_DIAG 2
#define D_RIGHT_DIAG 3

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
void init_bcs(board_t *board, board_cell_seq_t *seq) {
    DYNAMIC_ASSERT(NULL != board);
    DYNAMIC_ASSERT(NULL != seq);

    seq->board = board;
    seq->id = -1;
    seq->dir = D_LEFT_RIGHT;
}


/**
 * Generate a single board string. A board sequence is one which has:
 *
 *   i)   at least one unused board position;
 *   ii)  at least one used board positions
 *   iii) comes from a horizontal, vertical, or diagonal.
 *   iv)  has length at least WINNING_SEQUENCE_LENGTH and at most BOARD_LENGTH
 *
 * Each board string has as zero representing an empty cell, a 1 representing
 * a cell played by player 1, and a 2 representing a cell played by player 2.
 * There are no spaces between the cells (i.e. characters) and each generated
 * string is null-terminated.
 */
int generate_bcs(board_cell_seq_t *seq) {

    int empty_board_pos_found;
    int non_empty_board_pos_found;
    int i;
    int j;
    int i_incr;
    int j_incr;
    int k;
    int offset;
    board_cell_t *cell;

    DYNAMIC_ASSERT(NULL != seq);

    do {
        /* advance to the next sequence */
        update_bcs(seq);

        i = j = i_incr = j_incr = k = 0;
        empty_board_pos_found = 0;
        non_empty_board_pos_found = 0;
        offset = WINNING_SEQUENCE_LENGTH + seq->id;
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

        /* cut off any final diagonals that are too short */
        if(seq->dir > 1 && i > (BOARD_LENGTH - WINNING_SEQUENCE_LENGTH)) {
            seq->id = BOARD_LENGTH * 2;
            continue;
        }

        /* fill the sequence */
        for(; i >= 0 && i < BOARD_LENGTH && j >= 0 && j < BOARD_LENGTH; ++k) {

            cell = &(seq->board->cells[i][j]);

            /* figure out if we should accept this sequence */
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

    } while(!(empty_board_pos_found && non_empty_board_pos_found));

    return 1;
}
