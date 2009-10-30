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

#if 0
#define NUM_PATCH_CELLS ((LOCAL_SPACE * 4) * (LOCAL_SPACE + 1) + 2) /* + 1 trailing dummy */

typedef struct {
    int threat_rating;
    board_cell_t *cell;
} threat_cell_patch_t;

typedef struct {
    threat_cell_patch_t changes[NUM_PATCH_CELLS];
    board_cell_t *cell;
} threat_space_patch_t;
#endif

void calculate_threats(local_space_t *local_space);

void add_threat(local_space_t *local_space,
                board_cell_t *cell,
                const player_t add_player_id);

void remove_threat(local_space_t *local_space,
                   board_cell_t *cell);

#endif /* THREAT_H_ */
