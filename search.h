/*
 * search.h
 *
 *  Created on: Nov 4, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef SEARCH_H_
#define SEARCH_H_

#include <limits.h>

#include "common.h"
#include "board.h"
#include "localspace.h"
#include "successors.h"
#include "evaluate.h"

int search_for_move(board_t *board,
                    board_cell_t *cell,
                    const player_t max_player_id,
                    int *win_diff);

#endif /* SEARCH_H_ */
