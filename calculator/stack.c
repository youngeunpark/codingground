/**
    @file stack.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    stack.c
*/

#include <string.h>
#include <stack.h>

static symbolT stack[MAX_STRING];
static int sp = -1;

void push(symbolT c)
{
    stack[++sp] = c;
}

void pop(symbolT * p)
{
    *p = stack[sp--];
}

symbolT top(void)
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
