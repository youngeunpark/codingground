
/*
 * Author: Youngeun Park
 * Creation Date: 2018-06-10
 *
 * Calculator program
        reads the string of numeric infix expression,
        converts it postfix expression,
        calculates the postfix expression
        and prints out the result.
*/

#include <stdio.h>
#include <buffer.h>
#include <convert.h>
#include <calculator.h>

int main(void)
{
    printf("Supported operators: + - * / \n");
    printf("Enter infix expression (e.g> 1 + 2 * 3)\n");

    while (1) {
        // Initialize infix & postfix buffers
        initializeBufffers();

        // Read infix expresssion
        if (!getInfixExpression())
            return -1;

        // Convert infix expression into postfix one
        if (!convertToPostFix())
            return -1;

        printf("%s = %d\n", getInfixBuffer(), calc());
    }

    return 0;
}
