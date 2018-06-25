/**
    @file buffer.C
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ Implementation for buffer management
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <buffer.H>
#include <../stack/stack.H>
#include <../symbol/symbol.H>

using namespace std;

/**
    @return
    NONE

    @param
    size: size of buffer
*/
void Buffer::allocBuffers(int size)
{
    infix = (char *)malloc((size_t)size);
    if(!infix) {
        cout << "Oops, infix malloc failed" << endl;
        return;
    }

    postfix = (symbolT **)malloc(sizeof(symbolT *) * size);
    if(!postfix) {
        cout << "Oops, postfix malloc1 failed" << endl;
        return;
    }
    for(int i = 0; i < size; i++) {
        postfix[i] = new symbolT();
    }

    this->size = size;
    initializeBuffers();
}

/**
    @return
    NONE

    @param
    NONE
*/
Buffer::Buffer()
{
    allocBuffers(MAX_STACK_SIZE);
}

/**
    @return
    NONE

    @param
    size: size of buffer
*/
Buffer::Buffer(int size)
{
    if(size <= 0) {
        cout << "Oops, invalid size " << size << endl;
        return;
    }
    allocBuffers(size);
}

/**
    @return
    NONE

    @param
    NONE
*/
Buffer::~Buffer()
{
    free(infix);
    for(int i = 0; i < size; i++) {
        delete postfix[i];
    }
    delete postfix;
}

/**
    @return
    NONE

    @param
    size: size of buffer
*/
void Buffer::initializeBuffers(void)
{
    memset(infix, 0x0, (size_t)size);
    //memset(postfix, 0x0, sizeof(symbolT) * size);
}

/**
    @return
    On failure, -1 (actually, exits program)\n
    On encounting comment, 0\n
    On success, the length of expression ( greater than zero )

    @param
    NONE
*/
int Buffer::getInfixExpression(void)
{
    int len;

    if (fgets(infix, size - 1, stdin) == NULL) {
        if(errno == 0) {
            // Seems to encounter EOF
            exit(0);
        } else {
            // Something wrong happens
            cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
            cout << " errno(" << errno << ")" << endl;
        }
        return -1;
    }

    // expression is comment starting with #
    if(infix[0] == '#') {
#ifdef DEBUG
        cout << "Skip comment, " << infix ;
#endif
        return 0;
    }

    len = strlen(infix);

    // Remove newline from infix buffer
    if(infix[len - 1] == '\n') {
        infix[len - 1] = 0;
    }

    return len;
}

/**
    @return
    Pointer to infix buffer

    @param
    NONE
*/
char *Buffer::getInfixBuffer(void)
{
    return infix;
}

/**
    @return
    NONE

    @param
    NONE
*/
void Buffer::printInfixBuffer(void)
{
    cout << "infix: " << infix << endl ;
}

/**
    @return
    Pointer to postfix buffer

    @param
    NONE
*/
symbolT **Buffer::getPostfixBuffer(void)
{
    return postfix;
}

/**
    @return
    The size of buffer

    @param
    NONE
*/
int Buffer::getSize(void)
{
    return size;
}

/**
    @return
    NONE

    @param
    NONE
*/
void Buffer::printPostfixBuffer(void)
{
    int idx = 0;

    cout << "postfix:" << endl;

    while (!((postfix[idx]->IsTerminator()) || postfix[idx]->IsNone())) {
        cout << *postfix[idx];
        idx++;
    }
}

/**
    @return
    NONE

    @param
    s : symbol to print out
*/
void Buffer::printPostfixSymbol(symbolT s)
{
    if (s.IsOperator() || s.IsParenthesis()) {
        cout << (char)s.getVal() << endl;
    } else if (s.IsOperand()) {
        cout << s.getVal() << endl;
    }
}

