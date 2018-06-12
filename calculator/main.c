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
    // Brief help on how to run this calculator
    printf("Enter infix expression (e.g> 1 + 2 * 3)\n");
    printf("Supported operators: + - * / \n");

    while (1) {
        // Initialize buffers
        initializeBuffers();

        // Read infix expresssion
        if (!getInfixExpression()) {
            continue;
        }

        // Convert infix into postfix
        if (convertToPostFix() > 0) {
            int result;

            // Calcualte postfix expression
            if(calc(&result)) {
                // Print result
                printf("%s = %d\n", getInfixBuffer(), result);
            }
        }
    }

    return 0;
}

