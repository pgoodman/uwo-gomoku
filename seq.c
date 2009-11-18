/*
 * seq.c
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "seq.h"

/* map cells to cell sequences */
static board_cell_seq_t *cell_to_seqs[BOARD_NUM_CELLS][4];
static board_cell_seq_t board_cell_seqs[BOARD_NUM_SEQS];

static board_cell_seq_t *curr_seq;
static board_cell_t *first_cell;

/**
 * Fill up cell sequences until we've filled them up with k_max cell pointers.
 */
static void fill_seqs(int i_start,
                      int j_start,
                      const int i_incr,
                      const int j_incr,
                      const int i_start_incr,
                      const int j_start_incr,
                      const int k_max) {
    int i;
    int j;
    int k = 0;
    const int len = BOARD_LENGTH;
    board_cell_t **cell;

    /* fill up several sequences of cell pointers */
    for(; k < k_max; ++curr_seq) {

        cell = &(curr_seq->cells[0]);

        /* fill up and individual sequence */
        for(i = i_start, j = j_start;
            i >= 0 && i < len && j >= 0 && j < len;
            i += i_incr, j += j_incr, ++k, ++cell) {

            *cell = first_cell + ((i * len) + j);
        }

        *cell = NULL; /* trailing null */

        i_start = MIN(MAX(0, i_start + i_start_incr), len - 1);
        j_start = MIN(MAX(0, j_start + j_start_incr), len - 1);
    }
}

/**
 * Fill up all of the cell sequences.
 */
static void fill_all_seqs(void) {

    extern board_cell_seq_t board_cell_seqs[];

    /* information related to sequencing diagonals */
    const int diag_big_max = (BOARD_NUM_CELLS / 2) - BOARD_LENGTH;
    const int diag_small_max = diag_big_max - 2;
    const int diag_off = (BOARD_LENGTH - WINNING_SEQ_LENGTH);

    curr_seq = &(board_cell_seqs[0]);

    /* fill the sequences */
    fill_seqs(0, 0, 0, 1, 1, 0, BOARD_NUM_CELLS); /* - */
    fill_seqs(0, 0, 1, 0, 0, 1, BOARD_NUM_CELLS); /* | */
    fill_seqs(0, diag_off, 1, 1, 0, -1, diag_big_max); /* \ */
    fill_seqs(1, 0, 1, 1, 1, 0, diag_small_max); /* \ */
    fill_seqs(0, WINNING_SEQ_LENGTH - 1, 1, -1, 0, 1, diag_big_max); /* / */
    fill_seqs(1, BOARD_LENGTH - 1, 1, -1, 1, 0, diag_small_max); /* / */
}

/**
 * Relate each cell to its four cell sequences.
 */
static void map_cells_to_seqs(void) {

    extern board_cell_seq_t board_cell_seqs[];

    int i;
    int j;
    int k;
    int ldiag;
    int rdiag;
    const int min_diag = WINNING_SEQ_LENGTH;
    const int max_diag = BOARD_LENGTH + BOARD_LENGTH - WINNING_SEQ_LENGTH;
    board_cell_seq_t *seq;

    for(k = 0, i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j, ++k) {
            seq = &(board_cell_seqs[0]);

            /* link to the vertical */
            cell_to_seqs[k][0] = seq + i;
            seq += BOARD_LENGTH;

            /* link to the horizontal */
            cell_to_seqs[k][1] = seq + j;
            seq += BOARD_LENGTH;

            /* figure out on which diagonals this cell is located */
            ldiag = BOARD_LENGTH + i - j;
            rdiag = i + j + 1;

            /* link to the left diagonal */
            if(ldiag >= min_diag && ldiag <= max_diag) {
                cell_to_seqs[k][2] = seq + (ldiag - min_diag);
            } else {
                cell_to_seqs[k][2] = NULL;
            }
            seq += BOARD_NUM_DIAGONALS;

            /* link to the right diagonal */
            if(rdiag >= min_diag && rdiag <= max_diag) {
                cell_to_seqs[k][3] = seq + (rdiag - min_diag);
            } else {
                cell_to_seqs[k][3] = NULL;
            }
        }
    }
}

/**
 * Initialize the sequences. This will construct all sequences of cells for
 * the horizontals, verticals, and both diagonals, and then it will create a
 * table to link every cell to the four sequences pivoted at that cell.
 */
void init_seqs(board_t *board) {
    first_cell = &(board->cells[0][0]);
    fill_all_seqs();
    map_cells_to_seqs();
}

/**
 * Return the nth board cell sequence centered at this cell. NULL is returned
 * if no such sequence exists. There are at most 4 sequences.
 */
board_cell_t **nth_cell_seq_at_cell(board_cell_t *cell, const int n) {
    if(n < 0 || n >= 4) {
        return NULL;
    }

    return &(cell_to_seqs[(int) (cell - first_cell)][n]->cells[0]);
}

/**
 * Return the nth board cell sequences. NULL is returned if no such sequence
 * exists.
 */
board_cell_seq_t *nth_cell_seq(const int n) {
    if(n < 0 || n >= BOARD_NUM_SEQS) {
        return NULL;
    }

    return &(board_cell_seqs[n]);
}
