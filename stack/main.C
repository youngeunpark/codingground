
#include <stack.H>
#include <iostream>

int main(void)
{
    int i;

    // integer stack
    Stack *stack = new Stack();

    for(i = 0; i < 10; i++) {
        stack->push(i);
    }
    stack->print();
    while(stack->pop(&i));
    stack->print();

    delete stack;

    // char stack
    stack = new Stack('a');
    for(i = 0; i < 10; i++) {
        stack->push((char)('a' + i));
    }
    stack->print();
    while(stack->pop(&i));
    stack->print();

    delete stack;

    // string stack
    stack = new Stack("");
    stack->push("aaa");
    stack->push("bbb");
    stack->push("ccc");
    stack->push("ddd");
    stack->push("eee");
    stack->push("fff");
    stack->push("ggg");
    stack->print();

    char *p;
    while(stack->pop(&p)) {
        cout << "popped string is " << p << endl;
    }

    stack->print();

    delete stack;

}
