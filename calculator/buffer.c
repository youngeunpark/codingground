
/*
  'infix' as input buffer to read infix expression
  'postfix' as intermediate buffer to contain converted postfix expression
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <buffer.h>

// Indicator whether buffers are initialized
static char initialized = 0;

// infix buffer
static char infix[MAX_STRING];

// postfix buffer
static _postfixT postfix[MAX_STRING];

// Fill 0x0 to initizize buffers
void initializeBufffers(void)
{
    if(initialized) 
        return;
        
    memset(infix, 0x0, sizeof(infix));
    memset(postfix, 0x0, sizeof(postfix));
    
    initialized = 1;
}

// Read infix expression via stdin.
// Return
//   0 on failure.
//   The length of expression on success.
int getInfixExpression(void)
{
    if(fgets(infix, sizeof(infix), stdin) == NULL) {
        printf("ERROR [%s:%d] errno(%d)\n", __FILE__, __LINE__, errno);
        return 0;
    }
    
    return strlen(infix);
}

// Return the address to point to infix buffer
char *getInfixBuffer(void)
{
    return infix;
}

// Return the address to point to postfix buffer
_postfixT *getPostfixBuffer(void)
{
    return postfix;
}

