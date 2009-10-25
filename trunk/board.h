/*
 * parse.h
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "common.h"

typedef enum {
    CELL_EMPTY = 0,
    CELL_PLAYER1 = 1,
    CELL_PLAYER2 = 2
} board_cell_t;

int read_board(board_cell_t[BOARD_HEIGHT][BOARD_WIDTH]);
int put_board(board_cell_t[BOARD_HEIGHT][BOARD_WIDTH]);

#endif /* BOARD_H_ */
