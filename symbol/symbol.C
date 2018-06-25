
/**
    @file symbol.C
    @date 2018/06/21
    @author Youngeun Park
    @brief
    C++ implementation of symbol
*/

#include <symbol.H>

using namespace std;

/**
    @return
    NONE

    @param
    NONE
*/
symbolT::symbolT()
{
    type = _NONE_;
    val = 0;
}

/**
    @return
    NONE

    @param
    type: symbol type\n
    val: value (operator, operand) to set
*/
symbolT::symbolT(unsigned char type, int val)
{
    type = type;
    this->val = val;
}

/**
    @return
    NONE

    @param
    NONE
*/
void symbolT::printType(void)
{
    switch(type) {
    case _NONE_:
        cout << "none";
    break;

    case _OPERAND_:
        cout << "operand";
    break;

    case _OPERATOR_:
        cout << "operator";
    break;

    case _PARENTHESIS_:
        cout << "parenthesis";
    break;

    case _TERMINATOR_:
        cout << "terminator";
    break;

    default:
        cout << "invalid type";
    break;
    }
}

/**
    @return
    type of this symbol

    @param
    NONE
*/
unsigned char symbolT::getType(void)
{
    return type;
}

/**
    @return
    NONE

    @param
    t: type of this symbol
*/
void symbolT::setType(unsigned char t)
{
    type = t;
}

/**
    @return
    NONE

    @param
    NONE
*/
void symbolT::printVal(void)
{
    switch(type) {
    case _OPERAND_:
        cout << val;
    break;

    case _OPERATOR_:
    case _PARENTHESIS_:
        cout << (char)val;
    break;
    }
}

/**
    @return
    value of this symbol

    @param
    NONE
*/
int symbolT::getVal(void)
{
    return val;
}

/**
    @return
    NONE

    @param
    v: value of this symbol
*/
void symbolT::setVal(int v)
{
    val = v;
}

/**
    @return
    ostream

    @param
    out: standard output stream\n
    s: symbol to print out
*/
ostream &operator<<(ostream &out, const symbolT &s)
{
    switch(s.type) {
        case _NONE_:
            out << "none:" << endl;
        break;
        case _OPERAND_:
            out << "operand:" << s.val << endl;
        break;

        case _OPERATOR_:
            out << "operand:" << (char)s.val << endl;
        break;

        case _PARENTHESIS_:
            out << "parenthesis:" << (char)s.val << endl;
        break;

        case _TERMINATOR_:
            out << "terminator:" << endl;
        break;

        default:
            out << "invalid type" << endl;
        break;
    }

    return out;
}

/**
    @return
    NONE

    @param
    out: standard output stream\n
    s: symbol to print out
*/
void symbolT::operator=(const symbolT &s)
{
    this->val = s.val;
    this->type = s.type;
}

/**
    @return
    symbol of a + b

    @param
    s: right operand of +
*/
symbolT symbolT::operator+(const symbolT &s)
{
    symbolT t;

    t.val = this->val + s.val;

    return t;
}

/**
    @return
    symbol  of a - b

    @param
    s: right operand of -
*/
symbolT symbolT::operator-(const symbolT &s)
{
    symbolT t;

    t.val = this->val - s.val;

    return t;
}

/**
    @return
    symbol  of a * b

    @param
    s: right operand of *
*/
symbolT symbolT::operator*(const symbolT &s)
{
    symbolT t;

    t.val = this->val * s.val;

    return t;
}

/**
    @return
    symbol  of a / b

    @param
    s: right operand of /
*/
symbolT symbolT::operator/(const symbolT &s)
{
    symbolT t;

    if(s.val == 0) {
        cout << "Oops, divide by zero" <<endl;
        return t;
    } else {
        t.val = this->val / s.val;
    }

    return t;
}

/**
    @return
    1 if symbol is none\n
    0 otherwise

    @param
    NONE
*/
int symbolT::IsNone(void)
{
    return (type == _NONE_);
}

/**
    @return
    1 if symbol is operand\n
    0 otherwise

    @param
    NONE
*/
int symbolT::IsOperand(void)
{
    return (type == _OPERAND_);
}

/**
    @return
    1 if symbol is operator\n
    0 otherwise

    @param
    NONE
*/
int symbolT::IsOperator(void) {
    return (type == _OPERATOR_);
}

/**
    @return
    1 if symbol is parenthesis\n
    0 otherwise

    @param
    NONE
*/
int symbolT::IsParenthesis(void) {
    return (type == _PARENTHESIS_);
}

/**
    @return
    1 if symbol is terminator\n
    0 otherwise

    @param
    NONE
*/
int symbolT::IsTerminator(void) {
    return (type == _TERMINATOR_);
}

