#ifndef OPERATIONS
#define OPERATIONS

#include <string.h>
#include "../stack.h"

StackErr_t _Stack_Read(stack_t* stk, StackErr_t* err, const char* FILENAME, const int NUM_STRING, const char* FUNCNAME);

#endif