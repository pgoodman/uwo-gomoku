/*
 * move.h
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef MOVE_H_
#define MOVE_H_

#include "common.h"
#include "board.h"
#include "rate.h"
#include "match.h"
#include "seq.h"
#include "successors.h"

board_cell_t *make_move(board_t *board,
                        const player_t player_id,
                        const player_t opponent_id,
                        player_t *winner_id);

#endif /* MOVE_H_ */
