# 
# CS3346a, Assignment 2, Five in a Row
# Peter Goodman
#

CC = gcc
CFLAGS = -O2 -g -pedantic -pedantic-errors -Wall -Werror -c -ansi
OBJ_FILE = fiveinarow

OBJS = ./main.o ./context.o ./board.o

all: ${OBJ_FILE}

${OBJ_FILE}: ${OBJS}
	${CC} -o $@ ${OBJS}

%.o: ../%.c
	${CC} $^ $(CFLAGS)

clean:
	-rm *.o

realclean: clean
	-rm ${OBJ_FILE}
