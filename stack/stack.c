
#include <stack.h>
#include <stackInt.h>
#include <stackString.h>
#include <stackStruct.h>

// Stack pointer
// If MAX, stack is empty. If 0, then full.
int stackSize = MAX_STACK_SIZE;
int top = MAX_STACK_SIZE;

// Stack for any data type.
void **stack;

// Return 1 if empty, 0 otherwise
int IsEmpty(void)
{
    return (stackSize == top);
}

// Return 1 if full, 0 otherwise
int IsFull(void)
{
    return (top == 0);
}

static void initStack(void)
{
    stackSize = top = MAX_STACK_SIZE;
    stack = NULL;
}

int main(int argc, char *argv[])
{
    long n;
    
    // program starts
    printf("=== stack.c starts ===\n");
    
    // program exits due to invalid # of argument
    if(argc != 2) {
        printf("Usage: a.out number\n");
        return -1;
    }
    
    // program exits due to invalid argument
    n = strtol(argv[1], NULL, 10);
    if((n == LONG_MIN) || (n == LONG_MAX)) {
        printf("Wrong argument: %s\n", argv[1]);
        return -1;
    }
    
    // program exits due to invalid argument
    if((n > LIMIT_STACK_SIZE) || (n <= 0)) {
        printf("Stack size is weird: %d\n", (int)n);
        return -1;
    }
 
    // Initialize stack of type int and test with it
    initStack();
    if(!playStackInt(n)) {
        printf("playStackInt failed\n");
        return -1;
    }
    
    // Initialize stack of string type and test with it
    initStack();
    if(!playStackString(n)) {
        printf("playStackString failed\n");
        return -1;
    }
 
    // Initialize stack of type struct type and test with it
    initStack();
    if(!playStackStruct(n)) {
        printf("playStackStruct failed\n");
        return -1;
    }
    
    // program successfully exits
    printf("=== stack.c ends ===\n");
    return 0;
}
