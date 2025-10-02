#ifndef STACK
#define STACK

#include <stdlib.h>

#define NAME_INPUT_FILE "../stack_commands.txt"
#define NAME_ERROR_FILE "errors_report.txt"

#define ZASHITA

#ifdef ZASHITA

#define VERIF(stk) _Stack_Verify(stk, FILENAME, NUM_STRING, FUNCNAME)

#else

#define VERIF(stk) NO_ERRORS 

#endif

#define StackInit(stk, capacity) _Stack_Init(stk, capacity, __FILE__, __LINE__, __func__)
#define StackPush(stk, num) _Stack_Push(stk, num, __FILE__, __LINE__, __func__)
#define StackPop(stk, err) _Stack_Pop(stk, __FILE__, __LINE__, __func__, err)
#define StackDestroyer(stk) _Stack_Destroyer(stk, __FILE__, __LINE__, __func__)
#define StackDump(stk) _Stack_Dump(stk, __FILE__, __LINE__, __func__)
#define StackRead(stk, err) _Stack_Read(stk, err, __FILE__, __LINE__, __func__)

#define IF_ERROR(arg, stk)      \
    if (arg)                    \
    {                           \
        StackDump(stk);         \
        StackDestroyer(&stk);   \
        return NO_ERRORS;       \
    }

typedef double data_t;
#define SPEC "%lg"

typedef struct stack_str
{
    int can_struck1;
    data_t* data;
    int size;
    int capacity;
    int can_struck2;
} stack_t;

enum StackErr_t {
    NO_ERRORS = 0,
    ZERO_PTR_STACK = 1,
    ZERO_PTR_DATASTACK = 2,
    ERROR_CALLOC = 3,
    ILLEGAL_CAPACITY = 4,
    NO_ELEMENTS = 5,
    ILLEGAL_SIZE = 6,
    ILLEGAL_VALUE = 7,
    ILLEGAL_FUNC_MODE = 8,
    EMPTY_STACK = 9,
    POISON_ERROR = 10,
    ERROR_OPEN_ERRORFILE = 11,
    CANARY_DEATH = 12,
    ERROR_REALLOC = 13,
    ERROR_OPEN_INPUTFILE = 14,
    ERROR_PUSH_NUM = 15,
};


StackErr_t _Stack_Init(stack_t* stk, int capacity, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Push(stack_t* stk, data_t value, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

data_t _Stack_Pop(stack_t* stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME,  StackErr_t *err);

StackErr_t _Stack_Dump(stack_t stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Verify(stack_t* stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Destroyer(stack_t* stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Bigger(stack_t* stk, int capacity, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

int _Is_Zero(double a);

#endif