
include ../mkdefs

default : libconvert.a

clean :
	rm -rf *.o *.a

libconvert.a : convert.C
	$(CC) $(CLIBFLAGS) -o $@ $^ \
	$(CINCLUDE)

doxygen:
	doxygen *.c *.h *.C *.H

all: convert doxygen

