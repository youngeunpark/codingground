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
    postfix = (symbolT *)malloc(sizeof(symbolT) * size);
    if(!postfix) {
        cout << "Oops, postfix malloc failed" << endl;
        return;
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
    allocBuffers(MAX_STRING);
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
    free(postfix);
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
    memset(postfix, 0x0, sizeof(symbolT) * size);
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
            printf("ERROR [%s:%d] errno(%d)\n", __FILE__, __LINE__, errno);
        }
        return -1;
    }

    // expression is comment starting with #
    if(infix[0] == '#') {
#ifdef DEBUG
        printf("Skip comment, %s", infix);
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
    printf("infix: ");
    printf("%s\n", infix);
}

/**
    @return
    Pointer to postfix buffer

    @param
    NONE
*/
symbolT *Buffer::getPostfixBuffer(void)
{
    return postfix;
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

    printf("postfix:\n");

    while (!(IsTerminator(postfix[idx]) || IsNone(postfix[idx]))) {
        if (IsOperator(postfix[idx])) {
            printf("[%d] %c\n", idx, (char)postfix[idx].val);
        } else if (IsOperand(postfix[idx])) {
            printf("[%d] %d\n", idx, postfix[idx].val);
        }
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
    if (IsOperator(s)) {
        printf("%c\n", (char)s.val);
    } else if (IsOperand(s)) {
        printf("%d\n", s.val);
    }
}

