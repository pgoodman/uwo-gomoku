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

/* what did we match? */
static int matched_wins[3] = {0, 0, 0};

/* empty and full cells that we've seen when matching */
static int empty_offsets[BOARD_LENGTH];
static board_cell_t *empties[BOARD_LENGTH];
static board_cell_t *chips[BOARD_LENGTH];
static int empty_offset = -1;
static int chip_offset = -1;

/* values used for checking if we have matches */
static int num_cells_in_seq = 0;
static int num_chips_in_seq = 0;
static int num_trailing_empties = 0;
static int num_leading_empties = 0;
static int interior_empty_offset = -1;
static int first_chip_offset = -1;
static player_t player_chips = NO_PLAYER;

/* callbacks for when a match is made. */
static match5_callback_t *on_match_5 = &match5_ignore;
static match4ext_callback_t *on_match_4_ext = &match4ext_ignore;
static match4_callback_t *on_match_4_straight = &match4_ignore;
static match4_callback_t *on_match_4_broken = &match4_ignore;
static match3ext_callback_t *on_match_3_broken = &match3ext_ignore;
static match3_callback_t *on_match_3_straight = &match3_ignore;
static match3ext_callback_t *on_match_3_ext = &match3ext_ignore;

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
        empties[++empty_offset] = cell;
        empty_offsets[empty_offset] = i;

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

        chips[++chip_offset] = cell;

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
    empty_offset = -1;
    chip_offset = -1;
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

    /* record the win */
    matched_wins[player_chips] += 1;

    /* should we mark the chips? */
    on_match_5(
        chips[chip_offset - 4],
        chips[chip_offset - 3],
        chips[chip_offset - 2],
        chips[chip_offset - 1],
        chips[chip_offset]
    );
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
        on_match_4_broken(
            chips[chip_offset - 3],
            chips[chip_offset - 2],
            chips[chip_offset - 1],
            chips[chip_offset],
            empties[empty_offset]
        );

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
        on_match_4_straight(
            chips[chip_offset - 3],
            chips[chip_offset - 2],
            chips[chip_offset - 1],
            chips[chip_offset],
            empties[empty_offset]
        );

        /* if there are leading empties then just skip over them */
        if(num_leading_empties) {
            num_cells_in_seq -= num_leading_empties;
        } else {
            num_cells_in_seq -= num_trailing_empties;
            num_chips_in_seq -= 1;
            first_chip_offset += 1;
        }

        num_leading_empties = 0;

        /* check if we matched a straight four with an empty on either side.
         * we consider this a win as there is no way to block it. */
        if(i == interior_empty_offset && empty_offset > 0
        && (i - 5) == empty_offsets[empty_offset - 1]) {

            D( printf("matched 4 (straight extended) \n"); )
            on_match_4_ext(
                chips[chip_offset - 3],
                chips[chip_offset - 2],
                chips[chip_offset - 1],
                chips[chip_offset],
                empties[empty_offset - 1],
                empties[empty_offset]
            );
        }
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
        on_match_3_ext(
            chips[chip_offset - 2],
            chips[chip_offset - 1],
            chips[chip_offset],
            empties[empty_offset - 2],
            empties[empty_offset - 1],
            empties[empty_offset]
        );

        /* update the leading cells */
        if(num_leading_empties) {
            num_leading_empties -= 1;
            num_cells_in_seq -= 1;
        }
    }

    /* matched 3 with 1 (or more) leading and 1 tailing cells */
    if(1 <= num_leading_empties && 1 == num_trailing_empties) {

        /* matched 3, with 1 internal empty cell */
        if(4 == num_interior_cells) {

            D( printf("matched 3 (broken) \n"); )
            on_match_3_broken(
                chips[chip_offset - 2],
                chips[chip_offset - 1],
                chips[chip_offset],
                empties[empty_offset - 2],
                empties[empty_offset - 1],
                empties[empty_offset]
            );

        /* matched 3, with 1 leading and tailing empty cell */
        } else {

            D( printf("matched 3 (straight) \n"); )
            on_match_3_straight(
                chips[chip_offset - 2],
                chips[chip_offset - 1],
                chips[chip_offset],
                empties[empty_offset - 1],
                empties[empty_offset]
            );
        }
    }
}

/**
 * Initialize the pattern matcher by setting the match result functions. Each
 * callback is called when a particular type of match is made.
 */
void init_matcher(match5_callback_t *match5_straight,
                  match4_callback_t *match4_straight,
                  match4_callback_t *match4_broken,
                  match4ext_callback_t *match4_ext,
                  match3_callback_t *match3_straight,
                  match3ext_callback_t *match3_broken,
                  match3ext_callback_t *match3_ext) {

    on_match_5 = match5_straight;
    on_match_4_ext = match4_ext;
    on_match_4_straight = match4_straight;
    on_match_4_broken = match4_broken;
    on_match_3_broken = match3_broken;
    on_match_3_straight = match3_straight;
    on_match_3_ext = match3_ext;
}

/**
 * Perform pattern matching on a single sequence of null-terminated board cell
 * pointers.
 */
void match_seq(board_cell_t **cell) {
    int i;

    if(NULL == cell) {
        return;
    }

    /* match patterns */
    reset_match_info();
    for(i = 0; *cell != NULL; ++cell, ++i) {
        update_pattern_info(*cell, i);
        match5(i);
        match4(i);
        match3(i);
    }

    U( printf("\n"); )
}

/**
 * Clear out the matches information.
 */
void clear_matches(void) {
    matched_wins[PLAYER_1] = 0;
    matched_wins[PLAYER_2] = 0;
}

/**
 * Was a win matched? If so, return the number of total wins matched, otherwise
 * zero.
 */
int matched_win(const player_t player_id) {
    if(NO_PLAYER == player_id) {
        return (matched_wins[PLAYER_1] + matched_wins[PLAYER_2]) > 0;
    }

    return matched_wins[player_id] > 0;
}

/* callbacks for doing nothing on a specific match */
void match5_ignore(board_cell_t *c1,
                   board_cell_t *c2,
                   board_cell_t *c3,
                   board_cell_t *c4,
                   board_cell_t *c5) { }

void match4ext_ignore(board_cell_t *c1,
                      board_cell_t *c2,
                      board_cell_t *c3,
                      board_cell_t *c4,
                      board_cell_t *e1,
                      board_cell_t *e2) { }

void match4_ignore(board_cell_t *c1,
                   board_cell_t *c2,
                   board_cell_t *c3,
                   board_cell_t *c4,
                   board_cell_t *e1) { }

void match3_ignore(board_cell_t *c1,
                   board_cell_t *c2,
                   board_cell_t *c3,
                   board_cell_t *e1,
                   board_cell_t *e2) { }

void match3ext_ignore(board_cell_t *c1,
                      board_cell_t *c2,
                      board_cell_t *c3,
                      board_cell_t *e1,
                      board_cell_t *e2,
                      board_cell_t *e3) { }

