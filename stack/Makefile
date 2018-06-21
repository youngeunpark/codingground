
CC = gcc
CPP = g++
CFLAGS = -I. -g -Werror #-DDEBUG

all : stack Stack

clean :
	rm -rf stack Stack *.o

stack : stack.c stackInt.c stackString.c stackStruct.c
	$(CC) $(CFLAGS) -o $@ $^

Stack : stack.C main.C
	$(CC) $(CFLAGS) -o $@ $^

doxygen:
	doxygen *.c *.h *.C *.H

all: stack Stack doxygen

