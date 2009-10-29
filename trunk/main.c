/*
 * main.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "common.h"
#include "context.h"
#include "board.h"
#include "threat.h"

#if 1

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
                printf("%5d", cell->threat_rating);
            } else if(cell->player_id != player_id) {
                printf("    X");
            } else {
                printf("    _");
            }
        }
        printf("\n");
    }
}


/**
 * Do simple
 */
int main(const int argc, const char *argv[]) {

    board_t board;
    board_cell_t *cell;
    /*board_cell_seq_t seq;*/
    player_t player_id;

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
    } else {

        /* game board is empty */
        if(!board.num_empty_cells) {
            PRINT("Game is over.\n");
            return 1;
        }

        /* generate the threat matrix for the current board configuration if
         * it were the current player's turn and also if it were the other
         * player's turn. */
        calculate_threats(&board, player_id);
        print_board_and_threat(&board, player_id);

        add_threat(&board, &(board.cells[1][1]), player_id, player_id);
        add_threat(&board, &(board.cells[14][0]), player_id, player_id);
        add_threat(&board, &(board.cells[2][12]), player_id, player_id);
        add_threat(&board, &(board.cells[11][11]), player_id, player_id);

        print_board_and_threat(&board, player_id);

        remove_threat(&board, &(board.cells[1][1]), player_id);
        remove_threat(&board, &(board.cells[14][0]), player_id);
        remove_threat(&board, &(board.cells[2][12]), player_id);
        remove_threat(&board, &(board.cells[11][11]), player_id);

        print_board_and_threat(&board, player_id);
    }

    /* output the new board to the file */
    /*if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }*/

    return 1;
}

#else
static int i = 0;

static void search_for_move(void *context) {
    int tested = 0;
    while(++i) {
        fprintf(stdout, "searching...\n");

        /* test stopping short about half of the time. */
        if(i > 9000 && !tested) {
            tested = 1;
            if(rand() & 1) {
                yield();
            }
        }
    }
}

static void use_best_found_move(void *context) {
    fprintf(stdout, "alarm up, using move %d.\n", i);
}

int main(int argc, char *argv[]) {

    srand((unsigned int) time(NULL));

    timed_computation(
        (context_func_t *) &search_for_move,
        NULL,
        MAX_SEARCH_TIME
    );

    use_best_found_move(NULL);

    return 1;
}
#endif
