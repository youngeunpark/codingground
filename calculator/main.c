/**
    @file main.c
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Calculator program
        reads the string of numeric infix expression,
        converts it postfix expression,
        calculates the postfix expression
        and prints out the result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <buffer.h>
#include <convert.h>
#include <calculator.h>

/**
    @return
*/
int main(void)
{
    int nOps;

    printf("Supported operators: + - * / \n");
    printf("Enter infix expression (e.g> 1 + 2 * 3)\n");

    while (1) {
        // Initialize buffers
        initializeBuffers();

        // Read infix expresssion
        if (!getInfixExpression()) {
            continue;
        }

        // Convert infix expression into postfix one
        nOps = convertToPostFix();
        if (nOps < 0) {
            printf("%s = Invalid expression\n", getInfixBuffer());
        } else if(nOps == 0) {
            printf("%s = Valid expression, but no operator\n", getInfixBuffer());
        } else {
            printf("%s = %d\n", getInfixBuffer(), calc());
        }
    }

    return 0;
}
