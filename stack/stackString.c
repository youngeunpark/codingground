
#include <stack.h>

// Print stack
static void PrintString(void)
{
    int idx = top;
    while (idx != stackSize) {
        printf("stack[%d] = %s\n", idx, (char *)stack[idx]);
        idx++;
    }
}

// Push string
// Return 1 if success, 0 otherwise
static int PushString(char *val)
{
    if (IsFull())
        return 0;

    stack[--top] = (void *)val;

    return 1;
}

// Pop string
// Return 1 if success, 0 otherwise
static int PopString(char **val)
{
    if (IsEmpty())
        return 0;

    *val = (char *)stack[top++];

    return 1;
}

// Peek top
// Return 1 if success, 0 otherwise
static int PeekString(char **val)
{
    if (IsEmpty())
        return 0;

    *val = (char *)stack[top];

    return 1;
}

// Temporal string data
static char stringData[] = "abcdefghijklmnopqrstuvwxyz";

// argument n 
//   stack size. equal or less than LIMIT_STACK_SIZE
// return value 
//   0 on failure
//   1 on success
int playStackString(long n)
{
    int i = (int)n, ret = 1;
    char **buf;

    // Alloc memory buffer for stack of string
    buf = (char **)malloc(sizeof(char *) * (size_t) i);
    if (!buf) {
        printf("Error: %s(%d)\n", __FILE__, __LINE__);
        return 0;
    }
    // Create stack for string
    stackSize = top = i;
    stack = (void **)malloc(sizeof(void *) * (size_t) i);
    if (!stack) {
        free(buf);
        printf("Error: %s(%d)\n", __FILE__, __LINE__);
        return 0;
    }
    do {
        stack[i] = (void *)(buf[--i]);
    } while (i);

    // Testing starts...
    if (IsEmpty()) {
        printf("string stack is empty\n");
    } else {
        printf("Oops, stack should be empty\n");
        PrintString();
        ret = 0;
        goto error;
    }
    for (i = 1; i <= 5; i++) {
        if (!PushString(&stringData[i])) {
            char *val;
            if (IsFull()) {
                printf("Stack is full\n");
                break;
            } else {
                printf("Oops! PushString[%d] failed\n", i);
                ret = 0;
                goto error;
            }
            (void)PeekString(&val);
            printf("%s is pushed\n", val);
        }
    }

    PrintString();

    for (i = 1; i <= 5; i++) {
        char *val;
        if (!PopString(&val)) {
            printf("PopString[%d] failed\n", i);
            break;
        } else {
            printf("%s is poped\n", val);
        }
        if (PeekString(&val)) {
            printf("Val of top is %s\n", val);
        } else {
            printf("Stack is empty\n");
        }
    }

    for (i = 0; i < n; i++) {
        if (!PushString(&stringData[i % sizeof(stringData)])) {
            printf("Oops, PushString failed\n");
            ret = 0;
            goto error;
        }
    }

    PrintString();

    if (IsFull()) {
        printf("stack should be full\n");
    } else {
        printf("Oops, stack is not full\n");
        ret = 0;
        goto error;
    }
    for (i = 1; i <= n; i++) {
        char *val;
        if (!PopString(&val)) {
            printf("Oops, PopString failed\n");
            ret = 0;
            goto error;
        }
    }
    if (IsEmpty()) {
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
