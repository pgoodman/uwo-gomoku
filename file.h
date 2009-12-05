/*
 * file.h
 *
 *  Created on: Oct 31, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef FILE_H_
#define FILE_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_PUT_CHMOD 0654

int file_get_contents(const char *name,
                      char *buffer,
                      const size_t min_len,
                      const size_t max_len);

int file_put_contents(const char *name, char *buffer, const size_t len);

#define file_delete remove

#endif /* FILE_H_ */
