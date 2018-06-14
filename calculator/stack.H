/**
    @file stack.H
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ header file for stack implementation
*/

#ifndef __STACK_H_CPP__
#define __STACK_H_CPP__

#include <buffer.H>

class Stack {
    private:

#define MAX_STACK_SIZE MAX_STRING

        /// Stack for symbols
        symbolT *stack;

        /// Stack pointer
        int sp;

        /// Stack size
        int size;

        /// Initialize stack
        void initStack(int size);

    public:

        /// Default constructor
        Stack(void);

        /// Constructor with stack size
        Stack(int size);

        /// Destructor
        ~Stack();

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
};

#endif

