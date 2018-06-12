
CC = gcc
CFLAGS = -I. -g -Werror #-DDEBUG

default: calculator

calculator: main.c calculator.c buffer.c convert.c stack.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf calculator *.o

doxygen:
	doxygen *.c *.h

all: calculator doxygen
