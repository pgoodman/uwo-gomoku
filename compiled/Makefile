# 
# CS3346a, Assignment 2, Five in a Row
# Peter Goodman
#

CC = gcc
CFLAGS = -O2 -g -pedantic -pedantic-errors -Wall -Werror -c -ansi
OBJ_FILE = fiveinarow

INCLUDES = 
OBJS = ./main.o ./context.o ./board.o 
EXT_OBJS = ./ahocorasick.o

all: ${OBJ_FILE}

clean:
	-rm *.o

realclean: clean
	-rm ${OBJ_FILE}

# compile the project
${OBJ_FILE}: ${OBJS} ${EXT_OBJS}
	${CC} ${INCLUDES} -o $@ ${OBJS} ${EXT_OBJS}

# base objects
%.o: ../%.c
	${CC} ${INCLUDES} $^ $(CFLAGS)

# aho-corasick algorithm
%.o: ../ahocorasick/%.c
	${CC} ${INCLUDES} $^ $(CFLAGS)