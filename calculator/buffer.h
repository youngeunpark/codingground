/**
    @file buffer.h
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Struct and function for buffer management
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
    unsigned char _operator; ///< indicator of val (operand or operator)
    int val; ///< parsed value. can be operand or operator
} _postfixT;

#define IsNone(a) (a._operator == _NONE_)
#define IsOperand(a) (a._operator == _OPERAND_)
#define IsOperator(a) (a._operator == _OPERATOR_)
#define IsParenthesis(a) (a._operator == _PARENTHESIS_)
#define IsTerminator(a) (a._operator == _TERMINATOR_)

#define SIZE_POSTFIX_BUFFER (sizeof(postfix) / sizeof(_postfixT))

/// Initizize infix & postfix buffers to fill 0x0
void initializeBufffers(void);

// Read infix expression via stdin
int getInfixExpression(void);

// Return the address to point to infix buffer
char *getInfixBuffer(void);

// Print the contents of infix buffer
void printInfixBuffer(void);

// Return the address to point to postfix buffer
_postfixT *getPostfixBuffer(void);

// Print the contents of postfix buffer
void printPostfixBuffer(void);

// Print symbol in postfix
void printPostfixSymbol(_postfixT s);

#endif
