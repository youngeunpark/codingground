
/*
  Convert infix to postfix
*/

#include <stdio.h>
#include <stdlib.h>
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
        sp = -1;
}

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
static char *parseSymbol(char *in, _postfixT *symbol)
{
        char *c = in;

        // Oops! in buffer is NULL
        if (!c) {
                printf("ERROR [%s:%d] in is NULL\n", __FILE__, __LINE__);
                return NULL;
        }

        // Reaching terminator char
        if (isTerminator(*c)) {
                symbol->_operator = _TERMINATOR_;
                symbol->val = (int)*c;
                return c;
        }

        // Skip whitespaces
        while(isWhiteChar(*c)) {
                c++;
        }

        // Parsing Operator
        if (isOperator(*c)) { // Known operator
	            symbol->_operator = _OPERATOR_;
	            symbol->val = (int)*c;
                return ++c;
        }

        // Parsing Parenthesis
        if (isParenthesis(*c)) { // Known operator
	            symbol->_operator = _PARENTHESIS_;
	            symbol->val = (int)*c;
                return ++c;
        }

        // Check invalid data
        if (!isNumeric(*c)) {
	            printf("ERROR [%s:%d] invalid data(%d, %c)\n", __FILE__, __LINE__, (int)*c, *c);
	            return NULL;
        } else { // Numeric operand
                int i = 0;

                // Make given operand as decimal number
                while (isNumeric(*c)) {
                        char v = toNumeric(*c++);

                        i = i * 10 + v;
                }

                symbol->_operator = _OPERAND_;
                symbol->val = i;
        }

    return c;
}

// Convert infix expression into postpix one
// Return:
//   1 on success, 0 otherwise
int convertToPostFix(void)
{
        char *in = getInfixBuffer();
        _postfixT symbol, *post = getPostfixBuffer();
        int i = 0, j = 0;
        unsigned char previous_operator = _NONE_;

        // stack is used to convert infix to postfix
        initStack();

        while (1) {
                in = parseSymbol(in, &symbol);

                if (!in) {
                        printf("ERROR [%s:%d] failed\n", __FILE__, __LINE__);
                        return 0;
                }

                if (symbol._operator == _TERMINATOR_) {
                        break;
                }

                // Consecutive same type of symbols must be invalid
                if(symbol._operator == previous_operator) {
                        printf("ERROR [%s:%d] invalid infix expression\n", __FILE__, __LINE__);
                        return 0;
                }

                if (symbol._operator == _OPERAND_) {
                        post[j++] = symbol;
                } else { // _OPERATOR_
                        if ((char)symbol.val == '(') {
                                push(symbol);
                        } else if ((char)symbol.val == ')') {
                                while (1) {
                                        _postfixT s;

                                        pop(&s);
                                        if ((char)s.val != '(') {
                                                post[j++] = s;
                                        } else {
                                                break;
                                        }
                                }
                        } else {
                                if (empty()) {
                                        push(symbol);
                                } else if (precedence((char)symbol.val) > precedence((char)(top().val))) {
                                        push(symbol);
                                } else {
                                        while (1) {
                                                if (empty()) {
                                                        push(symbol);
                                                        break;
                                                } else if (precedence((char)symbol.val) <= precedence((char)(top().val))) {
                                                        pop(&post[j++]);
                                                } else {
                                                        push(symbol);
                                                        break;
                                                }
                                        }
                                }
                        }
                }

                previous_operator = symbol._operator;
        }

        while (!empty()) {
                pop(&post[j++]);
        }

        return 1;
}
