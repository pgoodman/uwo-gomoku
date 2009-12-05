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
#define WINNING_SEQ_LENGTH 5
#define BOUND_BOX_EXTEND 6
#define SEARCH_DEPTH 2
#define ENABLE_HISTORY 0
#define HISTORY_SCALE_FACTOR 1024

#define BOARD_LENGTH 15 /* default board width/height */
#define BOARD_DIR "./"
#define BOARD_FILE "board.txt" /* default location of board file */
#define STATUS_FILE "final.txt" /* game status file */
#define GAME_WON_MESSAGE "I have won the game!"
#define GAME_DRAW_MESSAGE "I have drawn the game!"
#define GAME_LOST_MESSAGE "I have lost the game."

/* incremental threat scores to various types of threat sequences */
#define IT_STRAIGHT_5 2048
#define IT_EXTENDED_4 1024
#define IT_STRAIGHT_4 1024
#define IT_BROKEN_3 128
#define IT_BROKEN_3_MID 256
#define IT_EXTENDED_3 128
#define IT_EXTENDED_3_MID 256
#define IT_STRAIGHT_3 64

/* computed macros */
#define BOARD_NUM_CELLS (BOARD_LENGTH * BOARD_LENGTH)
#define BOARD_TOTAL_DIAGS (BOARD_LENGTH + BOARD_LENGTH - 1)
#define BOARD_NUM_DIAGONALS ((BOARD_LENGTH - WINNING_SEQ_LENGTH) * 2 + 1)
#define BOARD_NUM_SEQS (2 * BOARD_LENGTH + 2 * BOARD_NUM_DIAGONALS)
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
    NO_PLAYER = 0,
    PLAYER_1 = 1,
    PLAYER_2 = 2
} player_t;

typedef int cell_rating_t;

#endif /* COMMON_H_ */
