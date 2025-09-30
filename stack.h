#ifndef STACK
#define STACK

#include <stdlib.h>

#define INPUT_FILE "stack_commands.txt"

#define POISON 7062007
#define CANARY1 0xDEDDED
#define CANARY2 0xDADDAD

#define IF_ERROR_FUNC(arg)  \
    if (arg)\
    {\
        _Stack_Dump(*stk, FILENAME, NUM_STRING, FUNCNAME);\
        _Stack_Destroyer(stk, FILENAME, NUM_STRING, FUNCNAME);\
        return *err;\
    }

typedef double data_t;
typedef struct stack_str
{
    data_t* data;
    int size;
    int capacity;
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
    ERROR_OPEN_INPUTFILE = 14
};


StackErr_t _Stack_Init(stack_t* stk, int capacity, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Push(stack_t* stk, data_t value, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

data_t _Stack_Pop(stack_t* stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME,  StackErr_t *err);

StackErr_t _Stack_Dump(stack_t stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Verify(stack_t* stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Destroyer(stack_t* stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Bigger(stack_t* stk, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

StackErr_t _Stack_Read(stack_t* stk, StackErr_t* err, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

int _Is_Zero(double a);

#endif