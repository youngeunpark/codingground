/**
    @file main.C
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ main
*/

#include <iostream>
#include <buffer.H>
#include <convert.H>
#include <calculator.H>

using namespace std;

#undef DEBUG

int main(void)
{
    Buffer *buffer = new Buffer();
    Convertor *convertor = new Convertor();
    Calculator *calc = new Calculator();

    while (1) {
        // Initialize buffers
        buffer->initializeBuffers();

        // Read infix expresssion
        if (!buffer->getInfixExpression()) {
            continue;
        }

#ifdef DEBUG
        buffer->printInfixBuffer();
#endif
        // Convert infix into postfix
        if (convertor->convertToPostFix(buffer) > 0) {
            int result;

#ifdef DEBUG
            buffer->printPostfixBuffer();
#endif
            // Calcualte postfix expression
            if(calc->calc(buffer, &result)) {
                // Print result
                cout << buffer->getInfixBuffer() << " = " << result << endl;
            }
        }
    }

    delete convertor;
    delete calc;

    return 0;
}

