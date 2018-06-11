
#include <stack.h>

typedef struct {
    int val;
    char *str;
    void (*printFnc) (void *);
} structType;

static void _printStruct(void *_val)
{
    structType *val = (structType *) _val;
    if (val) {
        printf("val(%d), str(%s)\n", val->val, val->str);
    }
}

// Print stack
static void PrintStruct(void)
{
    int idx = top;
    while (idx != stackSize) {
        printf("stack[%d] = ", idx);
        ((structType *) stack[idx])->printFnc(stack[idx]);
        idx++;
    }
}

// Push string
// Return 1 if success, 0 otherwise
static int PushStruct(structType * val)
{
    if (IsFull())
        return 0;

    stack[--top] = (structType *) val;

    return 1;
}

// Pop string
// Return 1 if success, 0 otherwise
static int PopStruct(structType ** val)
{
    if (IsEmpty())
        return 0;

    *val = (structType *) stack[top++];

    return 1;
}

// Peek top
// Return 1 if success, 0 otherwise
static int PeekStruct(structType ** val)
{
    if (IsEmpty())
        return 0;

    *val = (structType *) stack[top];

    return 1;
}

// Temporal string data
static char stringData[] = "abcdefghijklmnopqrstuvwxyz";

// argument n 
//   stack size. equal or less than LIMIT_STACK_SIZE
// return value 
//   0 on failure
//   1 on success
int playStackStruct(long n)
{
    int i = (int)n, ret = 1;
    structType *buf;

    // Alloc memory buffer for stack of string
    buf = (structType *) malloc(sizeof(structType) * (size_t) i);
    if (!buf) {
        printf("Error: %s(%d)\n", __FILE__, __LINE__);
        return 0;
    }
    // Create stack for string
    stackSize = top = i;
    stack = (void **)malloc(sizeof(structType *) * (size_t) i);
    if (!stack) {
        free(buf);
        printf("Error: %s(%d)\n", __FILE__, __LINE__);
        return 0;
    }
    do {
        stack[i] = (void *)(&buf[--i]);
    } while (i);

    // Testing starts...
    if (IsEmpty()) {
        printf("struct stack is empty\n");
    } else {
        printf("Oops, stack should be empty\n");
        PrintStruct();
        ret = 0;
        goto error;
    }
    for (i = 1; i <= 5; i++) {
        buf[i].val = i;
        buf[i].str = &stringData[i % sizeof(stringData)];
        buf[i].printFnc = _printStruct;
        if (!PushStruct(&buf[i])) {
            structType *val;
            if (IsFull()) {
                printf("Stack is full\n");
                break;
            } else {
                printf("Oops! PushStruct[%d] failed\n", i);
                ret = 0;
                goto error;
            }
            (void)PeekStruct(&val);
            _printStruct(val);
        }
    }

    PrintStruct();

    for (i = 1; i <= 5; i++) {
        structType *val;
        if (!PopStruct(&val)) {
            printf("PopStruct[%d] failed\n", i);
            break;
        } else {
            printf("Pop ");
            _printStruct(val);
        }
        if (PeekStruct(&val)) {
            printf("top is ");
            _printStruct(val);
        } else {
            printf("Stack is empty\n");
        }
    }

    for (i = 0; i < n; i++) {
        buf[i].val = i;
        buf[i].str = &stringData[i % sizeof(stringData)];
        buf[i].printFnc = _printStruct;
        if (!PushStruct(&buf[i])) {
            printf("Oops, PushStruct failed\n");
            ret = 0;
            goto error;
        }
    }

    PrintStruct();

    if (IsFull()) {
        printf("stack should be full\n");
    } else {
        printf("Oops, stack is not full\n");
        ret = 0;
        goto error;
    }
    for (i = 1; i <= n; i++) {
        structType *val;
        if (!PopStruct(&val)) {
            printf("Oops, PopStruct failed\n");
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
