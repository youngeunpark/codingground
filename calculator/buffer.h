
#ifndef __BUFFER_H__
#define __BUFFER_H__

#define MAX_STRING 1001

#define _OPERAND_ 1
#define _OPERATOR_ 2
#define _TERMINATOR_ 3

typedef struct {
    // _OPERATOR_ if val is operator
    // _OPERAND_ if val is numeric operand
    unsigned char _operator;
    int val;
} _postfixT;

// Fill 0x0 to initizize buffers
void initializeBufffers(void);

// Read infix expression via stdin
int getInfixExpression(void);

// Return the address to point to infix buffer
char *getInfixBuffer(void);

// Return the address to point to postfix buffer
_postfixT *getPostfixBuffer(void);

#endif
