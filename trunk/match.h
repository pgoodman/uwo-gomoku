/*
 * match.h
 *
 *  Created on: Nov 10, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef MATCH_H_
#define MATCH_H_

#include <stdio.h>
#include <string.h>

#include "common.h"
#include "board.h"

void match_seq(board_cell_t **cell,
               const int increment_mult,
               const int mark_the_chips);
int matched_win(void);

#endif /* MATCH_H_ */
