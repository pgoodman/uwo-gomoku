/*
 * main.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "common.h"
#include "board.h"
#include "successors.h"
#include "context.h"
#include "rate.h"

/* main copy of the board from the file that will be put back to the file */
static board_t board;

/* secondary copy of the board used for searching. this copy exists as the
 * search performs in-place modifications of the board as it goes along, and
 * search can also be abruptley stopped with an alarm and context switch, and
 * so maintaining a stack of changes to undo was not enough to guarantee that
 * only one move would ever be placed back into the board after we're done the
 * search. */
static board_t search_board;

/* the player id of the AI */
static player_t player_id;
static player_t opponent_id;
static player_t winner_id = NO_PLAYER;

#if 1
static void print_board(void) {
    int i;
    int j;
    board_cell_t *cell;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(search_board.cells[i][j]);
            if(NO_PLAYER == cell->player_id) {
                printf("%5d", (cell->rating[0] + cell->rating[1] + cell->rating[2]));
            } else if(PLAYER_1 == cell->player_id){
                printf("    X");
            } else {
                printf("    O");
            }
        }
        printf("\n");
    }
    printf("\n");
}
#endif

static board_cell_t *make_move(void) {
    ordered_cell_seq_t max_succ;
    ordered_cell_seq_t min_succ;

    const cell_rating_t win_score = MIN(IT_BROKEN_4, IT_STRAIGHT_4);
    const cell_rating_t dt_score = MIN(IT_BROKEN_3, IT_EXTENDED_3);

    board_cell_t **max_cell;
    board_cell_t **min_cell;

    init_ratings(&search_board);

    /* we won't waste processing power needlessly making a move. */
    if(matched_win()) {
        return NULL;
    }

    gen_successors(&search_board, &max_succ, player_id);
    gen_successors(&search_board, &min_succ, opponent_id);

    max_cell = &(max_succ.cells[0]);
    min_cell = &(min_succ.cells[0]);

    /* can we make a winning move immediately? */
    if((*max_cell)->rating[player_id] >= win_score) {
        winner_id = player_id;
        return *max_cell;

    /* can we block a win? */
    } else if((*min_cell)->rating[opponent_id] >= win_score) {

        /* doesn't matter, we have lost anyway */
        if((*(min_cell + 1))->rating[opponent_id] >= dt_score) {
            winner_id = opponent_id;
        }
        return *min_cell;

    /* can we make a double threat? */
    } else if((*max_cell)->rating[player_id] >= dt_score) {
        return *max_cell;

    /* can we block a double threat? */
    } else if((*min_cell)->rating[opponent_id] >= dt_score) {
        return *min_cell;
    }

    return NULL;
}

/**
 * Start up the AI and have it choose a move to make.
 */
int main(const int argc, const char *argv[]) {

    board_cell_t *board_cell = NULL;

    /* make sure the board length is legal */
    STATIC_ASSERT(BOARD_LENGTH >= WINNING_SEQ_LENGTH);

    /* get the player information */
    if(argc < 2) {
        DIE("No player id was given.\n");
    }

    if(*argv[1] == '1') {
        player_id = PLAYER_1;
        opponent_id = PLAYER_2;
    } else if(*argv[1] == '2') {
        player_id = PLAYER_2;
        opponent_id = PLAYER_1;
    } else {
        DIE("Invalid player id given.\n");
    }

    /* get and check the board. */
    if(!read_board(&board)) {
        DIE("Unable to read playing board.\n");
    }

    /* copy the board data structure into the search_board. */
    memcpy(&search_board, &board, sizeof(board_t));

    /* use the center of the board */
    if(BOARD_NUM_CELLS == board.num_empty_cells) {
        board_cell = &(board.cells[BOARD_CENTER][BOARD_CENTER]);
        board_cell->player_id = player_id;

    /* search for a move. */
    } else {

        board_cell = make_move();
        print_board();

        /* this shouldn't happen, but it's worth checking... */
        if(NULL == board_cell) {
            DIE("No cell was chosen as the next move.\n");
        }

        /* we are dealing with a coordinate from 'search_board' and we want
         * to modify a coordinate in 'board', normalize to 'board'. */
        board_cell = ((&(board.cells[0][0]))
                   + (board_cell - &(search_board.cells[0][0])));
        board_cell->player_id = player_id; /* cell in 'board' */

        /* check if the AI won or tied. */
        if(player_id == winner_id) {
            file_put_contents(
                BOARD_DIR STATUS_FILE,
                &(GAME_WON_MESSAGE[0]),
                strlen(GAME_WON_MESSAGE)
            );

        /* the AI lost. */
        } else if(opponent_id == winner_id) {
            fprintf(stdout, "%s\n", GAME_LOST_MESSAGE);

        /* the game is a draw */
        } else if(1 >= board.num_empty_cells) {
            file_put_contents(
                BOARD_DIR STATUS_FILE,
                GAME_DRAW_MESSAGE,
                strlen(GAME_DRAW_MESSAGE)
            );
        }

#if 0
        init_local_space(&search_board, player_id);

        /* search through the board for a winning or losing move and take it
         * immediately. */
        search_cell = yield_best_move(&search_board, player_id);

        /* no such winning or block losing move exists. search for a move for
         * approximately 8 seconds, after that give up and just use whatever
         * cell we chose most recently. */
        if(NULL == search_cell) {

            /* go and search for a move until completion or until time runs
             * out. */
            timed_computation(
                (timed_func_t *) &choose_move,
                (void *) &search_cell,
                MAX_SEARCH_TIME
            );
        }
#endif
    }

    /* output the new board to the file */
    if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

    return 1;
}
