
CC = gcc
CPP = g++
CFLAGS = -I. -g -Werror #-DDEBUG
CLIBFLAGS = -I. -g -Werror -c #-DDEBUG

default : stack libstack.a

clean :
	rm -rf stack Stack *.o *.a

stack : stack.c stackInt.c stackString.c stackStruct.c
	$(CC) $(CFLAGS) -o $@ $^

libstack.a : stack.C
	$(CC) $(CLIBFLAGS) -o $@ $^

doxygen:
	doxygen *.c *.h *.C *.H

all: stack stacklib.a doxygen

