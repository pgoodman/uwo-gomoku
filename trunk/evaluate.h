/*
 * evaluate.h
 *
 *  Created on: Oct 25, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */
#if 0
#ifndef EVALUATE_H_
#define EVALUATE_H_

/* score type, used to order successors. */
#define S_NONE 0

/* _ X _ X _ X _
 * X _ X _ X _ ?
 * _ X _ X _ X ? */
#define S_SPARSE_THREAT 1<<1

/* _ X _ X X _
 * _ X X _ X _ */
#define S_SPLIT_OUTER_THREAT 1<<2

/* _ X X X _ ?
 * _ X X X _ _
 * _ _ X X X _
 * _ _ X X X ?
 * X X X _ _ ? */
#define S_OUTER_THREAT 1<<3

/* X _ X X X
 * X X _ X X
 * X X X _ X */
#define S_SPLIT_THREAT 1<<6

/* _ X X X X
 * X X X X _ */
#define S_STRAIGHT_THREAT 1<<6

/* Y _ Y Y Y
 * Y Y _ Y Y
 * Y Y Y _ Y */
#define S_SPLIT_WIN 1<<8

/* _ Y Y Y Y
 * Y Y Y Y _ */
#define S_STRAIGHT_WIN 1<<8

typedef char score_t;
#endif

#endif /* EVALUATE_H_ */
