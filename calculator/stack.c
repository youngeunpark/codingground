/**
    @file stack.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Stack implementation for symbols
*/

#include <string.h>
#include <stack.h>

#define MAX_STACK_SIZE MAX_STRING

/// Stack for symbols
static symbolT stack[MAX_STACK_SIZE];

/// Stack pointer
static int sp = -1;

/**
    @return
    NONE

    @param
    c : symbol to push onto stack
*/
void push(symbolT c)
{
    if(!full())
        stack[++sp] = c;
}

/**
    @return
    NONE

    @param
    p : pointer of symbol to return the symbol on stack top
*/
void pop(symbolT * p)
{
    if(!empty())
        *p = stack[sp--];
}

/**
    @return
    symbol on stack top

    @param
    NONE
*/
symbolT top(void)
{
    if(!empty())
        return stack[sp];
}

/**
    @return
    1, if stack is empty\n
    0, otherwise

    @param
    NONE
*/
int empty(void)
{
    return (sp == -1);
}

/**
    @return
    1, if stack is empty\n
    0, otherwise

    @param
    NONE
*/
int full(void)
{
    return (sp == (MAX_STRING - 1));
}

/**
    @return
    NONE

    @param
    NONE
*/
void initStack(void)
{
    sp = -1;
    memset(stack, 0x0, sizeof(stack));
}

