
#include <stdio.h>
#include <string.h>

#define MAX_STRING 1001

char infix[MAX_STRING];
typedef unsigned char byte;
typedef struct {
    byte _operator; // 1 means val is operator
    int val;
} _postfixT;
_postfixT postfix[MAX_STRING];

int isOperand(char c)
{
    int ret = 0;
    
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            ret = 0;
            break;
        default:
            ret = 1;
            break;
    }
    
    return ret;
}

int precedence(char c)
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
        case '^':
            p = 4;
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

int stack[MAX_STRING];
int sp = -1;

void push(int c)
{
    stack[++sp] = c;
}

int pop(void) 
{
    return stack[sp--];
}

int top(void)
{
    return stack[sp];
}

int empty(void)
{
    return (sp == -1);
}

void initStack(void)
{
    sp = -1;
}

// Return:
//   the address of the buffer to be parsed next time
// Arguments:
//   in (in) - the buffer location to be parsed
//   symbol (out) - parsed value
static char* parseInfix(char *in, _postfixT *symbol)
{
    char *ret = in;
    
    
    return in;
}

static int convertToPostFix(char *in, _postfixT *post)
{
    char *infix = in;
    int i = 0, j = 0;
    _postfixT symbol;
    
    while(1) {
        symbol = in[i++];
        if((symbol == 0) || (symbol == '\n'))
            break;
        if(isOperand(symbol)) {
            post[j++] = symbol;
        } else { // symbol is operator
            if(symbol == '(') {
                push(symbol);
            } else if (symbol == ')') {
                while(1) {
                    char s;
                
                    s = (char)pop();
                    if(s != '(') {
                        post[j++] = s;
                    } else {
                        break;
                    }
                }
            } else {
                if(empty()) {
                    push((int)symbol);
                } else if(precedence(symbol) > precedence((char)top())) {
                    push((int)symbol);
                } else {
                    while(1) {
                        if(empty()) {
                            push(symbol);
                            break;
                        } else if(precedence(symbol) <= precedence((char)top())) {
                            post[j++] = (char)pop();
                        } else {
                            push((int)symbol);
                            break;
                        }
                    }
                }
            }
        }
        //printf("postfix = %s\n", post);
    }
    
    while(!empty()) {
        post[j++] = (char)pop();
    }
}

#define isNum(c) ((c >= '0') && (c <= '9'))
int calc(char *post)
{
    int i = 0;
    char symbol;
    int a, b;
    
    while(1) {
        symbol = post[i++];
        if((symbol == 0) || (symbol == '\n'))
            break;

        if(isNum(symbol)) {
            push(symbol);
        } else {
            switch (symbol) {
                case '+';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a+b+'0');
                    break;
                case '-';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a-b+'0');
                    break;
                case '*';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a*b+'0');
                    break;
                case '/';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a/b+'0');
                    break;
                case '^';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a^b+'0');
                    break;
                default:
                    printf("oops, invalid operator\n");
                break
            }
        }
    }
    while(!empty()) {
            switch (symbol) {
                case '+';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a+b+'0');
                    break;
                case '-';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a-b+'0');
                    break;
                case '*';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a*b+'0');
                    break;
                case '/';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a/b+'0');
                    break;
                case '^';
                    a = pop() - '0';
                    b = pop() - '0';
                    push(a^b+'0');
                    break;
                default:
                    printf("oops, invalid operator\n");
                break
            }
    }
}

int main(void)
{
    memset(infix, 0x0, sizeof(infix));
    memset(postfix, 0x0, sizeof(postfix));
    
    if(fgets(infix, sizeof(infix), stdin) == NULL) {
        printf("failed to fgets\n");
    }

    initStack();
    
    if(!convertToPostFix(infix, postfix)) {
        printf("failed to convert infix to postfix\n");
    }
    //printf("infix = %s\n", infix);
    printf("postfix = %s\n", postfix);
    
    initStack();
    
    printf("%s = %d\n", calc(postfix));
    
    return 0;
}