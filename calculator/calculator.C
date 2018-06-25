/**
    @file calculator.C
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ Calculator implementation
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <../stack/stack.H>
#include <utility.h>
#include <calculator.H>

using namespace std;

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
    symbolT a, b, s, *symbol, **post = buf->getPostfixBuffer();
    Stack *stack;

    if(!result || !buf) {
        cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
        cout << " parameter is NULL" << endl ;
        return 0;
    }

    stack = new Stack();

#ifdef DEBUG
    buf->printInfixBuffer();
    buf->printPostfixBuffer();
#endif
    while (1) {
        symbol = post[i++];

        if (symbol->IsTerminator() || symbol->IsNone()) {
            stack->pop(symbol); // why ?
            break;
        }

        if (symbol->IsOperand()) {
#ifdef DEBUG
            buf->printPostfixSymbol(*symbol);
#endif
            stack->push(*symbol);
        } else if (symbol->IsOperator()) {
#ifdef DEBUG
            buf->printPostfixSymbol(*symbol);
#endif
            s.setType(_OPERAND_);
            stack->pop(&a);
            stack->pop(&b);

            switch ((char)symbol->getVal()) {
            case '+':
                s = b + a;
                break;
            case '-':
                s = b - a;
                break;
            case '*':
                s = b * a;
                break;
            case '/':
                if (a.getVal() == 0) {
                    cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
                    cout << " divide by zero (" << b.getVal() << "/" << a.getVal() << ")" << endl;
                    delete stack;
                    return 0;
                }
                s = b / a;
                break;
            default:
                cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
                cout << " invalid operator (" << (char)symbol->getVal() << ":" ;
                cout << symbol->getVal() << ")" << endl;
                delete stack;
                return 0;
                break;
            }

            stack->push(s);
        } else {
            buf->printPostfixSymbol(*symbol);
            cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ;
            cout << " invalid symbol(type: " << (char) symbol->getType() ;
            cout << ", " << symbol->getType() << ")" << endl;
            delete stack;
            return 0;
        }
    }

    *result = symbol->getVal();
    delete stack;
    return 1;
}

