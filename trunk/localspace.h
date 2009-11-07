/*
 * localspace.h
 *
 *  Created on: Oct 30, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef LOCALSPACE_H_
#define LOCALSPACE_H_

#include <stdio.h>
#include "common.h"
#include "board.h"

void init_local_space(board_t *board, const player_t player_id);

player_t local_space_winner(board_cell_t *center_cell);

/*void update_local_space(board_cell_t *centre_cell, const int mult);*/

#endif /* LOCALSPACE_H_ */
