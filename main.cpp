#include <stdio.h>
#include "stack.h"
#include <string.h>

int main()
{
    StackErr_t err = NO_ERRORS;
    stack_t stk = {};

    IF_ERROR(StackInit(&stk, 2), stk);

    IF_ERROR(StackRead(&stk, &err), stk);

    IF_ERROR(StackDump(stk), stk);
    IF_ERROR(StackDestroyer(&stk), stk);

    return 0;
}

//-----сделать условную компиляцию
//stackbigger добавить параметр для нового значения capacity
//define error файла
//-----канарейки в структуре
//создать папочку с калькулятором
//*дополнить калькулятор: сделать массив структур для команд, создавать массив union
//сделать калькулятор через массив union