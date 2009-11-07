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
#include "localspace.h"
#include "successors.h"
#include "search.h"
#include "context.h"
#include "evaluate.h"

static board_t board;
static player_t player_id;

#if 0
static void print_board(board_t *board) {
    int i;
    int j;
    board_cell_t *cell;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(board->cells[i][j]);
            if(NO_PLAYER != cell->player_id) {
                printf("    *");
            } else {
                printf("%5d", (int) cell->rating);
            }
        }
        printf("\n");
    }
}
#endif

/**
 * Choose a one of the immediate successors as a move to make. Note: this
 * implements the first MAX level of the minimax algorithm. This is intentional
 * as it allows us to exit this function early using context switching and still
 * get a move choice out of it.
 */
static void choose_move(board_cell_t **cell) {

    ordered_cell_seq_t successors;

    int curr_succ;
    int minmax_val = INT_MIN;
    int minmax_temp;
    int win_diff = INT_MIN;
    int win_diff_temp;

    gen_successors(&board, &successors);

    for(curr_succ = 0; curr_succ < successors.len; ++curr_succ) {

        /* get the minimax value of this successor */
        minmax_temp = search_for_move(
            &board,
            successors.cells[curr_succ],
            player_id,
            &win_diff_temp
        );

        /* replace the minimax value, even in the event of a tie. Note:
         * there is no third-level tie breaker :P */
        if(minmax_temp > minmax_val
        || (minmax_temp == minmax_val && win_diff_temp > win_diff)) {
            minmax_val = minmax_temp;
            *cell = successors.cells[curr_succ];
            win_diff = win_diff_temp;
        }
    }
}

/**
 * Do simple
 */
int main(const int argc, const char *argv[]) {

    player_t winner_id;
    board_cell_t *cell = NULL;

    /* make sure the board length is legal */
    STATIC_ASSERT(BOARD_LENGTH >= WINNING_SEQ_LENGTH);

    /* get the player information */
    if(argc < 2) {
        DIE("No player id was given.\n");
    }

    if(*argv[1] == '1') {
        player_id = PLAYER_1;
    } else if(*argv[1] == '2') {
        player_id = PLAYER_2;
    } else {
        DIE("Invalid player id given.\n");
    }

    /* get and check the board. */
    if(!read_board(&board)) {
        DIE("Unable to read playing board.\n");
    }

    /* use the center of the board */
    if(BOARD_NUM_CELLS == board.num_empty_cells) {
        cell = &(board.cells[BOARD_CENTER][BOARD_CENTER]);
        cell->player_id = player_id;

    /* search for a move. */
    } else {

        init_local_space(&board, player_id);
        /*print_board(&board);*/

        /* search through the board for a winning or losing move and take it
         * immediately. We can do this with out evaluation function, i.e. we
         * evaluate the start state!
         */
        minmax_evaluate(&board, player_id, player_id, NO_PLAYER);
        yield_best_move(&cell, player_id);

        /* no such winning or block losing move exists. search for a move for
         * approximately 8 seconds, after that give up and just use whatever
         * cell we chose most recently. */
        if(NULL == cell) {
            timed_computation((timed_func_t *) &choose_move, (void *) &cell, 8);
        }

        /* this shouldn't happen, but it's worth checking... */
        if(NULL == cell) {
            DIE("No cell was chosen as the next move.\n");
        }

        /* make our move */
        cell->player_id = player_id;

        /* the program won! */
        winner_id = local_space_winner(cell);
        if(player_id == winner_id) {
            file_put_contents(
                BOARD_DIR STATUS_FILE,
                &(GAME_WON_MESSAGE[0]),
                strlen(GAME_WON_MESSAGE)
            );

        /* the game is a draw */
        } else if(NO_PLAYER == winner_id && 1 >= board.num_empty_cells) {
            file_put_contents(
                BOARD_DIR STATUS_FILE,
                &(GAME_DRAW_MESSAGE[0]),
                strlen(GAME_DRAW_MESSAGE)
            );
        }
    }

    /* output the new board to the file */
    if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

    return 1;
}
