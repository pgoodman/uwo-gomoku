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
#include "evaluate.h"

#if 1

/**
 * Do simple
 */
int main(const int argc, const char *argv[]) {
    board_t board;
    board_cell_t *cell;
    board_cell_string_t string;
    player_t player_id;

    /* make sure the board length is legal */
    if(BOARD_LENGTH < 5) {
        DIE("Program compiled with illegal board length.\n");
    }

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
        cell->is_nothing = 0;

    /* search for a move to make. */
    } else {

        reset_board_string(&board, &string);
        while(generate_board_string(&string)) {
            printf("string generated: %s \n", string.str);
        }

        /*
        if(!board.num_empty_cells) {
            PRINT("Game is over.\n");
            return 1;
        }
        */
    }

    /* output the new board to the file */
    if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

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
