/*
 * parse.c
 *
 *  Created on: Oct 24, 2009
 *      Author: petergoodman
 *     Version: $Id$
 */

#include "board.h"

#define BOARD_CELLS BOARD_WIDTH * BOARD_HEIGHT
#define BOARD_MIN_BUFFER_SIZE BOARD_CELLS * 2
#define BOARD_BUFFER_SIZE (BOARD_MIN_BUFFER_SIZE + 2 * BOARD_HEIGHT)

#ifndef O_BINARY
#define O_BINARY 0
#endif

/**
 * Quickly read in the board from memory. This goes straight to file descriptors
 * instead of file pointers to avoid needlessly passing the board from buffer to
 * buffer.
 */
int read_board(board_cell_t cells2[BOARD_HEIGHT][BOARD_WIDTH]) {
    int fd;
    ssize_t got;
    int i;
    int j;
    board_cell_t *cells = (board_cell_t *) cells2;
    char buffer[BOARD_BUFFER_SIZE];

    /* open the file */
    fd = open(BOARD_DIR BOARD_FILE, O_RDONLY | O_BINARY);
    if(-1 == fd) {
        return 0;
    }

    /* get the game board, include any possible \n's or \r's and spaces. */
    got = read(fd, buffer, BOARD_BUFFER_SIZE * sizeof(char));
    if(got <= 0) {
        return 0;
    }

    close(fd);

    /* fill the actual board with the right values */
    for(i = 0, j = -1; i < got && j < BOARD_CELLS; ++i) {
        switch(buffer[i]) {
            case '0':
                cells[++j] = CELL_EMPTY;
                break;
            case '1':
                cells[++j] = CELL_PLAYER1;
                break;
            case '2':
                cells[++j] = CELL_PLAYER2;
                break;
        }
    }

    return 1;
}

/**
 * Output the board back into the board file.
 */
int put_board(board_cell_t cells[BOARD_HEIGHT][BOARD_WIDTH]) {
    int i;
    int j;
    int k = -1;
    int fd;
    char buffer[BOARD_MIN_BUFFER_SIZE];
    ssize_t put;

    /* fill the buffer */
    for(i = 0; i < BOARD_HEIGHT; ++i) {
        for(j = 0; j < BOARD_WIDTH; ++j) {
            buffer[++k] = '0' + cells[i][j];
            buffer[++k] = ' ';
        }
        buffer[k] = '\n'; /* replaces trailing space on line */
    }

    /* open the file and directly transfer the buffer */
    fd = open(BOARD_DIR BOARD_FILE, O_TRUNC | O_CREAT | O_WRONLY);
    if(-1 == fd) {
        return 0;
    }

    put = write(fd, (char *) buffer, BOARD_MIN_BUFFER_SIZE * sizeof(char));
    if(put < BOARD_MIN_BUFFER_SIZE) {
        return 0;
    }

    close(fd);

    return 1;
}
