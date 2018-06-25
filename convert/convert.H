/**
    @file convert.H
    @date 2018/06/14
    @author Youngeun Park
    @brief
    Header file for infix to postfix convertor
*/

#ifndef __CONVERT_CPP_H__
#define __CONVERT_CPP_H__

#include <../buffer/buffer.H>

class Convertor {
    private:

    /// Return precedence of the given operator, c
    int precedence(char c);

    /// Check if c is operator
    int isOperator(char c);

    /// Check if c is paranthesis
    int isParenthesis(char c);

    /// Parse string in and convert it to symbolT
    char *parseSymbol(char *in, symbolT &symbol);

    public:
    /**
        Convert infix expression into postpix\n
        ( Reference: https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm )
    */
    int convertToPostFix(Buffer *buffer);

};

#endif
