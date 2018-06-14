
CC = gcc
CPP = g++
CFLAGS = -I. -g -Werror #-DDEBUG

default: calculator calculatorCpp

calculator: main.c calculator.c buffer.c convert.c stack.c
	$(CC) $(CFLAGS) -o $@ $^

calculatorCpp: main.cpp stack.cpp
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	rm -rf calculator calculatorCpp *.o

doxygen:
	doxygen *.c *.h

all: calculator calculatorCpp doxygen
