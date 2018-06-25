/**
    @file main.C
    @date 2018/06/14
    @author Youngeun Park
    @brief
    C++ main
*/

#include <iostream>
#include <../buffer/buffer.H>
#include <../convert/convert.H>
#include <calculator.H>

using namespace std;

#undef DEBUG

int main(void)
{
    Convertor *convertor = new Convertor();
    Calculator *calc = new Calculator();

    while (1) {
        Buffer *buffer = new Buffer();

        // Initialize buffers
        buffer->initializeBuffers();

        // Read infix expresssion
        if (!buffer->getInfixExpression()) {
            delete buffer;
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

        delete buffer;
    }

    delete convertor;
    delete calc;

    return 0;
}

