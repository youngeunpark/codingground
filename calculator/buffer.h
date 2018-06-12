/**
    @file buffer.h
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Header file for buffer management
*/

#ifndef __BUFFER_H__
#define __BUFFER_H__

#define MAX_STRING 1001

#define _NONE_ 0
#define _OPERAND_ 1
#define _OPERATOR_ 2
#define _PARENTHESIS_ 3
#define _TERMINATOR_ 4

typedef struct {
    unsigned char type; ///< indicator (operand or operator)
    int val; ///< parsed integer value or operator
} symbolT;

#define IsNone(a) (a.type == _NONE_)
#define IsOperand(a) (a.type == _OPERAND_)
#define IsOperator(a) (a.type == _OPERATOR_)
#define IsParenthesis(a) (a.type == _PARENTHESIS_)
#define IsTerminator(a) (a.type == _TERMINATOR_)

/// Initialize infix & postfix buffers by filling 0x0
void initializeBuffers(void);

/// Read infix expression via standard input
int getInfixExpression(void);

/// Return infix buffer
char *getInfixBuffer(void);

/// Print infix buffer
void printInfixBuffer(void);

/// Return postfix buffer
symbolT *getPostfixBuffer(void);

/// Print postfix buffer
void printPostfixBuffer(void);

// Print a symbol of symbolT
void printPostfixSymbol(symbolT s);

#endif

