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

/* X X X X X */
typedef void (match5_callback_t)(board_cell_t *c1,
                                 board_cell_t *c2,
                                 board_cell_t *c3,
                                 board_cell_t *c4,
                                 board_cell_t *c5);

/* _ X X X X _ */
typedef void (match4ext_callback_t)(board_cell_t *c1,
                                    board_cell_t *c2,
                                    board_cell_t *c3,
                                    board_cell_t *c4,
                                    board_cell_t *e1,
                                    board_cell_t *e2);

/* _ X X X X and X _ X X X and X X _ X X */
typedef void (match4_callback_t)(board_cell_t *c1,
                                 board_cell_t *c2,
                                 board_cell_t *c3,
                                 board_cell_t *c4,
                                 board_cell_t *e1);

/* _ X X X _ */
typedef void (match3_callback_t)(board_cell_t *c1,
                                 board_cell_t *c2,
                                 board_cell_t *c3,
                                 board_cell_t *e1,
                                 board_cell_t *e2);

/* _ X X X _ _ */
typedef void (match3ext_callback_t)(board_cell_t *c1,
                                    board_cell_t *c2,
                                    board_cell_t *c3,
                                    board_cell_t *e1,
                                    board_cell_t *e2,
                                    board_cell_t *e3);

/* callbacks for doing nothing on a specific match */
void match5_ignore(board_cell_t *c1,
                   board_cell_t *c2,
                   board_cell_t *c3,
                   board_cell_t *c4,
                   board_cell_t *c5);

void match4ext_ignore(board_cell_t *c1,
                      board_cell_t *c2,
                      board_cell_t *c3,
                      board_cell_t *c4,
                      board_cell_t *e1,
                      board_cell_t *e2);

void match4_ignore(board_cell_t *c1,
                   board_cell_t *c2,
                   board_cell_t *c3,
                   board_cell_t *c4,
                   board_cell_t *e1);

void match3_ignore(board_cell_t *c1,
                   board_cell_t *c2,
                   board_cell_t *c3,
                   board_cell_t *e1,
                   board_cell_t *e2);

void match3ext_ignore(board_cell_t *c1,
                      board_cell_t *c2,
                      board_cell_t *c3,
                      board_cell_t *e1,
                      board_cell_t *e2,
                      board_cell_t *e3);

/* main functons */
void init_matcher(match5_callback_t *match5_straight,
                  match4_callback_t *match4_straight,
                  match4_callback_t *match4_broken,
                  match4ext_callback_t *match4_ext,
                  match3_callback_t *match3_straight,
                  match3ext_callback_t *match3_broken,
                  match3ext_callback_t *match3_ext);

void match_seq(board_cell_t **cell);

void clear_matches(void);

int matched_win(const player_t player_id);

#endif /* MATCH_H_ */
