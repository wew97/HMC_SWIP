// calc.c
#include "calc.h"
// : 함수의 선언을 헤더를 통해 포함해야 합니다.

// => 아래 함수를 제공하는 사람이
//    자신이 제공하는 함수의 선언의 정보를
//    헤더 파일을 통해서 제공해야 합니다.

int Add(int a, int b)
{
    return a + b;
}

void goo(void)
{
    foo();
}

void foo(void)
{
    goo();
}

// $ nm calc.o
//  0000000000000000 T _Add