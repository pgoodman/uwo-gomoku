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
#define MAX_SEARCH_DEPTH 10 /* depth-limited alpha-beta search */
#define MAX_SUCCESSORS_TO_SEARCH 10 /* integrated with beam search */

#define WINNING_SEQ_LENGTH 5

#define BOARD_LENGTH 15 /* default board width/height */
#define BOARD_DIR "./"
#define BOARD_FILE "board.txt" /* default location of board file */

/* other */
#define SEARCH_BOUNDS 1 /* extends the bounding box to look for successors */
#define THREAT 1
#define BENEFIT 1
#define THREAT_EXPONENT 3.0
#define BENEFIT_EXPONENT 2.0
#define DEFAULT_THREAT 1
#define DEFAULT_BENEFIT 0

/* computed macros */
#define BOARD_NUM_CELLS BOARD_LENGTH * BOARD_LENGTH
#define BOARD_NUM_DIAGONALS (BOARD_LENGTH - WINNING_SEQ_LENGTH) * 2 + 1
#define BOARD_CENTER ((int) (BOARD_LENGTH / 2))
#define BOARD_MIN_BUFFER_SIZE BOARD_NUM_CELLS * 2
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
    PLAYER_1 = 1,
    PLAYER_2 = 2
} player_t;

typedef short threat_rating_t;

#endif /* COMMON_H_ */
