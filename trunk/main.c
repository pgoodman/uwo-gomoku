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

#include "common.h"
#include "context.h"
#include "board.h"
#include "threat.h"
#include "localspace.h"
#include "successors.h"
#include "winner.h"

/*#include "game.h"*/
#if 0
static void print_board_and_threat(board_t *board, player_t player_id) {
    int i;
    int j;
    board_cell_t *cell;
#if 0
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
#endif
#if 1
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
                printf("%5d", cell->threat + cell->benefit + cell->weight);
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
#if 0
int negascout(board_t *board,
              local_space_t *local_space,
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

    successors(board, &seq);

    if(!depth || !seq.len) {
        return eval;
    }

    b = beta;

    for(i = 0; i < seq.len; ++i) {

        cell = seq.cells[i];
        add_threat(local_space, cell, opponent_id);

        a = -1 * negascout(
            board,
            local_space,
            opponent_id,
            depth - 1,
            -1 * b,
            -1 * alpha
        );

        if(a > alpha) {
            alpha = a;
        }

        if(alpha >= beta) {
            return alpha;
        }

        /* re-search */
        if(alpha >= b) {
            alpha = -1 * negascout(
                board,
                local_space,
                opponent_id,
                depth - 1,
                -1 * beta,
                -1 * alpha
            );

            if(alpha >= beta) {
                return alpha;
            }
        }

        b = alpha + 1;

        remove_threat(local_space, cell);
    }

    return alpha;
}
#endif

static int evaluate(board_t *board) {
    board_cell_t *cell = &(board->cells[0][0]);
    board_cell_t *max = cell + BOARD_NUM_CELLS;
    int max_threat = 0;
    int max_benefit = 0;
    int max_weight = 0;

    for(; cell < max; ++cell) {
        if(cell->player_id == NO_PLAYER) {
            max_threat += cell->threat;
            max_benefit += cell->benefit;
            max_weight += cell->weight;
        }
    }

    return max_threat > max_benefit ? -1 : (max_threat == max_benefit ? 0 : 1);
}

static int negamax(board_t *board,
                   local_space_t *local_space,
                   board_cell_t *prev_cell,
                   board_cell_t **max_cell,
                   player_t player_id,
                   const int depth,
                   const int num_empty_cells) {

    ordered_cell_seq_t successors;
    board_cell_t **cell;
    board_cell_t **max;
    int max_val = -1 * (1 << 15); /* should be lower than any eval result */
    int curr_val;

    /* someone won */
    if(NULL != prev_cell && NO_PLAYER != local_winner(local_space, prev_cell)) {
        return evaluate(board) * 2;

    /* reach the depth */
    } else if(!depth) {
        return evaluate(board);

    /* draw */
    } else if(!num_empty_cells) {
        return 0;
    }

    /* generate the initial successor states */
    gen_successors(board, &successors);

    cell = &(successors.cells[0]);
    max = cell + successors.len;

    /* go over the successors and choose the best one */
    for(; cell < max; ++cell) {
        add_threat(local_space, *cell, player_id);

        /* calculate the negamax value for this node. */
        curr_val = -1 * negamax(
            board,
            local_space,
            *cell,
            NULL,
            OPPONENT(player_id),
            depth - 1,
            num_empty_cells - 1
        );

        /* have we found a new best negamax value? */
        if(max_val < curr_val) {
            max_val = curr_val;

            /* only update the top level one, ignore all lower levels */
            if(NULL != max_cell) {
                *max_cell = *cell;
            }
        }

        remove_threat(local_space, *cell);
    }

    return max_val;
}

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
        /*
        cell = &(board.cells[7][5]);
        add_threat(&local_space, cell, player_id);

        print_board_and_threat(&board, player_id);

        remove_threat(&local_space, cell);

        cell->player_id = player_id;
        calculate_threats(&local_space, player_id);
        print_board_and_threat(&board, player_id);

        */
        negamax(
            &board,
            &local_space,
            NULL, /* prev cell */
            &cell, /* max cell */
            player_id,
            5,
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
            GAME_WON_MESSAGE,
            strlen(GAME_WON_MESSAGE)
        );

    /* the game is a draw */
    } else if(NO_PLAYER == winner_id && 1 >= board.num_empty_cells) {
        file_put_contents(
            BOARD_DIR STATUS_FILE,
            GAME_DRAW_MESSAGE,
            strlen(GAME_DRAW_MESSAGE)
        );
    }

    /* output the new board to the file */
    if(!put_board(&board)) {
        DIE("Unable to output the board.\n");
    }

    return 1;
}
