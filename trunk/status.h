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
#include "threat.h"

extern game_status_t local_status(board_t *board, board_cell_t *cell);

game_status_t global_status(board_t *board, const player_t player_id);

#endif /* TERMINAL_H_ */
