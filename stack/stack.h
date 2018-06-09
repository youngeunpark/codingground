
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef __STACK_H__
#define __STACK_H__

// Default stack size. It can be set by program 1st argument
#define MAX_STACK_SIZE 100
#define LIMIT_STACK_SIZE 1000

// Stack pointer
// If MAX, stack is empty. If 0, then full.
extern int stackSize;
extern int top;

// Stack for any type of data (array of void *).
extern void **stack;

// Return 1 if empty, 0 otherwise
int IsEmpty(void);

// Return 1 if full, 0 otherwise
int IsFull(void);

#endif