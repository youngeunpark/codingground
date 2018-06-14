/**
    @file calculator.C
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ Calculator implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <buffer.H>
#include <stack.H>
#include <utility.h>
#include <calculator.H>

/**
    @return
    On success, 1\n
    On failure, 0

    @param
    result (OUT) : integer pointer to return calculated result
*/
int Calculator::calc(Buffer *buf, int *result)
{
    int i = 0;
    symbolT a, b, s, symbol, *post = buf->getPostfixBuffer();
    Stack *stack;

    if(!result || !buf) {
        printf("ERROR [%s:%d] parameter is NULL\n", __FILE__, __LINE__);
        return 0;
    }

    stack = new Stack();

#ifdef DEBUG
    buf->printInfixBuffer();
    buf->printPostfixBuffer();
#endif
    while (1) {
        symbol = post[i++];

        if (IsTerminator(symbol) || IsNone(symbol)) {
            stack->pop(&symbol);
            break;
        }

        if (IsOperand(symbol)) {
#ifdef DEBUG
            buf->printPostfixSymbol(symbol);
#endif
            stack->push(symbol);
        } else if (IsOperator(symbol)) {
#ifdef DEBUG
            buf->printPostfixSymbol(symbol);
#endif
            s.type = _OPERAND_;
            stack->pop(&a);
            stack->pop(&b);

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
                    delete stack;
                    return 0;
                }
                s.val = b.val / a.val;
                break;
            default:
                printf("ERROR [%s:%d] invalid operator(%c, %d)\n", __FILE__,
                       __LINE__, (char)symbol.val, symbol.val);
                delete stack;
                return 0;
                break;
            }

            stack->push(s);
        } else {
            buf->printPostfixSymbol(symbol);
            printf("ERROR [%s:%d] invalid symbol(type: %c, %d)\n",
                   __FILE__, __LINE__, (char)symbol.type,
                   symbol.type);
            delete stack;
            return 0;
        }
    }

    *result = symbol.val;
    delete stack;
    return 1;
}

