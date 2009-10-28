/*
 * context.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "context.h"

static jmp_buf *orig_context = NULL;

/**
 * Switch contexts when the first context is interrupted.
 */
static void switch_context_on_signal(int sig) {
    if(NULL != orig_context && SIGALRM == sig) {
        longjmp(*orig_context, 0);
    }
}

/**
 * Manually switch the context if we are before the signal. Note that
 * shared_context->in_new_context is used as opposed to switched_context as
 * for some reason someone might have called switch_context_after twice.
 */
void yield(void) {
    raise(SIGALRM);
}

/**
 * Perform a single line of computation for no more than approximately
 * num_seconds. This provides the func a pointer to return its data in.
 */
void timed_computation(timed_func_t *func,
                       void *computed_data,
                       unsigned int num_seconds) {

    jmp_buf context;

    /* if we are currently in a timed context then make sure we don't begin
     * another one that might step over it. */
    if(NULL != orig_context) {
        raise(SIGABRT);
    }

    orig_context = &context;

    /* set the max search time */
    if(num_seconds) {
        if(num_seconds < UINT_MAX) {
            signal(SIGALRM, &switch_context_on_signal);
            alarm(num_seconds);
        }

        /* begin the computation */
        if(!setjmp(context)) {
            func(computed_data);

        /* notify that we are no longer in a context that can be jumped out
         * of. */
        } else {
            orig_context = NULL;
        }
    }
}
