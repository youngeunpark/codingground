
CPP = g++
CFLAGS = -I. -g -Werror #-DDEBUG

all : symbol

clean :
	rm -rf symbol *.o

symbol : symbol.C
	$(CPP) $(CFLAGS) -o $@ $^

doxygen:
	doxygen *.c *.h *.C *.H

all: symbol doxygen

