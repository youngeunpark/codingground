
CC = gcc
CFLAGS = -I. -g #-DDEBUG

all: calculator

clean:
	rm -rf calculator *.o

calculator: main.c calculator.c buffer.c convert.c stack.c
	$(CC) $(CFLAGS) -o $@ $^

