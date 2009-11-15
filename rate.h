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

#define RATE_CHIPS 1
#define IGNORE_CHIPS 0

void init_ratings(board_t *board);
void clear_ratings(board_t *board);
void rate_pivoted_seqs(board_cell_t *pivot_cell, const int rate_chips);
void unrate_pivoted_seqs(board_cell_t *pivot_cell, const int rate_chips);

#endif /* RATING_H_ */
