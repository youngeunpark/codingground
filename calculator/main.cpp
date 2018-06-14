
#include <stack.hpp>

int main(void)
{
    Stack *s = new Stack();
    symbolT symbol = {_OPERATOR_, '+'};

    s->push(symbol);
    //s->push(symbol);
    //s->print();
    s->pop(&symbol);
    //s->print();
    //s->pop(&symbol);

    delete s;

    return 0;
}
