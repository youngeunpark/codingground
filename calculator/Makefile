
include ../mkdefs

default: calculator calculatorCpp

calculator: main.c calculator.c buffer.c convert.c stack.c
	$(CC) -o $@ \
	$(CFLAGS) \
	$^ \
	$(CINCLUDE)

calculatorCpp: main.C calculator.C
	$(CPP) -o $@ \
	$(CFLAGS) \
	$^ \
	$(CINCLUDE) \
	$(LINCLUDE) \
	-lstack -lsymbol -lconvert -lbuffer

clean:
	rm -rf calculator calculatorCpp *.o

doxygen:
	doxygen *.c *.h *.C *.H

all: calculator calculatorCpp doxygen
