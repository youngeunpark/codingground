/**
    @file calculator.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Calculator
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <buffer.h>
#include <stack.h>

#define isNum(c) ((c >= '0') && (c <= '9'))
#define isTerminator(c) ((c == '\n') || (c == 0))

int calc(void)
{
    int i = 0;
    _postfixT a, b, s, symbol, *post = getPostfixBuffer();

    initStack();

#ifdef DEBUG
    printInfixBuffer();
    printPostfixBuffer();
#endif
    while (1) {
        symbol = post[i++];

        if (IsTerminator(symbol) || IsNone(symbol)) {
            pop(&symbol);
            break;
        }

        if (IsOperand(symbol)) {
#ifdef DEBUG
            printPostfixSymbol(symbol);
#endif
            push(symbol);
        } else if (IsOperator(symbol)) {
#ifdef DEBUG
            printPostfixSymbol(symbol);
#endif
            s._operator = _OPERAND_;
            pop(&a);
            pop(&b);

            switch ((char)symbol.val) {
            case '+':
                s.val = b.val + a.val;
                break;
            case '-':
                s.val = b.val - a.val;
                break;
            case '*':
                s.val = b.val * a.val;
                break;
            case '/':
                if (a.val == 0) {
                    printf("ERROR [%s:%d] divide by zero\n", __FILE__,
                           __LINE__);
                    exit(0);
                }
                s.val = b.val / a.val;
                break;
            default:
                printf("ERROR [%s:%d] invalid operator(%c, %d)\n", __FILE__,
                       __LINE__, (char)symbol.val, symbol.val);
                exit(0);
                break;
            }

            push(s);
        } else {
            printPostfixSymbol(symbol);
            printf("ERROR [%s:%d] invalid symbol(_operator: %c, %d)\n",
                   __FILE__, __LINE__, (char)symbol._operator,
                   symbol._operator);
            exit(0);
        }
    }

    return symbol.val;
}
