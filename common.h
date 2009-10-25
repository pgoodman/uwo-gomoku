/*
 * common
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef COMMON_H_
#define COMMON_H_

#define MAX_SEARCH_TIME 1 /* time limit for solution searching */
#define MAX_SEARCH_DEPTH 10 /* depth-limited alpha-beta search */
#define MAX_SUCCESSORS_TO_SEARCH 10 /* integrated with beam search */

#define BOARD_WIDTH 15 /* default board width */
#define BOARD_HEIGHT 15 /* default board height */
#define BOARD_DIR "./"
#define BOARD_FILE "board.txt" /* default location of board file */

#define SEARCH_BOUNDS 1 /* extends the bounding box to look for successors */

#define BOARD_NUM_CELLS BOARD_WIDTH * BOARD_HEIGHT

#define DIE(err) {fprintf(stderr, "%s", (err));exit(EXIT_FAILURE);}
#define PRINT(str) fprintf(stdout, "%s", (str));

typedef enum {
    PLAYER_1 = 1,
    PLAYER_2 = 2
} player_t;

#endif /* COMMON_H_ */
