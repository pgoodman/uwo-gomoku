# 
# CS3346a, Assignment 2, Five in a Row
# Peter Goodman
#

CC = gcc
CFLAGS = -O3 -g -pedantic -pedantic-errors -Wall -Werror -c -ansi
OBJ_FILE = fiveinarow

INCLUDES = 
OBJS = ./main.o ./board.o ./successors.o ./localspace.o ./file.o \
       ./evaluate.o ./search.o ./context.o

all: ${OBJ_FILE}

clean:
	-rm *.o

realclean: clean
	-rm ${OBJ_FILE}

# compile the project
${OBJ_FILE}: ${OBJS} ${EXT_OBJS}
	${CC} ${INCLUDES} -lm -o $@ ${OBJS}
	
# base objects
%.o: ../%.c
	${CC} ${INCLUDES} $^ $(CFLAGS)
