/**
    @file buffer.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Struct and function for buffer management
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <buffer.h>

// infix buffer
static char infix[MAX_STRING];

// postfix buffer
static symbolT postfix[MAX_STRING];

/**
    @return
    NONE
*/
void initializeBuffers(void)
{
    memset(infix, 0x0, sizeof(infix));
    memset(postfix, 0x0, sizeof(postfix));
}

/**
    @return
    On failure, -1 (actually, exits program)\n
    On encounting comment, 0\n
    On success, the length of expression ( greater than zero )

    @param
    NONE
*/
int getInfixExpression(void)
{
    int len;

    if (fgets(infix, sizeof(infix) - 1, stdin) == NULL) {
        if(errno == 0) {
            // Seems to encounter EOF
            exit(0);
        } else {
            // Something wrong happens
            printf("ERROR [%s:%d] errno(%d)\n", __FILE__, __LINE__, errno);
        }
        return -1;
    }

    // expression is comment starting with #
    if(infix[0] == '#') {
#ifdef DEBUG
        printf("Skip comment, %s", infix);
#endif
        return 0;
    }

    len = strlen(infix);

    // Remove newline from infix buffer
    if(infix[len - 1] == '\n') {
        infix[len - 1] = 0;
    }

    return len;
}

/**
    @return
    Pointer to infix buffer

    @param
    NONE
*/
char *getInfixBuffer(void)
{
    return infix;
}

/**
    @return
    NONE

    @param
    NONE
*/
void printInfixBuffer(void)
{
    printf("infix: ");
    printf("%s\n", infix);
}

/**
    @return
    Pointer to postfix buffer

    @param
    NONE
*/
symbolT *getPostfixBuffer(void)
{
    return postfix;
}

/**
    @return
    NONE

    @param
    NONE
*/
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

/**
    @return
    NONE

    @param
    s : symbol to print out
*/
void printPostfixSymbol(symbolT s)
{
    if (IsOperator(s) || IsParenthesis(s)) {
        printf("%c\n", (char)s.val);
    } else if (IsOperand(s)) {
        printf("%d\n", s.val);
    }
}

