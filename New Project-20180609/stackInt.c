
#include <stack.h>

// Return 1 if empty, 0 otherwise
static int IsEmptyInt(void)
{
    return (stackSize == top);
}

// Return 1 if full, 0 otherwise
static int IsFullInt(void)
{
    return (top == 0);
}

// Print stack
static void PrintInt(void)
{
    int idx = top;
    while(idx != stackSize) {
        printf("stack[%d] = %d\n", idx, *((int *)stack[idx]));
    }
}

// Push integer value
// Return 1 if success, 0 otherwise
static int PushInt(int val)
{
    if(IsFullInt()) return 0;
    
    *((int *)stack[--top]) = val;
    
    return 1;
}

// Pop integer value
// Return 1 if success, 0 otherwise
static int PopInt(int *val)
{
    if(IsEmptyInt()) return 0;
    
    *val = *((int *)stack[top++]);
    
    return 1;
}

// Peek top
// Return 1 if success, 0 otherwise
static int PeekInt(int *val)
{
    if(IsEmptyInt()) return 0;
    
    *val = *((int *)stack[top]);
    
    return 1;
}

// argument n 
//   stack size. equal or less than LIMIT_OF_STACK_DEPTH
// return value 
//   0 on failure
//   1 on success
int playStackInt(long n)
{
    int i = (int)n, *buf, ret = 1;
    
    // Alloc memory buffer for stack of int type
    buf = (int *)malloc(sizeof(int) * (size_t)i);
    if(!buf) {
        printf("Error: %s(%d)\n", __FILE__, __LINE__);
        return 0;
    }

    // Create stack for int
    stackSize = top = i;
    stack = (void **)malloc(sizeof(void *) * (size_t)i);
    if(!stack) {
        free(buf);
        printf("Error: %s(%d)\n", __FILE__, __LINE__);
        return 0;
    }
    do {
        stack[i] = (void *)(&buf[--i]);
    } while(i);
    
    // Testing starts...
    if(IsEmptyInt()) {
        printf("int stack is empty\n");
    } else {
        printf("Oops, stack should be empty\n");
        PrintInt();
        ret = 0;
        goto error;
    }
    for(i = 1; i <= 5; i++) {
        if(!PushInt(i)) {
            int val;
            if(IsFullInt()) {
                printf("Stack is full\n");
                break;
            } else {
                printf("Oops! PushInt[%d] failed\n", i);    
                ret = 0;
                goto error;
            }
            (void)PeekInt(&val);
            printf("%d is pushed\n", val);
        }
    }

    PrintInt();

    for(i = 1; i <= 5; i++) {
        int val;
        if(!PopInt(&val)) {
            printf("PopInt[%d] failed\n", i);
            break;
        } else {
            printf("%d is poped\n", val);
        }
        (void)PeekInt(&val);
        printf("Val of top is %d\n", val);
    }
    
    for(i = 1; i <= n; i++) {
        if(!PushInt(i)) {
            printf("Oops, PushInt failed\n");
            ret = 0;
            goto error;
        }
    }
    if(IsFullInt()) {
        printf("stack should be full\n");
    } else {
        printf("Oops, stack is not full\n");
        ret = 0;
        goto error;
    }
    for(i = 1; i <= n; i++) {
        int val;
        if(!PopInt(&val)) {
            printf("Oops, PopInt failed\n");
            ret = 0;
            goto error;
        }
    }
    if(IsEmptyInt()) {
        printf("stack should be empty\n");
    } else {
        printf("Oops, stack is not empty\n");
        ret = 0;
        goto error;
    }

error:    
    free(buf);
    free(stack); 
    stack = NULL;
    
    return ret;
}
