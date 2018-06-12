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
    unsigned char type; ///< indicator of val (operand or operator)
    int val; ///< parsed value. can be operand or operator
} _postfixT;

#define IsNone(a) (a.type == _NONE_)
#define IsOperand(a) (a.type == _OPERAND_)
#define IsOperator(a) (a.type == _OPERATOR_)
#define IsParenthesis(a) (a.type == _PARENTHESIS_)
#define IsTerminator(a) (a.type == _TERMINATOR_)

#define SIZE_POSTFIX_BUFFER (sizeof(postfix) / sizeof(_postfixT))

/// Initialize infix & postfix buffers by filling 0x0
void initializeBuffers(void);

/// Read infix expression via standard input
int getInfixExpression(void);

/// Return infix buffer
char *getInfixBuffer(void);

/// Print infix buffer
void printInfixBuffer(void);

/// Return postfix buffer
_postfixT *getPostfixBuffer(void);

/// Print postfix buffer
void printPostfixBuffer(void);

// Print a symbol of _postfixT
void printPostfixSymbol(_postfixT s);

#endif

