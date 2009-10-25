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

#if 0
int main(const int argc, const char *argv[]) {
    board_cell_t board[BOARD_HEIGHT][BOARD_WIDTH];

    if(!read_board(board)) {
        DIE("Unable to read playing board.\n");
    }

    board[10][10] = CELL_PLAYER2;

    if(!put_board(board)) {
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
