/**
    @file calculator.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Calculator implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <buffer.h>
#include <stack.h>
#include <utility.h>

/**
    @return
    On success, 1\n
    On failure, 0

    @param
    result (OUT) : integer pointer to return calculated result
*/
int calc(int *result)
{
    int i = 0;
    symbolT a, b, s, symbol, *post = getPostfixBuffer();

    initStack();

    if(!result) {
        printf("ERROR [%s:%d] result is NULL\n", __FILE__, __LINE__);
        return 0;
    }

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
            s.type = _OPERAND_;
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
                    printf("ERROR [%s:%d] divide by zero (%d/%d)\n", __FILE__,
                           __LINE__, b.val, a.val);
                    return 0;
                }
                s.val = b.val / a.val;
                break;
            default:
                printf("ERROR [%s:%d] invalid operator(%c, %d)\n", __FILE__,
                       __LINE__, (char)symbol.val, symbol.val);
                return 0;
                break;
            }

            push(s);
        } else {
            printPostfixSymbol(symbol);
            printf("ERROR [%s:%d] invalid symbol(type: %c, %d)\n",
                   __FILE__, __LINE__, (char)symbol.type,
                   symbol.type);
            return 0;
        }
    }

    *result = symbol.val;
    return 1;
}

