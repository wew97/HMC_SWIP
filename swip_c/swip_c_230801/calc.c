// calc.c
#include "calc.h"
// : �Լ��� ������ ����� ���� �����ؾ� �մϴ�.

// => �Ʒ� �Լ��� �����ϴ� �����
//    �ڽ��� �����ϴ� �Լ��� ������ ������
//    ��� ������ ���ؼ� �����ؾ� �մϴ�.

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