/*
 * common
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <assert.h>

/* configuration macros */
#define MAX_SEARCH_TIME 1 /* time limit for solution searching */
#define MAX_SEARCH_DEPTH 7 /* depth-limit */
#define MAX_SUCCESSORS_TO_SEARCH 5 /* node breadth limit */

#define WINNING_SEQ_LENGTH 5

#define BOARD_LENGTH 15 /* default board width/height */
#define BOARD_DIR "./"
#define BOARD_FILE "board.txt" /* default location of board file */
#define STATUS_FILE "final.txt" /* game status file */
#define GAME_WON_MESSAGE "I have won the game!"
#define GAME_DRAW_MESSAGE "I have drawn the game!"

/* other */
#define THREAT_BASE 4
#define BENEFIT_BASE 4
#define LOCAL_SPACE 4
#define CELL_WEIGHT_INCREMENT 1
#define MAX_EVALUATION 99999

/* computed macros */
#define BOARD_NUM_CELLS (BOARD_LENGTH * BOARD_LENGTH)
#define BOARD_NUM_DIAGONALS ((BOARD_LENGTH - WINNING_SEQ_LENGTH) * 2 + 1)
#define BOARD_CENTER ((int) (BOARD_LENGTH / 2))
#define BOARD_MIN_BUFFER_SIZE (BOARD_NUM_CELLS * 2)
#define BOARD_BUFFER_SIZE (BOARD_MIN_BUFFER_SIZE + 2 * BOARD_LENGTH)

/* function-like macros */
#define DIE(err) {fprintf(stderr, "%s", (err));exit(EXIT_FAILURE);}
#define PRINT(str) {fprintf(stdout, "%s", (str));}
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define STATIC_ASSERT(pred) switch(0){case 0:case (pred):;}
#define DYNAMIC_ASSERT(pred) assert((pred))
#define OPPONENT(p) ((p)==PLAYER_1 ? PLAYER_2 : PLAYER_1)

/* types */
typedef enum {
    NO_PLAYER,
    PLAYER_1,
    PLAYER_2
} player_t;

typedef unsigned int cell_rating_t;

#endif /* COMMON_H_ */
