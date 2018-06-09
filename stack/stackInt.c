
#include <stack.h>

// Print stack
static void PrintInt(void)
{
    int idx = top;
    while(idx != stackSize) {
        printf("stack[%d] = %d\n", idx, *((int *)stack[idx]));
        idx++;
    }
}

// Push integer value
// Return 1 if success, 0 otherwise
static int PushInt(int val)
{
    if(IsFull()) return 0;
    
    *((int *)stack[--top]) = val;
    
    return 1;
}

// Pop integer value
// Return 1 if success, 0 otherwise
static int PopInt(int *val)
{
    if(IsEmpty()) return 0;
    
    *val = *((int *)stack[top++]);
    
    return 1;
}

// Peek top
// Return 1 if success, 0 otherwise
static int PeekInt(int *val)
{
    if(IsEmpty()) return 0;
    
    *val = *((int *)stack[top]);
    
    return 1;
}

// argument n 
//   stack size. equal or less than LIMIT_STACK_SIZE
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
    if(IsEmpty()) {
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
            if(IsFull()) {
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
    
    for(i = 0; i < n; i++) {
        if(!PushInt(i)) {
            printf("Oops, PushInt failed\n");
            ret = 0;
            goto error;
        }
    }
    if(IsFull()) {
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
    if(IsEmpty()) {
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
