/*
 * move.h
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef MOVE_H_
#define MOVE_H_

#include <math.h>

#include "common.h"
#include "board.h"
#include "rate.h"
#include "match.h"
#include "seq.h"
#include "successors.h"
#include "time.h"

/* related to learning */
#include "insight/player1.h"
#include "insight/player2.h"

board_cell_t *choose_move(board_t *board,
                          const player_t player_id,
                          const player_t opponent_id);

#endif /* MOVE_H_ */
