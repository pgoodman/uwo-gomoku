# 
# CS3346a, Assignment 2, Five in a Row
# Peter Goodman
#

CC = /Developer/usr/bin/clang
CFLAGS = -O0 -g -pedantic -pedantic-errors -Wall -Werror -c -ansi
OBJ_FILE = fiveinarow

INCLUDES = 
OBJS = ./main.o ./board.o ./successors.o ./file.o ./rate.o \
       ./seq.o ./match.o ./move.o ./md5.o ./player1.o ./player2.o

all: ${OBJ_FILE}

clean:
	-rm *.o

realclean: clean
	-rm ./${OBJ_FILE}
	
# compile the project
${OBJ_FILE}: ${OBJS} ${EXT_OBJS}
	${CC} ${INCLUDES} -lm -o $@ ${OBJS}
	
# base objects
%.o: ../%.c
	${CC} ${INCLUDES} $^ $(CFLAGS)

# library objects
%.o: ../md5/%.c
	${CC} ${INCLUDES} $^ $(CFLAGS)
%.o: ../insight/%.c
	${CC} ${INCLUDES} $^ $(CFLAGS)