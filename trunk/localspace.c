/*
 * localspace.c
 *
 *  Created on: Oct 30, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "localspace.h"

/* extra 1 for trailing NULL */
#define CELL_SPACE_LENGTH (LOCAL_SPACE + LOCAL_SPACE + 2)

typedef struct {
    board_cell_t *seq[4][CELL_SPACE_LENGTH];
} cell_space_t;

typedef struct {
    board_cell_t *first_cell;
    cell_space_t cell_space[BOARD_NUM_CELLS];
} local_space_t;

static player_t max_player_id;
static board_t *game_board;
static local_space_t local_space;

/**
 * Fill up the cell space. Each cell space is a n-tuple in the local space of
 * the cell centered at (i_init, j_init), where n=WINNING_SEQ_LENGTH. This
 * initialized the cell weights, then nearby number of player 1 cells, and the
 * nearby number of player 2 cells.
 */
static void fill_cell_space(board_t *board,
                            board_cell_t **cell,
                            const int i_init, /* row */
                            const int j_init, /* column */
                            const int i_incr,
                            const int j_incr) {

    /* figure out the looping bounds */
    const int N = LOCAL_SPACE;

    /* the bounding box the our traversal */
    const int i_min = MAX(0, i_init - N);
    const int i_max = MIN(BOARD_LENGTH - 1, i_init + N);
    const int j_min = MAX(0, j_init - N);
    const int j_max = MIN(BOARD_LENGTH - 1, j_init + N);

    /* where we start in the bounding box */
    const int i_start = MIN(i_max, MAX(i_min, (i_init - (i_incr * N))));
    const int j_start = MIN(j_max, MAX(j_min, (j_init - (j_incr * N))));

    int i;
    int j;

    /* fill this local space */
    for(i = i_start, j = j_start;
        i >= i_min && j >= j_min && i <= i_max && j <= j_max;
        i += i_incr, j += j_incr, ++cell) {

        *(cell) = &(board->cells[i][j]);
    }

    *(cell) = NULL; /* trailing null */
}

/**
 * Score the five cells centered at the current cell.
 */
static void update_cell_ratings(const int i_init,
                                const int j_init,
                                const int i_incr,
                                const int j_incr) {
    cell_rating_t threat = 0;
    cell_rating_t benefit = 0;
    cell_rating_t importance = 0;
    board_cell_t *cell;

    int i;
    int j;

    const int N = (WINNING_SEQ_LENGTH / 2);
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

        cell = &(game_board->cells[i][j]);
        if(cell->player_id == NO_PLAYER) {
            continue;


        /* our own chip */
        } else if(cell->player_id == max_player_id) {
            benefit += 1;

        /* opponent */
        } else {
            threat += 1;
        }
    }

    /* calculate threat value */
    if(!threat) { importance += (benefit * benefit * benefit * benefit); }
    if(!benefit) { importance += (threat * threat * threat * threat); }

    /* increment the threat level of all cells in the local space */
    if(threat || benefit) {
        for(i = i_start, j = j_start;
            i >= i_min && i <= i_max && j >= j_min && j <= j_max;
            i += i_incr, j += j_incr) {

            cell = &(game_board->cells[i][j]);
            if(cell->player_id == NO_PLAYER) {
                cell->rating += importance;
            }
        }
    }
}

/**
 * Evaluate the local space. This is a one-off ranking that goes through and
 * tries to rank cells. It tries to hint at what a good first move is. By
 * default the board has a bias toward the centre, this gives it a bias towards
 * the majority of the cells.
 */
static void eval_local_space(void) {
    int i;
    int j;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            update_cell_ratings(i, j, 0, 1);
            update_cell_ratings(i, j, 1, 0);
            update_cell_ratings(i, j, 1, 1);
            update_cell_ratings(i, j, 0, 1);
            update_cell_ratings(i, j, 1, -1);
        }
    }
}

/**
 * Fill up the local space. The local space is used for figuring out the
 * importance of each cell.
 */
void init_local_space(board_t *board, const player_t player_id) {
    int i;
    int j;
    cell_space_t *cell_space = &(local_space.cell_space[0]);

    /* store a pointer to the first cell of the board */
    max_player_id = player_id;
    local_space.first_cell = &(board->cells[0][0]);
    game_board = board;

    /* fill up the local space */
    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j, ++cell_space) {

            fill_cell_space(board, &(cell_space->seq[0][0]), i, j, 0, 1); /* - */
            fill_cell_space(board, &(cell_space->seq[1][0]), i, j, 1, 0); /* | */
            fill_cell_space(board, &(cell_space->seq[2][0]), i, j, 1, 1); /* \ */
            fill_cell_space(board, &(cell_space->seq[3][0]), i, j, 1, -1); /* / */
        }
    }

    /* evaluate the ratings */
    eval_local_space();
}

/**
 * Return the player id that won in the current local space, or NO_PLAYER
 * if no one won. Note: this checks it using one cell space with respect to
 * another (possibly non-existant) one.
 */
player_t local_space_winner(board_cell_t *center_cell, board_t *normal_board) {

    cell_space_t *cell_space = &(local_space.cell_space[
        (unsigned int) (center_cell - local_space.first_cell)
    ]);

    board_cell_t **first_cell;
    board_cell_t **cell;
    board_cell_t *normal = local_space.first_cell;

    player_t player_id;

    int i;
    int num_in_line = 0;

    /* find out the start of the normal. */
    if(NULL != normal_board) {
        normal = &(normal_board->cells[0][0]);
    }

    /* go over the four cell sequences in this cell space */
    for(i = 0; i < 4; ++i) {

        first_cell = &(cell_space->seq[i][0]);
        num_in_line = 0;

        /* go over each cell in a cell sequence */
        for(cell = first_cell; NULL != (*cell); ++cell) {

            /* normalize to a possibly different board! */
            player_id = (
                normal + ((unsigned int) ((*cell) - local_space.first_cell))
            )->player_id;

            /* a break in a sequence of chips */
            if(player_id == NO_PLAYER) {
                num_in_line = 0;

            /* player 1 chip, will either continue a line or break one */
            } else if(player_id == PLAYER_1) {
                if(num_in_line >= 0) {
                    ++num_in_line;
                } else {
                    num_in_line = 1;
                }

            /* player 2 chip, will either continue a line or break one */
            } else {
                if(num_in_line <= 0) {
                    --num_in_line;
                } else {
                    num_in_line = -1;
                }
            }

            /* someone won in this cell space. */
            if(WINNING_SEQ_LENGTH == num_in_line) {
                return PLAYER_1;
            } else if(WINNING_SEQ_LENGTH == -1 * num_in_line) {
                return PLAYER_2;
            }
        }
    }

    return NO_PLAYER;
}

