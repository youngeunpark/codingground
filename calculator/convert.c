/**
    @file convert.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Infix-to-postfix convertor
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <buffer.h>
#include <stack.h>
#include <utility.h>

/**
    @return
    precedence of given c

    @param
    c : operator (+, -, * or /)
*/
static int precedence(char c)
{
    int p = 2;

    switch (c) {
    case '+':
    case '-':
        p = 2;
        break;
    case '*':
    case '/':
        p = 3;
        break;
    case '(':
    case ')':
        p = 1;
        break;
    default:
        p = 0;
        break;
    }

    return p;
}

// Return 1 if c is operator
static int isOperator(char c)
{
    switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
        break;
    }

    return 0;
}

// Return 1 if c is operator
static int isParenthesis(char c)
{
    int result = 0;

    switch (c) {
    case '(':
    case ')':
        result = 1;
        break;
    }

    return result;
}

/**
    @return:
    On success, pointer of the buffer to be parsed next time\n
    On fauilure, NULL

    @param:
    in (IN) : pointer of infix buffer\n
    symbol (OUT) - parsed symbol
*/
static char *parseSymbol(char *in, symbolT * symbol)
{
    char *c = in;

    // Oops! in buffer is NULL
    if (!c) {
        printf("ERROR [%s:%d] in is NULL\n", __FILE__, __LINE__);
        return NULL;
    }

    // Strip out whitespaces
    while (isWhitespace(*c)) {
        c++;
    }

    // Reaching terminator char
    if (isTerminator(*c)) {
        symbol->type = _TERMINATOR_;
        symbol->val = (int)*c;
        return c;
    }

    // Parsing Operator
    if (isOperator(*c)) {
        symbol->type = _OPERATOR_;
        symbol->val = (int)*c;
        return ++c;
    }

    // Parsing Parenthesis
    if (isParenthesis(*c)) {
        symbol->type = _PARENTHESIS_;
        symbol->val = (int)*c;
        return ++c;
    }

    // Check invalid data
    if (!isNum(*c)) {
        printf("ERROR [%s:%d] invalid data(%d, %c)\n", __FILE__, __LINE__,
               (int)*c, *c);
        return NULL;
    } else { // Numeric operand
        int i = 0;

        // Make given operand as decimal number
        while (isNum(*c)) {
            char v = toNumeric(*c++);

            i = i * 10 + v;
        }

        symbol->type = _OPERAND_;
        symbol->val = i;
    }

    return c;
}

/**
    @return
    On success, the number of operators to be parsed\n
    On failutre, -1
*/
int convertToPostFix(void)
{
    char *in = getInfixBuffer();
    symbolT symbol, previousSymbol, *post = getPostfixBuffer();
    int j = 0, nOps = 0;

    // stack is used to convert infix to postfix
    initStack();

    memset(&previousSymbol, 0x0, sizeof(previousSymbol));

    while (1) {
        // Take out one symbol from infix expression
        in = parseSymbol(in, &symbol);

        if (!in) {
            printf("ERROR [%s:%d] parseSymbol failed\n", __FILE__, __LINE__);
            return -1;
        }

        if (symbol.type == _TERMINATOR_) {
            break;
        }

        // Consecutive same type of symbols must be invalid
        if (symbol.type == previousSymbol.type) {
            printf("ERROR [%s:%d] invalid infix expression\n", __FILE__,
                   __LINE__);
            printInfixBuffer();
            printf("previous symbol : "); printPostfixSymbol(previousSymbol);
            printf("current symbol : "); printPostfixSymbol(symbol);
            return -1;
        }

        previousSymbol = symbol;

        if (symbol.type == _OPERAND_) {
            post[j++] = symbol;
        } else {
            if ((char)symbol.val == '(') {
                push(symbol);
            } else if ((char)symbol.val == ')') {
                while (1) {
                    symbolT s;

                    pop(&s);
                    if ((char)s.val != '(') {
                        post[j++] = s;
                    } else {
                        break;
                    }
                }
            } else {
                nOps++;
                if (empty()) {
                    push(symbol);
                } else if (precedence((char)symbol.val) >
                           precedence((char)(top().val))) {
                    push(symbol);
                } else {
                    while (1) {
                        if (empty()) {
                            push(symbol);
                            break;
                        } else if (precedence((char)symbol.val) <=
                                   precedence((char)(top().val))) {
                            pop(&post[j++]);
                        } else {
                            push(symbol);
                            break;
                        }
                    }
                }
            }
        }
    }

    while (!empty()) {
        pop(&post[j++]);
    }

    if(nOps == 0) {
#ifdef DEBUG
        printf("%s = Valid expression, but no operator\n", getInfixBuffer());
#endif
    }

    return nOps;
}
