
/*
  Calculate postfix buffer to get numeric result
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <buffer.h>

static _postfixT stack[MAX_STRING];
static int sp = -1;

static void push(_postfixT c)
{
        stack[++sp] = c;
}

static void pop(_postfixT *p)
{
        *p = stack[sp--];
}

static _postfixT top(void)
{
        return stack[sp];
}

static int empty(void)
{
        return (sp == -1);
}

static void initStack(void)
{
        memset(stack, 0x0, sizeof(stack));
        sp = -1;
}


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
                                if(a.val == 0) {
                                        printf("ERROR [%s:%d] divide by zero\n", __FILE__, __LINE__);
                                        exit(0);
                                }
                                s.val = b.val / a.val;
                        break;
                        default:
                                printf("ERROR [%s:%d] invalid operator(%c, %d)\n", __FILE__, __LINE__, (char)symbol.val, symbol.val);
                                exit(0);
                        break;
	                    }

                        push(s);
                } else {
                        printPostfixSymbol(symbol);
                        printf("ERROR [%s:%d] invalid symbol(_operator: %c, %d)\n", __FILE__, __LINE__, (char)symbol._operator, symbol._operator);
                        exit(0);
                }
        }

        return symbol.val;
}

