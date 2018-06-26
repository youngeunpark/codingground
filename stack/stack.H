/**
    @file stack.H
    @date 2018/06/21
    @author Youngeun Park
    @brief
    C++ header file of stack implementation for some types
*/

#ifndef __STACK_H_CPP__
#define __STACK_H_CPP__

#include <../symbol/symbol.H>

class Stack {
    private:

        /// Stack for symbols
        void *stack;

        /// Stack pointer
        int sp;

#define MAX_STACK_SIZE 100

        /// Stack size
        int size;

#define STACK_TYPE_SYMBOL   1
#define STACK_TYPE_INT      2
#define STACK_TYPE_CHAR     3
#define STACK_TYPE_STRING   4

        /// data type
        int type;

        /// Initialize stack
        void initStack(symbolT v, size_t size);
        void initStack(int v, size_t size);
        void initStack(char v, size_t size);
        void initStack(const char *v, size_t size);

    public:

        /// Constructors
        /// Default constructor
        Stack(void);

        /// Constructor for symbolT type with default stack size
        Stack(symbolT v);

        /// Constructor for int type with default stack size
        Stack(int v);

        /// Constructor for char type with default stack size
        Stack(char v);

        /// Constructor for string type with default stack size
        Stack(const char *v);

        /// Constructor for symbolT type with given stack size
        Stack(symbolT v, int size);

        /// Constructor for int type with given stack size
        Stack(int v, int size);

        /// Constructor for char type with given stack size
        Stack(char v, int size);

        /// Constructor for string type with given stack size
        Stack(const char *v, int size);

        /// Destructor
        ~Stack();

        /// push functions
        /// Push symbol onto stack for symbolT type
        int push(symbolT c);

        /// Push symbol onto stack for int type
        int push(int i);

        /// Push symbol onto stack for char type
        int push(char c);

        /// Push symbol onto stack for string type
        int push(const char *s);

        /// pop functions
        /// Pop symbol from stack for symbolT type
        int pop(symbolT *p);

        /// Pop symbol from stack for int type
        int pop(int *i);

        /// Pop symbol from stack for char type
        int pop(char *c);

        /// Pop symbol from stack for string type
        int pop(char **s);

        /// top functions
        /// Peek symbol on stack top for symbolT type
        int top(symbolT *p);

        /// Peek symbol on stack top for int type
        int top(int *i);

        /// Peek symbol on stack top for char type
        int top(char *c);

        /// Peek symbol on stack top for string type
        int top(char **s);

        /// Check if stack is empty
        int empty(void);

        /// Check if stack is full
        int full(void);

        /// Return data type of stack
        int getType(void);

        /// print function
        void print(void);
};

#endif

