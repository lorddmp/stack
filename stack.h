#ifndef STACK
#define STACK

#include <stdlib.h>

#define NAME_INPUT_FILE "stack_commands.txt"
#define NAME_ERROR_FILE "errors_report.txt"
#define NAME_BYTECODE_FILE "bytecode_file"

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
    ERROR_OPEN_INPUTFILE = 1,
    ERROR_OPEN_ERRORFILE = 2,
    ERROR_CREATING_BYTYCODE_FILE = 3,
    ZERO_PTR_STACK = 4,
    ZERO_PTR_DATASTACK = 5,
    ILLEGAL_CAPACITY = 6,
    EMPTY_STACK = 7,
    ILLEGAL_SIZE = 8,
    POISON_ERROR = 9,
    CANARY_DEATH = 10,
    ERROR_CALLOC = 11,
    ERROR_REALLOC = 12,
    ERROR_PUSH_NUM = 13,
    ILLEGAL_COMMAND = 14,
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