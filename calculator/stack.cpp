/**
    @file stack.cpp
    @date 2018/06/10
    @author Youngeun Park
    @brief
    C++ Stack implementation for symbols
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stack.hpp>

//using namespace std;

/**
    @return
    NONE

    @param
    NONE
*/
Stack::Stack(void)
{
    std::cout << "Stack::Stack" << std::endl;
    Stack(MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    size : the size of stack
*/
Stack::Stack(int size)
{
    std::cout << "Stack::Stack(size)" << std::endl;
    if(size <= 0) {
        std::cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
        std::cout << " invalid size(" << size << ")" << std::endl;
        return;
    }
    this->stack = (symbolT *)malloc(sizeof(symbolT) * size);
    if(!stack) {
        std::cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
        std::cout << " malloc failed" << std::endl;
        return;
    }

    this->size = size;
    initStack();
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
    std::cout << "size = " << this->size << std::endl;
    std::cout << "sp = " << this->sp << std::endl;
    std::cout << "stack = " << this->stack << std::endl;
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

/**
    @return
    NONE

    @param
    NONE
*/
void Stack::initStack(void)
{
    this->sp = -1;
    memset(stack, 0x0, sizeof(symbolT) * size);
}

