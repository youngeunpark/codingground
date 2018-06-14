
CC = gcc
CFLAGS = -I. -g -Werror #-DDEBUG

default: anagram

anagram: main.c anagram.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf anagram *.o

doxygen:
	doxygen *.c *.h

all: anagram doxygen
