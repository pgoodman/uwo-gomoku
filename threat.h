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
#include "localspace.h"

void calculate_threats(local_space_t *local_space, const player_t player_id);

void add_threat(local_space_t *local_space,
                board_cell_t *cell,
                const player_t player_id);

void remove_threat(local_space_t *local_space,
                   board_cell_t *cell,
                   const player_t player_id);

#endif /* THREAT_H_ */
