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

#include "common.h"
#include "board.h"
#include "threat.h"
#include "localspace.h"
#include "winner.h"
#include "negamax.h"

/**
 * Do simple
 */
int main(const int argc, const char *argv[]) {

    board_t board;
    board_cell_t *cell;
    player_t player_id;
    player_t winner_id;
    local_space_t local_space;

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
    if(board.num_empty_cells == BOARD_NUM_CELLS) {
        cell = &(board.cells[BOARD_CENTER][BOARD_CENTER]);

    /* search for a move to make. */
    } else {
        init_local_space(&board, &local_space);
        calculate_threats(&local_space, player_id);

        negamax(
            &board,
            &local_space,
            NULL, /* prev cell */
            &cell, /* max cell */
            player_id,
            0, /* max */
            MAX_SEARCH_DEPTH,
            board.num_empty_cells
        );
    }

    /* make the move */
    cell->player_id = player_id;

    /* the program won */
    winner_id = global_winner(&board);
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

    /* output the new board to the file */
    if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

    return 1;
}
