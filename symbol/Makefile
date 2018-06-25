
CPP = g++
CFLAGS = -I. -g -c -Werror#-DDEBUG

default : libsymbol.a

clean :
	rm -rf symbol *.o *.a

libsymbol.a : symbol.C
	$(CPP) $(CFLAGS) -o $@ $^

doxygen:
	doxygen *.C *.H

all: libsymbol.a doxygen

