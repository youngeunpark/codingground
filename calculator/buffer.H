/**
    @file buffer.H
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ Header file for buffer management
*/

#ifndef __BUFFER_CPP_H__
#define __BUFFER_CPP_H__

#include <../symbol/symbol.H>

/// class Buffer
class Buffer {
    private:

    /// infix buffer
    char *infix;

    /// buffer size
    int size;

    /// postfix buffer
    symbolT **postfix;

    /// Allocate infix & postfix buffer and fill them by 0x0
    void allocBuffers(int size);

    public:

    /// Default constructor
    Buffer();

    /// Constructor
    Buffer(int size);

    /// Destructor
    ~Buffer();

    /// Fill infix & postfix buffers with 0x0
    void initializeBuffers(void);

    /// Read infix expression via standard input
    int getInfixExpression(void);

    /// Return infix buffer
    char *getInfixBuffer(void);

    /// Print infix buffer
    void printInfixBuffer(void);

    /// Return postfix buffer
    symbolT **getPostfixBuffer(void);

    /// Return size of buffer
    int getSize(void);

    /// Print postfix buffer
    void printPostfixBuffer(void);

    // Print a symbol of symbolT
    void printPostfixSymbol(symbolT s);
};

#endif

