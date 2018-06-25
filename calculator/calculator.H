/**
    @file calculator.H
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ Header file for Calculator
*/

#ifndef __CALC_CPP_H__
#define __CALC_CPP_H__

#include <../buffer/buffer.H>

/// Class Calculator
class Calculator {

    public:

    /// calculator function to evaluate postifx expression
    int calc(Buffer *buf, int *);
};

#endif

