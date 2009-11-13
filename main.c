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
#include <limits.h>

#include "common.h"
#include "board.h"
#include "context.h"
#include "move.h"

#if 1
static void print_board(board_t *board) {
    int i;
    int j;
    board_cell_t *cell;

    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(board->cells[i][j]);
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
    player_t winner_id = NO_PLAYER;

    /* the board cell that we will place our chip in */
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

        board_cell = make_move(
            &search_board,
            player_id,
            opponent_id,
            &winner_id
        );

        print_board(&search_board);

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
    }

    /* output the new board to the file */
    if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

    return 1;
}
