/**
    @file stack.C
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ Stack implementation for symbols
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stack.H>

using namespace std;

/**
    @return
    NONE

    @param
    size: the size of stack
*/
void Stack::initStack(int size)
{
    if(size <= 0) {
        cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
        cout << " invalid size(" << size << ")" << endl;
        return;
    }
    stack = (symbolT *)malloc(sizeof(symbolT) * size);
    if(!stack) {
        cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
        cout << " malloc failed" << endl;
        return;
    }

    sp = -1;
    this->size = size;
    memset(stack, 0x0, sizeof(symbolT) * size);
}

/**
    @return
    NONE

    @param
    NONE
*/
Stack::Stack(void)
{
    initStack(MAX_STACK_SIZE);

    // Note that
    // calling another constructor like below creates 2 different instances
    // Stack(MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    size : the size of stack
*/
Stack::Stack(int size)
{
    initStack(size);
}

/**
    @return
    NONE

    @param
    NONE
*/
Stack::~Stack(void)
{
    free(stack);
}

/**
    @return
    NONE

    @param
    c : symbol to push onto stack
*/
void Stack::push(symbolT c)
{
    if (!full())
        stack[++sp] = c;
}

/**
    @return
    NONE

    @param
    p : pointer of symbol to return the symbol on stack top
*/
void Stack::pop(symbolT * p)
{
    if (!empty())
        *p = stack[sp--];
}

/**
    @return
    symbol on stack top

    @param
    NONE
*/
symbolT Stack::top(void)
{
    if (!empty())
        return stack[sp];
}

/**
    @return
    1, if stack is empty\n
    0, otherwise

    @param
    NONE
*/
int Stack::empty(void)
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
int Stack::full(void)
{
    return (sp == (MAX_STRING - 1));
}

