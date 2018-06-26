
include ../mkdefs

default : libstack.a stack stackCpp

clean :
	rm -rf *.o *.a stack stackCpp

libstack.a : stack.C
	$(CPP) $(CLIBFLAGS) -o $@ $^ \
	$(CINCLUDE)

stack : stack.c stackInt.c stackString.c stackStruct.c
	$(CC) $(CFLAGS) -o $@ \
	$^ \
	$(CINCLUDE)

stackCpp : main.C stack.C
	$(CPP) $(CFLAGS) -o $@ \
	$^ \
	$(CINCLUDE) \
	$(LINCLUDE) \
	-lsymbol

splint: stack.C main.C
	splint $(CFLAGS_SPLINT) stack.C main.C
	$(CINCLUDE)

cppcheck: stack.C main.C
	cppcheck --enable=all $(CFLAGS_SPLINT) stack.C main.C

doxygen:
	doxygen *.c *.h *.C *.H

all: libstack.a stack doxygen

