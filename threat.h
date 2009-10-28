/*
 * threat.h
 *
 *  Created on: Oct 27, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef THREAT_H_
#define THREAT_H_

#include <math.h>
#include "common.h"
#include "board.h"
#include "board-cell-seq.h"

/* type representing the changes made to the game board for any one choice of
 * move. */
typedef struct {

    struct {
        board_cell_t *cell; /* which cell changed */
        threat_rating_t change[2]; /* threat/benefit changes */
    } changes[(WINNING_SEQ_LENGTH - 1) * 8];

    player_t player_id;
    board_t *board;
    threat_rating_t threat_benefit[2];

} threat_patch_t;

void update_threats_with_seq(board_t *board, board_cell_seq_t *seq);
void compute_threat_ratings(board_t *board);

#endif /* THREAT_H_ */
