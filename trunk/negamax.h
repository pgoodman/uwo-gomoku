/*
 * negamax.h
 *
 *  Created on: Nov 1, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef NEGAMAX_H_
#define NEGAMAX_H_

#include <stdio.h>

#include "common.h"
#include "board.h"
#include "localspace.h"
#include "successors.h"
#include "winner.h"
#include "threat.h"

int negamax(board_t *board,
            local_space_t *local_space,
            board_cell_t *prev_cell,
            board_cell_t **max_cell,
            player_t player_id,
            const int color,
            const int depth,
            const int num_empty_cells);

#endif /* NEGAMAX_H_ */
