/**
    @file convert.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    convert.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <buffer.h>
#include <stack.h>

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

#define isNumeric(c) ((c >= '0') && (c <= '9'))
#define toNumeric(c) (c - '0')
#define isTerminator(c) ((c == '\n') || (c == 0))
#define isWhiteChar(c) ((c == ' ') || (c == '\t'))

// Return:
//   On success, the address of the buffer to be parsed next time
//   On fauilure, NULL
// Arguments:
//   in (in) - the buffer location to be parsed
//   symbol (out) - parsed value
static char *parseSymbol(char *in, symbolT * symbol)
{
    char *c = in;

    // Oops! in buffer is NULL
    if (!c) {
        printf("ERROR [%s:%d] in is NULL\n", __FILE__, __LINE__);
        return NULL;
    }

    // Strip out whitespaces
    while (isWhiteChar(*c)) {
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
    if (!isNumeric(*c)) {
        printf("ERROR [%s:%d] invalid data(%d, %c)\n", __FILE__, __LINE__,
               (int)*c, *c);
        return NULL;
    } else { // Numeric operand
        int i = 0;

        // Make given operand as decimal number
        while (isNumeric(*c)) {
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

    return nOps;
}
