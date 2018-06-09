
#include <stack.h>
#include <stackInt.h>

// Stack pointer
// If MAX, stack is empty. If 0, then full.
int stackSize = MAX_STACK_DEPTH_DEFAULT;
int top = MAX_STACK_DEPTH_DEFAULT;

// Stack for any type of data (array of void *).
void **stack;

// argument n 
//   stack size. equal or less than LIMIT_OF_STACK_DEPTH
// return value 
//   0 on failure
//   1 on success
static int playStackString(long n)
{
    return 1;
}

// argument n 
//   stack size. equal or less than LIMIT_OF_STACK_DEPTH
// return value 
//   0 on failure
//   1 on success
static int playStackStruct(long n)
{
    return 1;
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
    if((n > LIMIT_OF_STACK_DEPTH) || (n <= 0)) {
        printf("Stack size is weird: %d\n", (int)n);
        return -1;
    }
    
    // Initialize stack of type int and test with it
    if(!playStackInt(n)) {
        printf("playStackInt failed\n");
        return -1;
    }
    
    // Initialize stack of string type and test with it
    if(!playStackString(n)) {
        printf("playStackString failed\n");
        return -1;
    }
    
    // Initialize stack of type struct type and test with it
    if(!playStackStruct(n)) {
        printf("playStackStruct failed\n");
        return -1;
    }
    
    // program successfully exits
    printf("=== stack.c ends ===\n");
    return 0;
}
