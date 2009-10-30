/*
 * main.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "context.h"
#include "board.h"
#include "threat.h"
#include "status.h"
#include "ocs.h"

/*#include "game.h"*/

#if 0
static void print_board_and_threat(board_t *board, player_t player_id) {
    int i;
    int j;
    board_cell_t *cell;

    printf("Board: \n");
    for(i = 0; i < BOARD_LENGTH; ++i) {
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(board->cells[i][j]);
            if(cell->player_id == NO_PLAYER) {
                printf("0 ");
            } else {
                printf("%d ", (int) cell->player_id);
            }
        }
        printf("\n");
    }
#if 0
    printf("\nThreats: \n    ");
    for(i = 0; i < BOARD_LENGTH; ++i) {
        printf("%5d", i);
    }
    printf("\n   +");
    for(i = 0; i < BOARD_LENGTH; ++i) {
        printf("-----");
    }
    printf("\n");
    for(i = 0; i < BOARD_LENGTH; ++i) {
        printf("%2d |", i);
        for(j = 0; j < BOARD_LENGTH; ++j) {
            cell = &(board->cells[i][j]);
            if(cell->player_id == NO_PLAYER) {
                printf("%5d", cell->importance);
            } else if(cell->player_id != player_id) {
                printf("    X");
            } else {
                printf("    _");
            }
        }
        printf("\n");
    }
#endif
}
#endif
int negascout(board_t *board,
               const player_t player_id,
               const int depth,
               int alpha,
               int beta) {

    ordered_cell_seq_t seq;
    board_cell_t *cell;
    player_t opponent_id = OPPONENT(player_id);
    int a;
    int b;
    int i;
    int eval = fill_ocs(board, &seq);

    if(!depth || !seq.len) {
        return eval;
    }

    b = beta;

    for(i = 0; i < seq.len; ++i) {

        cell = seq.cells[i];
        add_threat(board, cell, player_id);

        a = -1 * negascout(board, opponent_id, depth - 1, -1 * b, -1 * alpha);

        if(a > alpha) {
            alpha = a;
        }

        if(alpha >= beta) {
            return alpha;
        }

        /* re-search */
        if(alpha >= b) {
            alpha = -1 * negascout(board, opponent_id, depth - 1, -1 * beta, -1 * alpha);
            if(alpha >= beta) {
                return alpha;
            }
        }

        b = alpha + 1;

        remove_threat(board, cell);
    }

    return alpha;
}

/**
 * Do simple
 */
int main(const int argc, const char *argv[]) {

    board_t board;
    board_cell_t *cell;
    player_t player_id;
    game_status_t status;

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

    /* make the first move of a game in the center of the board */
    if(board.num_empty_cells == BOARD_NUM_CELLS) {
        cell = &(board.cells[BOARD_CENTER][BOARD_CENTER]);
        cell->player_id = player_id;

    /* search for a move to make. */
    } else if(0 < board.num_empty_cells) {
        calculate_threats(&board);


        printf("negascout: %d\n", negascout(&board, player_id, 5, -9999, 9999));

        /*

        print_board_and_threat(&board, player_id);

        cell = &(board.cells[BOARD_CENTER][BOARD_CENTER]);

        add_threat(&board, cell, OPPONENT(player_id));

        remove_threat(&board, cell);

        print_board_and_threat(&board, player_id);*/


    }

    /* update the text file to notify that the game is over */
    status = game_status(&board, player_id);
    if(GAME_WON == status || GAME_DRAW == status) {

    }

    /* output the new board to the file */
    /*if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }*/

    return 1;
}
