
/*
  Stack
*/

#ifndef __STACK_H__
#define __STACK_H__

#include <buffer.h>

void push(_postfixT c);
void pop(_postfixT *p);
_postfixT top(void);
int empty(void);
void initStack(void);

#endif

