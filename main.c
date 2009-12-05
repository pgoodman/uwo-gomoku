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
#include <time.h>

#include "common.h"
#include "board.h"
#include "move.h"
#include "history.h"

#if 0
static void print_board(board_t *board) {
    int i;
    int j;
    board_cell_t *cell;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(board->cells[i][j]);
            if(NO_PLAYER == cell->player_id) {
                /*printf("%5d", (cell->rating[0] + cell->rating[1] + cell->rating[2]));*/
                printf("%7d", cell->rating[0] + cell->chip_rating);
            } else if(PLAYER_1 == cell->player_id){
                printf("      X");
            } else {
                printf("      O");
            }
        }
        printf("\n");
    }
    printf("\n");
}
#endif



/**
 * Start up the AI and have it choose a move to make.
 */
int main(const int argc, const char *argv[]) {

    /* main copy of the board from the file that will be put back to the file */
    board_t board;

    /* secondary copy of the board used for searching. this copy exists as the
     * search performs in-place modifications of the board as it goes along,
     * and search can also be abruptly stopped with an alarm and context
     * switch, and so maintaining a stack of changes to undo was not enough to
     * guarantee that only one move would ever be placed back into the board
     * after we're done the search. */
    board_t search_board;

    /* the player id of the AI, other, and winner */
    player_t player_id;
    player_t opponent_id;

    /* the board cell that we will place our chip in */
    board_cell_t *board_cell = NULL;

    /* how long it takes to run the program. */
    time_t duration = time(NULL);

    /* make sure the board length is legal */
    STATIC_ASSERT(BOARD_LENGTH >= WINNING_SEQ_LENGTH);
    STATIC_ASSERT(BOARD_LENGTH > 0);
    STATIC_ASSERT(WINNING_SEQ_LENGTH > 0);

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

    /* clear out any old history */
    clear_old_history(&board, player_id);

    /* use the center of the board */
    if(BOARD_NUM_CELLS == board.num_empty_cells) {
        board_cell = &(board.cells[BOARD_CENTER][BOARD_CENTER]);
        board_cell->player_id = player_id;

    /* search for a move. */
    } else {

        /* choose the move that we want to make */
        board_cell = choose_move(&search_board, player_id, opponent_id);

        /* will only happen if the game has already been won. */
        if(NULL == board_cell) {
            DIE("No cell was chosen as the next move.\n");
        }

        /* make the move in search_board and perform pattern matching to see
         * if a win is matched. This will also rate the board, but we don't
         * care about the ratings, just that it does the right matching. */
        board_cell->player_id = player_id;
        rate_seqs_at_cell(board_cell);

        /* we are dealing with a coordinate from 'search_board' and we want
         * to modify a coordinate in 'board', normalize to 'board'. */
        board_cell = ((&(board.cells[0][0]))
                   + (board_cell - &(search_board.cells[0][0])));
        board_cell->player_id = player_id; /* cell in 'board' */

        /* check if the AI won or tied. */
        if(matched_win(player_id)) {
            file_put_contents(
                BOARD_DIR STATUS_FILE,
                &(GAME_WON_MESSAGE[0]),
                strlen(GAME_WON_MESSAGE)
            );

        /* the AI lost. */
        } else if(matched_win(opponent_id)) {
            fprintf(stdout, "%s\n", GAME_LOST_MESSAGE);

        /* the game is a draw */
        } else if(board.num_empty_cells <= 1) {
            file_put_contents(
                BOARD_DIR STATUS_FILE,
                GAME_DRAW_MESSAGE,
                strlen(GAME_DRAW_MESSAGE)
            );
        }
    }

    /* output the new board to the file */
    if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

    /* print out how long running the AI took */
    fprintf(
        stdout,
        "\nCompleted in %d seconds. \n",
        (int) (time(NULL) - duration)
    );

    return 1;
}
