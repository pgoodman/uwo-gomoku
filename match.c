/*
 * match.c
 *
 *  Created on: Nov 10, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "match.h"

#define D(x)
#define U(x)

/* empty cells that we've seen when matching */
static board_cell_t *empties[BOARD_LENGTH];
static int num_empties = 0;

/* statistics on matches */
static int num_wins[3] = {0, 0, 0};
static int num_almost_wins[3] = {0, 0, 0};
static int num_dt_constructs[3] = {0, 0, 0};

/* values used for checking if we have matches */
static int num_cells_in_seq = 0;
static int num_chips_in_seq = 0;
static int num_trailing_empties = 0;
static int num_leading_empties = 0;
static int interior_empty_offset = -1;
static int first_chip_offset = -1;
static player_t player_chips = NO_PLAYER;

/* should we increment or decrement cell scores */
static int mult = 1;

/**
 * Update the match info given a the player id of the current cell.
 */
static void update_pattern_info(board_cell_t *cell, const int i) {

    const player_t player_id = cell->player_id;

    /* the pattern matcher is specific to sequences of length 5 */
    STATIC_ASSERT(5 == WINNING_SEQ_LENGTH);

    /* empty cell */
    if(NO_PLAYER == player_id) {

        /* record for later ;) */
        empties[num_empties++] = cell;

        /* this is the nth empty cell in a row. */
        if(num_trailing_empties) {

            /* we are still at the start of a string */
            if(num_cells_in_seq <= num_leading_empties) {
                num_leading_empties += 1;
            }

        /* this is the first empty we have seen since the start or since a
         * chip */
        } else {

            /* if we aren't in a sequence then this is a leading empty. */
            if(NO_PLAYER == player_chips) {
                num_leading_empties = 1;

            /* if we are in a sequence then this could be a trailing empty
             * or an interior empty */
            } else if(-1 == interior_empty_offset) {
                interior_empty_offset = i;
            }
        }

        num_cells_in_seq += 1;
        num_trailing_empties += 1;

        /* cut the leading empties short */
        if(num_leading_empties >= 2) {
            num_cells_in_seq = num_cells_in_seq - (num_leading_empties - 2);
            num_leading_empties = 2;
        }

    /* player 1 or 2 chip */
    } else {

        /* we are continuing as part of a sequence or this is the first
         * chip that we have seen. */
        if(NO_PLAYER == player_chips || player_id == player_chips) {

            player_chips = player_id;
            num_cells_in_seq += 1;
            num_chips_in_seq += 1;

            /* this is the first chip we've seen */
            if(-1 == first_chip_offset) {
                first_chip_offset = i;

            /* we seen some chips */
            } else {

                /* we need to break the sequence because we don't want there
                 * to be more than one interiors. */
                if(num_trailing_empties >= 2 && -1 != interior_empty_offset) {
                    num_chips_in_seq = 1;
                    num_leading_empties = num_trailing_empties;
                    num_cells_in_seq = num_leading_empties + 1;
                    interior_empty_offset = -1;
                    first_chip_offset = i;
                }
            }

        /* we are breaking a sequence and starting a new one, swap the
         * trailing cells for the leading cells. */
        } else {
            player_chips = player_id;
            num_cells_in_seq = num_trailing_empties + 1;
            num_chips_in_seq = 1;
            num_leading_empties = num_trailing_empties;
            interior_empty_offset = -1;
            first_chip_offset = i;
        }

        /* now that we have seen a chip, it means there aren't any trailing
         * empty cells (yet) */
        num_trailing_empties = 0;
    }
}

/**
 * Reset the match info.
 */
static void reset_match_info(void) {
    num_empties = 0;
    num_cells_in_seq = 0;
    num_chips_in_seq = 0;
    num_trailing_empties = 0;
    num_leading_empties = 0;
    interior_empty_offset = -1;
    first_chip_offset = -1;
    player_chips = NO_PLAYER;
}

/**
 * Attempt to match a winning sequence, i.e.: 5 chips in a row.
 */
static void match5(const int i) {
    const int num_surrounding_empties = num_leading_empties + num_trailing_empties;
    const int num_interior_cells = num_cells_in_seq - num_surrounding_empties;

    if(5 != num_chips_in_seq || 5 != num_interior_cells) {
        return;
    }

    D( printf("matched 5 \n"); )

    num_cells_in_seq -= 1;
    if(num_leading_empties) {
        num_leading_empties -= 1;
    } else {
        num_chips_in_seq -= 1;
    }

    /* matched 5 in a row! */
    num_wins[player_chips] += mult * 1;
}

/**
 * Attempt to match a threat pattern with four chips where the addition of
 * one chip would result in a win.
 */
static void match4(const int i) {

    const int num_surrounding_empties = num_leading_empties + num_trailing_empties;
    const int num_interior_cells = num_cells_in_seq - num_surrounding_empties;

    /* check to see if we have matched a four-in-a-row */
    if(4 != num_chips_in_seq || num_cells_in_seq < 5) {
        return;
    }

    /* we matched four in a row, with an interior cell empty */
    if(5 == num_interior_cells) {

        /* matched 4, with one interior empty */
        D( printf("matched 4 (broken) \n"); )
        num_almost_wins[player_chips] += mult * 1;
        empties[num_empties - 1]->rating[player_chips] += mult * IT_BROKEN_4;

        num_chips_in_seq -= 1;
        first_chip_offset += 1;

        /* we can't advance the chip offset into an empty cell */
        if(first_chip_offset == interior_empty_offset) {
            num_leading_empties = 1;
            first_chip_offset += 1;

            if(num_trailing_empties) {
                interior_empty_offset = (i - num_trailing_empties) + 1;
            } else {
                interior_empty_offset = -1;
            }
        }

        /* update the num cells in seq properly */
        num_cells_in_seq = (
            (num_leading_empties + num_trailing_empties + num_chips_in_seq)
        );

        if(-1 != interior_empty_offset
        && interior_empty_offset != ((i - num_trailing_empties) + 1)) {
            num_cells_in_seq += 1;
        }

    /* we matched four in a row, with an exterior cell empty */
    } else if(4 == num_interior_cells) {

        /* matched 4, with one exterior empty */
        D( printf("matched 4 (straight) \n"); )
        num_almost_wins[player_chips] += mult * 1;
        empties[num_empties - 1]->rating[player_chips] += mult * IT_STRAIGHT_4;

        /* if there are leading empties then just skip over them */
        if(num_leading_empties) {
            num_cells_in_seq -= num_leading_empties;
        } else {
            num_cells_in_seq -= num_trailing_empties;
            num_chips_in_seq -= 1;
            first_chip_offset += 1;
        }

        num_leading_empties = 0;
    }
}

/**
 * Match a threat pattern with 3 chips and 2 or 3 empties, such that the
 * addition of one more chip could result in a double threat.
 */
static void match3(const int i) {
    const int num_surrounding_empties = num_leading_empties + num_trailing_empties;
    const int num_interior_cells = num_cells_in_seq - num_surrounding_empties;

    if(num_chips_in_seq != 3 || num_cells_in_seq < 5
    || !num_leading_empties || !num_trailing_empties) {
        return;
    }

    /* matched 3 with 1 leading and 2 tailing empty cells */
    if(3 == num_interior_cells && num_cells_in_seq >= 6) {

        D( printf("matched 3 (straight extended) \n"); )
        num_dt_constructs[player_chips] += mult * 1;

        empties[num_empties - 3]->rating[player_chips] += mult * IT_EXTENDED_3;
        empties[num_empties - 2]->rating[player_chips] += mult * IT_EXTENDED_3_MID;
        empties[num_empties - 1]->rating[player_chips] += mult * IT_EXTENDED_3;

        /* update the leading cells */
        if(num_leading_empties) {
            num_leading_empties -= 1;
            num_cells_in_seq -= 1;
        }
    }

    /* matched 3 with 1 (or more) leading and 1 tailing cells */
    if(1 <= num_leading_empties && 1 == num_trailing_empties) {

        num_dt_constructs[player_chips] += mult * 1;

        /* matched 3, with 1 internal empty cell */
        if(4 == num_interior_cells) {
            D( printf("matched 3 (broken) \n"); )
            empties[num_empties - 3]->rating[player_chips] += mult * IT_BROKEN_3;
            empties[num_empties - 2]->rating[player_chips] += mult * IT_BROKEN_3_MID;
            empties[num_empties - 1]->rating[player_chips] += mult * IT_BROKEN_3;

        /* matched 3, with 1 leading and tailing empty cell */
        } else {
            D( printf("matched 3 (straight) \n"); )
            empties[num_empties - 2]->rating[player_chips] += mult * IT_STRAIGHT_3;
            empties[num_empties - 1]->rating[player_chips] += mult * IT_STRAIGHT_3;
        }
    }
}

/**
 * Perform pattern matching on a single sequence of null-terminated board cell
 * pointers.
 */
void match_seq(board_cell_t **cell, const int increment_mult) {
    int i;

    if(NULL == cell) {
        return;
    }

    mult = increment_mult;

    /* match patterns */
    reset_match_info();
    for(i = 0; *cell != NULL; ++cell, ++i) {
        U( printf("%3d", (*cell)->player_id); )
        update_pattern_info(*cell, i);
        match5(i);
        match4(i);
        match3(i);
    }

    U( printf("\n"); )
}

/**
 * Was a win matched? If so, return the number of total wins matched, otherwise
 * zero.
 */
int matched_win(void) {
    return (num_wins[1] + num_wins[2]);
}
