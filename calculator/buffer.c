
/*
  'infix' as input buffer to read infix expression
  'postfix' as intermediate buffer to contain converted postfix expression
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <buffer.h>

// infix buffer
static char infix[MAX_STRING];

// postfix buffer
static _postfixT postfix[MAX_STRING];

// Fill 0x0 to initizize buffers
void initializeBufffers(void)
{
    memset(infix, 0x0, sizeof(infix));
    memset(postfix, 0x0, sizeof(postfix));
}

// Read infix expression via stdin.
// Return
//   0 on failure.
//   The length of expression on success.
int getInfixExpression(void)
{
    int len;

    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        if (errno == 0) {       // Encounter end of file
            return 0;
        } else {
            printf("ERROR [%s:%d] errno(%d)\n", __FILE__, __LINE__, errno);
        }
        return 0;
    }

    len = strlen(infix);

    // Remove newline from infix buffer
    if(infix[len - 1] == '\n') {
        infix[len - 1] = 0;
    }

    return len;
}

// Return the address to point to infix buffer
char *getInfixBuffer(void)
{
    return infix;
}

// Print the contents of infix buffer
void printInfixBuffer(void)
{
    printf("infix: ");
    printf("%s\n", infix);
}

// Return the address to point to postfix buffer
_postfixT *getPostfixBuffer(void)
{
    return postfix;
}

// Print the contents of postfix buffer
void printPostfixBuffer(void)
{
    int idx = 0;

    printf("postfix:\n");

    while (!(IsTerminator(postfix[idx]) || IsNone(postfix[idx]))) {
        if (IsOperator(postfix[idx])) {
            printf("[%d] %c\n", idx, (char)postfix[idx].val);
        } else if (IsOperand(postfix[idx])) {
            printf("[%d] %d\n", idx, postfix[idx].val);
        }
        idx++;
    }
}

// Print symbol in postfix
void printPostfixSymbol(_postfixT s)
{
    if (IsOperator(s)) {
        printf("%c\n", (char)s.val);
    } else if (IsOperand(s)) {
        printf("%d\n", s.val);
    }
}
