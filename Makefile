CC = g++
CXXFLAGS = -Wall -O2
OBJS = main.o set_avl.o

.PHONY: clean
clean:
		rm -f ${OBJS} main

set_avl.o: set_avl.h set_avl.cc
		${CC} ${CXXFLAGS} -c set_avl.cc

main.o: set_avl.h main.cc
		${CC} ${CXXFLAGS} -c main.cc

main: ${OBJS}
		${CC} ${CXXFLAGS} ${OBJS} -o main