/*
 * search.c
 *
 *  Created on: Nov 4, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "search.h"

#define D(x)
#define DD(x)
#define M(x)
#define R(x) x

typedef int (minmax_func)(const int, const int);

/**
 * A min/max search continuation.
 */
typedef struct _search_continuation_t {
    int curr_successor;
    int minmax_value;
    player_t player_id;
    ordered_cell_seq_t successors;
    board_cell_t *changed_cell;
    minmax_func *minmax_choice;

    struct _search_continuation_t *parent_cont;
} search_continuation_t;

/* stack of search continuations used for doing depth-first traversal */
static search_continuation_t stack[MAX_SEARCH_DEPTH];

/**
 * Return the minimum of two numbers.
 */
static int minmax_min(const int a, const int b) {
    M( printf("old min: %d; new min: %d \n", a, (a > b) ? b : a); )
    return (a > b) ? b : a;
}

/**
 * Return the maximum of two numbers.
 */
static int minmax_max(const int a, const int b) {
    M( printf("old max: %d; new max: %d \n", a, (a < b) ? b : a); )
    return (a > b) ? a : b;
}

/**
 * Perform a depth-first simulation of moves of the playing board, starting with
 * cell as the first move to set to our player's chip. This calculates the
 * min/max values of the nodes searched as well as calculating how many
 * wins and losses have occurred. The return is the minimax value of the node.
 */
int search_for_move(board_t *board,
                    board_cell_t *cell,
                    const player_t max_player_id,
                    int *win_diff) {

    int stack_offset = 0;
    int num_wins = 0;
    int num_losses = 0;

    board_cell_t *next_cell;
    search_continuation_t *cont = &(stack[0]);
    search_continuation_t *parent_cont = NULL;
    player_t next_chip_player_id;
    player_t winning_player_id;

    /* base case */
    cell->player_id = max_player_id;
    cont->changed_cell = cell;
    cont->player_id = max_player_id;
    cont->curr_successor = -1;
    cont->minmax_value = INT_MAX;
    cont->minmax_choice = &minmax_min;
    cont->parent_cont = NULL;
    gen_successors(board, &(cont->successors));

    /* do the depth-first minimax search */
    while(stack_offset >= 0) {

        D( printf("searching at depth %d ... \n", stack_offset); )

        /* the current search continuation */
        cont = &(stack[stack_offset]);
        parent_cont = cont->parent_cont;

        /* advance to the next node to be searched */
        ++(cont->curr_successor);

        D( printf("checking if we have more successors. \n"); )

        /* no more nodes to search at this level, pop it off and move up */
        if(cont->curr_successor >= cont->successors.len) {

            D( printf("popping stack... \n"); )

            cont->changed_cell->player_id = NO_PLAYER; /* undo the change */

            --stack_offset;

            if(NULL != cont->parent_cont) {
                DD( printf("backing up minimax value. \n"); )
                /* back up the min/max values */
                parent_cont->minmax_value = parent_cont->minmax_choice(
                    parent_cont->minmax_value,
                    cont->minmax_value
                );
            }

            D( printf("\tstack popped. \n"); )

            continue;
        }

        D( printf("we have a successor. \n"); )

        /* the next successor that we want to search */
        next_cell = cont->successors.cells[cont->curr_successor];

        /* we have a new successor to search, lets take a look at it. We have
         * a few conditions to consider:
         *
         *  i) If it's a winning or losing move then increment the win counters
         *     and also find the min/max value of the node. Then continue on
         *     as normal to see the next successor at the current level.
         *
         *  ii) If we're at the maximum search depth the calculate the min/max
         *      value of the current state and then continue on.
         *
         *  iii) If neither (i) or (ii) are true, push the state onto the stack
         *       to begin searching its successors.
         */

        /* start by placing the chip */
        next_chip_player_id = OPPONENT(cont->player_id);
        next_cell->player_id = next_chip_player_id;

        D( printf("placed chip, checking for winner. \n"); )

        /* check for a win. Note: that we consider a win for the *AI* and not
         * for whoever the player of the current level is. */
        winning_player_id = local_space_winner(next_cell, NULL);
        if(NO_PLAYER != winning_player_id) {

            D( printf("there is a winner. \n"); )

            /* increment the win counters */
            /*
            if(max_player_id == winning_player_id) {
                ++num_wins;
            } else {
                ++num_losses;
            }*/

            DD( printf("backing up minimax value... \n"); )

            /* calculate the min/max value of the current board. This is the
             * backed-up value as we haven't pushed anything onto the stack
             * yet. */
            cont->minmax_value = cont->minmax_choice(
                cont->minmax_value,
                minmax_evaluate(
                    board,
                    max_player_id,
                    next_chip_player_id,
                    winning_player_id,
                    &num_wins,
                    &num_losses
                )
            );

            /* undo the chip placement */
            next_cell->player_id = NO_PLAYER;

        /* nobody won, lets see if we're at the end of the stack or should
         * we just keep going. */
        } else {

            D( printf("there is no winner. \n"); )

            /* we're at the end of the stack, don't push anything on and
             * instead calculate the min/max value of the node. */
            if(stack_offset + 1 >= MAX_SEARCH_DEPTH) {

                D( printf("reached max depth. \n"); )

                DD( printf("backing up minimax value... \n"); )

                /* back up the min/max value */
                cont->minmax_value = cont->minmax_choice(
                    cont->minmax_value,
                    minmax_evaluate(
                        board,
                        max_player_id,
                        next_chip_player_id,
                        NO_PLAYER,
                        &num_wins,
                        &num_losses
                    )
                );

                /* undo the chip placement */
                next_cell->player_id = NO_PLAYER;

            /* we can keep searching, push a continuation onto the stack */
            } else {

                D( printf("pushing node on stack... \n"); )

                ++stack_offset;
                parent_cont = cont;
                cont = &(stack[stack_offset]);

                /* recurrence relation */
                cont->parent_cont = parent_cont;
                cont->changed_cell = next_cell;
                cont->player_id = next_chip_player_id;
                cont->curr_successor = -1;
                cont->minmax_value = (stack_offset & 1) ? INT_MIN : INT_MAX;
                cont->minmax_choice = (
                    (stack_offset & 1) ? &minmax_max : &minmax_min
                );

                gen_successors(board, &(cont->successors));

                D( printf("\tpushed. \n"); )
            }
        }
    }

    D( printf("cleaning up.\n"); )

    /* pass the tie breaking info for minimax values */
    (*win_diff) = num_wins - num_losses;

    R(
        printf(
            "num wins: %d; num losses: %d; minimax: %d \n",
            num_wins,
            num_losses,
            stack[0].minmax_value
        );
    )

    return stack[0].minmax_value;
}


