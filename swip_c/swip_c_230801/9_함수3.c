// 9_�Լ�3.c
#include <stdio.h>

#include "calc.h"

int main(void)
{
    int result = Add(10, 20);
    printf("result: %d\n", result);

    return 0;
}

// $ nm 9_�Լ�3.o
//                  U _Add
// 0000000000000000 T _main
//                  U _printf