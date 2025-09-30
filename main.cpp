#include <stdio.h>
#include "stack.h"

#define StackInit(stk, capacity) _Stack_Init(stk, capacity, __FILE__, __LINE__, __func__)
#define StackPush(stk, num) _Stack_Push(stk, num, __FILE__, __LINE__, __func__)
#define StackPop(stk, err) _Stack_Pop(stk, __FILE__, __LINE__, __func__, err)
#define StackDestroyer(stk) _Stack_Destroyer(stk, __FILE__, __LINE__, __func__)
#define StackDump(stk) _Stack_Dump(stk, __FILE__, __LINE__, __func__)
#define StackRead(stk, err) _Stack_Read(stk, err, __FILE__, __LINE__, __func__)

#define IF_ERROR(arg)  \
    if (arg)\
    {\
        StackDump(stk);\
        StackDestroyer(&stk);\
        return 0;\
    }

int main()
{
    StackErr_t err = NO_ERRORS;
    stack_t stk = {};

    IF_ERROR(StackInit(&stk, 7));

    IF_ERROR(StackRead(&stk, &err));

    IF_ERROR(StackDump(stk));
    IF_ERROR(StackDestroyer(&stk));


    return 0;
}