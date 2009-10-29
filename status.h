/*
 * status.h
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "common.h"
#include "board.h"

typedef enum {
    GAME_WON,
    GAME_LOST,
    GAME_DRAW,
    GAME_PLAY
} game_status_t;

game_status_t game_status(board_t *board, const player_t player_id);

#endif /* TERMINAL_H_ */
