/**
    @file stack.C
    @date 2018/06/21
    @author Youngeun Park
    @brief
    C++ Stack implementation for some types
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stack.H>

using namespace std;

#define ERROR_FILE_LINE() \
{ \
    cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" << endl; \
}

/**
    @return
    NONE

    @param
    v: initial value to fill in stack
    size: the size of stack
*/
void Stack::initStack(symbolT v, size_t size)
{
    stack = (symbolT *)malloc(sizeof(v) * size);
    if(!stack) {
        ERROR_FILE_LINE();
        cout << " malloc failed" << endl;
        return;
    }

    sp = -1;
    this->size = size;
    type = STACK_TYPE_SYMBOL;
    for (int i = 0; i < size; i++) {
        ((symbolT *)stack)[i] = v;
    }
}

/**
    @return
    NONE

    @param
    v: initial value to fill in stack
    size: the size of stack
*/
void Stack::initStack(int v, size_t size)
{
    stack = (int *)malloc(sizeof(v) * size);
    if(!stack) {
        ERROR_FILE_LINE();
        cout << " malloc failed" << endl;
        return;
    }

    sp = -1;
    this->size = size;
    type = STACK_TYPE_INT;
    memset(stack, v, sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        ((int *)stack)[i] = v;
    }
}

/**
    @return
    NONE

    @param
    v: initial value to fill in stack
    size: the size of stack
*/
void Stack::initStack(char v, size_t size)
{
    stack = (char *)malloc(sizeof(v) * size);
    if(!stack) {
        ERROR_FILE_LINE();
        cout << " malloc failed" << endl;
        return;
    }

    sp = -1;
    this->size = size;
    type = STACK_TYPE_CHAR;
    for (int i = 0; i < size; i++) {
        ((char *)stack)[i] = v;
    }
}

/**
    @return
    NONE

    @param
    v: initial value to fill in stack. pointer to point string
    size: the size of stack
*/
void Stack::initStack(const char *v, size_t size)
{
    stack = (void *)malloc(sizeof(v) * size);
    if(!stack) {
        ERROR_FILE_LINE();
        cout << " malloc failed" << endl;
        return;
    }

    sp = -1;
    this->size = size;
    type = STACK_TYPE_STRING;
    for (int i = 0; i < size; i++) {
        ((char **)stack)[i] = (char *)v;
    }
}

/**
    @return
    NONE

    @param
    NONE
*/
Stack::Stack(void)
{
    initStack(0, MAX_STACK_SIZE);

    // Note that
    // calling another constructor like below creates 2 different instances
    // Stack(MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack
*/
Stack::Stack(symbolT v)
{
    initStack(v, MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack
*/
Stack::Stack(int v)
{
    initStack(v, MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack
*/
Stack::Stack(char v)
{
    initStack(v, MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack. pointer to point string
*/
Stack::Stack(const char *v)
{
    initStack(v, MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack
    size : the size of stack
*/
Stack::Stack(symbolT v, int size)
{
    initStack(v, size);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack
    size : the size of stack
*/
Stack::Stack(int v, int size)
{
    initStack(v, size);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack
    size : the size of stack
*/
Stack::Stack(char v, int size)
{
    initStack(v, size);
}

/**
    @return
    NONE

    @param
    v: value to initialize stack. pointer to point string
    size : the size of stack
*/
Stack::Stack(const char *v, int size)
{
    initStack(v, size);
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
    1 on success\n
    0 on failure

    @param
    c : symbol to push onto stack
*/
int Stack::push(symbolT c)
{
    if (!full()) {
        ((symbolT *)stack)[++sp] = c;
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    c : value to push onto stack
*/
int Stack::push(int i)
{
    if (!full()) {
        ((int *)stack)[++sp] = i;
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    c : value to push onto stack
*/
int Stack::push(char c)
{
    if (!full()) {
        ((char *)stack)[++sp] = c;
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    c : value to push onto stack. pointer to point string
*/
int Stack::push(const char *c)
{
    if (!full()) {
        ((char **)stack)[++sp] = (char *)c;
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    p : pointer of symbol to return the symbol on stack top
*/
int Stack::pop(symbolT *p)
{
    if (!empty()) {
        *p = ((symbolT *)stack)[sp--];
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    i : pointer of value to return the value on stack top
*/
int Stack::pop(int *i)
{
    if (!empty()) {
        *i = ((int *)stack)[sp--];
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    c : pointer of value to return the value on stack top
*/
int Stack::pop(char *c)
{
    if (!empty()) {
        *c = ((char *)stack)[sp--];
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    c : pointer of value to return the value on stack top
*/
int Stack::pop(char **c)
{
    if (!empty()) {
        *c = ((char **)stack)[sp--];
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    p : pointer of symbol to return the symbol on stack top
*/
int Stack::top(symbolT *p)
{
    if (!empty()) {
        *p = ((symbolT *)stack)[sp];
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    i : pointer of value to return the value on stack top
*/
int Stack::top(int *i)
{
    if (!empty()) {
        *i = ((int *)stack)[sp];
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    c : pointer of value to return the value on stack top
*/
int Stack::top(char *c)
{
    if (!empty()) {
        *c = ((char *)stack)[sp];
        return 1;
    }

    return 0;
}

/**
    @return
    1 on success\n
    0 on failure

    @param
    c : pointer of value to return the value on stack top
*/
int Stack::top(char **c)
{
    if (!empty()) {
        *c = ((char **)stack)[sp];
        return 1;
    }

    return 0;
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
    return (sp == (size - 1));
}

/**
    @return
    Data type of stack

    @param
    NONE
*/
int Stack::getType(void)
{
    return type;
}

/**
    @return
    NONE

    @param
    NONE
*/
void Stack::print(void)
{
    int _sp = sp;

    cout << "Stack type(";
    switch (getType()) {
        case STACK_TYPE_SYMBOL:
            cout << "Symbol";
        break;

        case STACK_TYPE_INT:
            cout << "Int";
        break;

        case STACK_TYPE_CHAR:
            cout << "Char";
        break;

        case STACK_TYPE_STRING:
            cout << "String";
        break;

        default:
            cout << "None";
        break;
    }
    cout << ")";
    cout << " size("<< size << ")";
    cout << " pointer(" << _sp << ")" <<endl;

    while(_sp >= 0) {
        cout << "[" << _sp << "] " ;
        if(type == STACK_TYPE_SYMBOL)
            cout << ((symbolT *)stack)[_sp--] << endl;
        else if(type == STACK_TYPE_INT)
            cout << ((int *)stack)[_sp--] << endl;
        else if(type == STACK_TYPE_CHAR)
            cout << ((char *)stack)[_sp--] << endl;
        else if(type == STACK_TYPE_STRING)
            cout << ((char **)stack)[_sp--] << endl;
    }

    cout << endl;
}

