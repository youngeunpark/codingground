
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef __STACK_H__
#define __STACK_H__

// Default stack size. It can be set by program 1st argument
#define MAX_STACK_DEPTH_DEFAULT 100
#define LIMIT_OF_STACK_DEPTH 1000

// Stack pointer
// If MAX, stack is empty. If 0, then full.
extern int stackSize;
extern int top;

// Stack for any type of data (array of void *).
extern void **stack;

#endif