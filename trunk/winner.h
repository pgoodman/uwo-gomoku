/*
 * winner.h
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "common.h"
#include "board.h"
#include "localspace.h"

player_t global_winner(board_t *board);
player_t local_winner(local_space_t *local_space, const board_cell_t *cell);

#endif /* TERMINAL_H_ */
