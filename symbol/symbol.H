/**
    @file symbol.H
    @date 2018/06/21
    @author Youngeun Park
    @brief
    C++ header file of symbol
*/

#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include <iostream>

using namespace std;

/// structure symbolT
class symbolT {
    private:

#define _NONE_ 0
#define _OPERAND_ 1
#define _OPERATOR_ 2
#define _PARENTHESIS_ 3
#define _TERMINATOR_ 4

    ///< indicator (operand or operator)
    unsigned char type;

    ///< parsed integer value or operator
    int val;

    public:

    /// Constructors
    symbolT();
    symbolT(unsigned char type, int val);

    /// Print type
    void printType(void);

    /// Return type
    unsigned char getType(void);

    /// Set type
    void setType(unsigned char t);

    /// Print val
    void printVal(void);

    /// Return val
    int getVal(void);

    /// Set val
    void setVal(int v);

    /// Overloading << to display type and val
    friend ostream &operator<<(ostream &out, const symbolT &s);

    /// Overloading = for assignment operation
    void operator=(const symbolT &s);

    /// Overloading +
    symbolT operator+(const symbolT &s);

    /// Overloading -
    symbolT operator-(const symbolT &s);

    /// Overloading *
    symbolT operator*(const symbolT &s);

    /// Overloading /
    symbolT operator/(const symbolT &s);

    /// Check if type of this symbol is notype
    int IsNone(void);

    /// Check if type of this symbol is operand
    int IsOperand(void);

    /// Check if type of this symbol is operator
    int IsOperator(void);

    /// Check if type of this symbol is operator
    int IsParenthesis(void);

    /// Check if type of this symbol is terminator
    int IsTerminator(void);
};

#endif

