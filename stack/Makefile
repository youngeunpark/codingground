
include ../mkdefs

default : libstack.a stack

clean :
	rm -rf *.o *.a stack

libstack.a : stack.C
	$(CC) $(CLIBFLAGS) -o $@ $^ \
	$(CINCLUDE)

stack : stack.c stackInt.c stackString.c stackStruct.c
	$(CC) $(CFLAGS) -o $@ \
	$^ \
	$(CINCLUDE)

doxygen:
	doxygen *.c *.h *.C *.H

all: libstack.a stack doxygen

