/**
    @file stack.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    stack.c
*/

#include <string.h>
#include <stack.h>

static _postfixT stack[MAX_STRING];
static int sp = -1;

void push(_postfixT c)
{
    stack[++sp] = c;
}

void pop(_postfixT * p)
{
    *p = stack[sp--];
}

_postfixT top(void)
{
    return stack[sp];
}

int empty(void)
{
    return (sp == -1);
}

void initStack(void)
{
    sp = -1;
    memset(stack, 0x0, sizeof(stack));
}
