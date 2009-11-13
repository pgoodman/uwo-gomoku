/*
 * file.c
 *
 *  Created on: Oct 31, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef O_BINARY
#define O_BINARY 0
#endif

#include "file.h"

/**
 * Read at most max_len characters into buffer and at least min_len. Return 0
 * otherwise.
 */
int file_get_contents(const char *name,
                      char *buffer,
                      const size_t min_len,
                      const size_t max_len) {

    int fd = open(name, O_RDONLY | O_BINARY);
    ssize_t got;

    if(-1 == fd) {
        return 0;
    }

    /* get the game board, include any possible \n's or \r's and spaces. */
    got = read(fd, buffer, max_len);
    close(fd);

    if(got < (ssize_t) min_len) {
        return 0;
    }

    return 1;
}

/**
 * Write len characters from buffer to the file name. Returns 0 on failure.
 */
int file_put_contents(const char *name, char *buffer, const size_t len) {
    int fd;
    ssize_t put;

    fd = open(name, O_TRUNC | O_CREAT | O_WRONLY);
    if(-1 == fd) {
        return 0;
    }

    fchmod(fd, FILE_PUT_CHMOD);
    put = write(fd, buffer, len);
    close(fd);

    if(put < len) {
        return 0;
    }

    return 1;
}
