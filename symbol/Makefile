include ../mkdefs

default : libsymbol.a

clean:
	rm -rf symbol *.o *.a

libsymbol.a : symbol.C
	$(CPP) $(CLIBFLAGS) -o $@ $^ \
	$(CINCLUDE)

doxygen:
	doxygen *.C *.H

all: libsymbol.a doxygen

