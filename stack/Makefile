
all : stack
clean :
	rm -rf stack *.o
stack : stack.c stackInt.c stackString.c
	cc -I. -o stack stack.c stackInt.c stackString.c stackStruct.c
