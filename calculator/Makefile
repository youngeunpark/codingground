
CC = gcc
CPP = g++
CFLAGS = -I. -g -Werror #-DDEBUG

default: calculator calculatorCpp

calculator: main.c calculator.c buffer.c convert.c stack.c
	$(CC) $(CFLAGS) -o $@ $^

calculatorCpp: main.C calculator.C buffer.C convert.C stack.C
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	rm -rf calculator calculatorCpp *.o

doxygen:
	doxygen *.c *.h *.C *.H

all: calculator calculatorCpp doxygen
