/**
    @file convert.cpp
    @date 2018/06/14
    @author Youngeun Park
    @brief
    Infix-to-postfix convertor
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <../stack/stack.H>
#include <../symbol/symbol.H>
#include <../calculator/utility.h>
#include <convert.H>

using namespace std;

/**
    @return
    precedence of given c

    @param
    c : operator (+, -, * or /)
*/
int Convertor::precedence(char c)
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

/**
    @return
    1, if c is operator
    0, otherwise

    @param
    c : operator (+, -, * or /)
*/
int Convertor::isOperator(char c)
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

/**
    @return
    1, if c is parenthesis
    0, otherwise

    @param
    c : operator (, )
*/
int Convertor::isParenthesis(char c)
{
    switch (c) {
    case '(':
    case ')':
        return 1;
        break;
    }

    return 0;
}

/**
    @return:
    On success, pointer of the buffer to be parsed next time\n
    On fauilure, NULL

    @param:
    in (IN) : pointer of infix buffer\n
    symbol (OUT) - parsed symbol
*/
char *Convertor::parseSymbol(char *in, symbolT &symbol)
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
        //symbol->type = _TERMINATOR_;
        //symbol->val = (int)*c;
        symbol.setType(_TERMINATOR_);
        symbol.setVal((int)*c);
        return c;
    }

    // Parsing Operator
    if (isOperator(*c)) {
        symbol.setType(_OPERATOR_);
        symbol.setVal((int)*c);
        return ++c;
    }

    // Parsing Parenthesis
    if (isParenthesis(*c)) {
        symbol.setType(_PARENTHESIS_);
        symbol.setVal((int)*c);
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

        symbol.setType(_OPERAND_);
        symbol.setVal(i);
    }

    return c;
}

#define ERROR_POSTFIX_EXPRESSION() \
    cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" ; \
    cout << " invalid infix expression" << endl; \
    buffer->printInfixBuffer(); \
    cout << "previous symbol : " ; buffer->printPostfixSymbol(previousSymbol); \
    cout << "current symbol : " ; buffer->printPostfixSymbol(symbol); \

/**
    @return
    On success, the number of operators to be parsed\n
    On failutre, -1
*/
int Convertor::convertToPostFix(Buffer *buffer)
{
    char *in = buffer->getInfixBuffer();
    symbolT symbol, previousSymbol, **post = buffer->getPostfixBuffer();
    int j = 0, nOps = 0;
    Stack *stack = new Stack();

    //memset(&previousSymbol, 0x0, sizeof(previousSymbol));

    while (1) {
        // Take out one symbol from infix expression
        in = parseSymbol(in, symbol);

        if (!in) {
            cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "]" << "parseSymbol failed" << endl;
            delete stack;
            return -1;
        }

        if (symbol.IsTerminator()) {
            break;
        }

#ifdef DEBUG
        buffer->printPostfixSymbol(symbol);
#endif

        // Check invalid expression in postfix
        if (symbol.getType() == previousSymbol.getType()) {
            if(symbol.IsParenthesis() && (symbol.getVal() == previousSymbol.getVal())) {
                ; // Consecurive parenthesis like (( or )) is acceptable
            } else {
                ERROR_POSTFIX_EXPRESSION()
                delete stack;
                return -1;
            }
        } else if (previousSymbol.IsOperand() && ((char)symbol.getVal() == '(')) {
            ERROR_POSTFIX_EXPRESSION()
            delete stack;
            return -1;
        }

        previousSymbol = symbol;

        if (symbol.IsOperand()) {
            *(post[j++]) = symbol;
        } else {
            if ((char)symbol.getVal() == '(') {
                stack->push(symbol);
            } else if ((char)symbol.getVal() == ')') {
                while (1) {
                    symbolT s;

                    stack->pop(&s);
                    if ((char)s.getVal() != '(') {
                        *(post[j++]) = s;
                    } else {
                        break;
                    }
                }
            } else {
                symbolT s;
                stack->top(&s);
                nOps++;
                if (stack->empty()) {
                    stack->push(symbol);
                } else if (precedence((char)symbol.getVal()) >
                            precedence((char)(s.getVal()))) {
                    stack->push(symbol);
                } else {
                    while (1) {
                        stack->top(&s);
                        if (stack->empty()) {
                            stack->push(symbol);
                            break;
                        } else if (precedence((char)symbol.getVal()) <=
                                    precedence((char)(s.getVal()))) {
                            stack->pop(post[j++]);
                        } else {
                            stack->push(symbol);
                            break;
                        }
                    }
                }
            }
        }
    }

    while (!stack->empty()) {
        stack->pop(post[j++]);
    }

    if(nOps == 0) {
#ifdef DEBUG
        cout << buffer->getInfixBuffer() << " = Valid expression, but no operator" << endl;
#endif
    }

    delete stack;
    return nOps;
}

