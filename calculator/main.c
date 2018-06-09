
/*
  Calculator program 
    reads the string of numeric infix expression,
    converts it postfix expression,
    calculates the postfix expression
    and prints out the result.
*/

#include <stdio.h>
#include <buffer.h>
#include <convert.h>
#include <calc.h>

int main(void)
{
    printf("=== Calculator start... ===\n");
    
    // Initialize infix & postfix buffers
    initializeBufffers();
    
    // Read infix expresssion
    if(!getInfixExpression()) return -1;

    // Convert infix expression into postfix one
    if(!convertToPostFix()) return -1;
    
    printf("Calculated result is %d\n", calc());
    
    return 0;
}
