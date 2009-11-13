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
#include "seq.h"
#include "context.h"
#include "match.h"

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

#if 1
static void print_board(void) {
    int i;
    int j;
    board_cell_t *cell;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(board.cells[i][j]);
            if(NO_PLAYER == cell->player_id) {
                printf("%4d", (cell->rating[0] + cell->rating[1] + cell->rating[2]));
            } else if(PLAYER_1 == cell->player_id){
                printf("   X");
            } else {
                printf("   O");
            }
        }
        printf("\n");
    }
    printf("\n");
}
#endif

#if 0
/**
 * Choose a one of the immediate successors as a move to make. Note: this
 * implements the first MAX level of the min/max algorithm. This is intentional
 * as it allows us to exit this function early using context switching and still
 * get a move choice out of it. Also, this lets us use the extra
 * num_wins - num_losses heuristic as a way to break min/max ties. Whether or
 * not this is a good heuristic is another question!
 */
void choose_move(board_cell_t **cell) {

    ordered_cell_seq_t successors;

    int curr_succ;
    int minmax_val = INT_MIN;
    int minmax_temp;
    int win_diff = INT_MIN;
    int win_diff_temp;

    gen_successors(&search_board, &successors);

    for(curr_succ = 0; curr_succ < successors.len; ++curr_succ) {

        /* get the min/max value of this successor */
        minmax_temp = search_for_move(
            &search_board,
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
#endif

/**
 * Start up the AI and have it choose a move to make.
 */
int main(const int argc, const char *argv[]) {

#if 0
    player_t winner_id;
    board_cell_t *search_cell = NULL;
#endif
    board_cell_t *board_cell = NULL;

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

    /* copy the board data structure into the search_board. */
    memcpy(&search_board, &board, sizeof(board_t));

    /* use the center of the board */
    if(BOARD_NUM_CELLS == board.num_empty_cells) {
        board_cell = &(board.cells[BOARD_CENTER][BOARD_CENTER]);
        board_cell->player_id = player_id;

    /* search for a move. */
    } else {

        init_seqs(&board);
        print_board();

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

        /* this shouldn't happen, but it's worth checking... */
        if(NULL == search_cell) {
            DIE("No cell was chosen as the next move.\n");
        }

        /* we are dealing with a coordinate from 'search_board' and we want
         * to modify a coordinate in 'board', normalize to 'board'. */
        board_cell = (
            (&(board.cells[0][0])) + (search_cell - &(search_board.cells[0][0]))
        );
        board_cell->player_id = player_id; /* cell in 'board' */

        /* check if the AI won or tied. */
        winner_id = local_space_winner(search_cell, &board);
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
#endif
    }

    /* output the new board to the file */
    if(0 && !put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

    return 1;
}
