/*
 * evaluate.h
 *
 *  Created on: Oct 29, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef EVALUATE_H_
#define EVALUATE_H_

#include <limits.h>
#include <math.h>

#include "common.h"
#include "board.h"

int minmax_evaluate(board_t *board,
                    const player_t max_player_id,
                    const player_t curr_player_id,
                    const player_t winner_id,
                    int *num_wins,
                    int *num_losses);

void yield_best_move(board_cell_t **cell, const player_t player_id);

#endif /* EVALUATE_H_ */
