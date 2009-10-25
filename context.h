/*
 * context.h
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <signal.h>
#include <setjmp.h>
#include <sys/time.h>
#include <limits.h>
#include <unistd.h>

typedef void (context_func_t)(void *);

void yield(void);

void timed_computation(context_func_t *func,
                       void *computed_data,
                       unsigned int num_seconds);

#endif /* CONTEXT_H_ */
