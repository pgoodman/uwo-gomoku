/*
 * threat.h
 *
 *  Created on: Oct 27, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef THREAT_H_
#define THREAT_H_

#include <stdlib.h>
#include <math.h>

#include "common.h"
#include "board.h"
#include "board-cell-seq.h"

void calculate_threats(board_t *board, const player_t player_id);

void add_threat(board_t *board,
                board_cell_t *cell,
                const player_t player_id,
                const player_t add_player_id);

void remove_threat(board_t *board,
                   board_cell_t *cell,
                   const player_t player_id);

#endif /* THREAT_H_ */
