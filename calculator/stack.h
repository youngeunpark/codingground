/**
    @file stack.h
    @date 2018/06/10
    @author Youngeun Park
    @brief
    header file for stack implementation
*/

#ifndef __STACK_H__
#define __STACK_H__

#include <buffer.h>

/// Push symbol onto stack
void push(symbolT c);

/// Pop symbol from stack
void pop(symbolT * p);

/// Peek symbol on stack top
symbolT top(void);

/// Check if stack is empty
int empty(void);

/// Check if stack is full
int full(void);

/// Initialize stack
void initStack(void);

#endif
