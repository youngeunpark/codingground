
include ../mkdefs

default : libbuffer.a

clean :
	rm -rf *.o *.a

libbuffer.a : buffer.C
	$(CC) $(CLIBFLAGS) -o $@ $^ \
	$(CINCLUDE)

doxygen:
	doxygen *.c *.h *.C *.H

all: libbuffer.a doxygen

