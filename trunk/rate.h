/*
 * rate.h
 *
 *  Created on: Nov 12, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef RATING_H_
#define RATING_H_

#include "common.h"
#include "board.h"
#include "seq.h"
#include "match.h"

void init_ratings(board_t *board);

void rate_pivoted_seqs(board_cell_t *pivot_cell);
void unrate_pivoted_seqs(board_cell_t *pivot_cell);

#endif /* RATING_H_ */
