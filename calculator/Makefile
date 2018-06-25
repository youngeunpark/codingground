
CC = gcc
CPP = g++
CFLAGS = -I. -g -Werror #-DDEBUG

default: calculator calculatorCpp

calculator: main.c calculator.c buffer.c convert.c stack.c
	$(CC) -o $@ \
	$(CFLAGS) \
	$^

calculatorCpp: main.C calculator.C buffer.C convert.C
	$(CPP) -o $@ \
	$(CFLAGS) \
	$^ \
	-lstack -lsymbol -L../stack -L../symbol

clean:
	rm -rf calculator calculatorCpp *.o

doxygen:
	doxygen *.c *.h *.C *.H

all: calculator calculatorCpp doxygen
