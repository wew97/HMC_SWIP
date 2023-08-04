// 14_��ó����.c

// 1. ���� ����
// : a.c
//    ��ó�� => ������|------
//   b.c                 |-> ��ũ(a.o + b.o) -> a.exe(���� ����)
//    ��ó�� => ������|------

// 2. ��ó����(preprocessor)
//  - �ؽ�Ʈ ó��
// 1) #include
//     => ������ ��� ������ ���� �ҽ� �ڵ忡 �����ݴϴ�.
//     => ��� ������ �ٸ� ���Ͽ��� �����ϴ� �Լ��� ���� / ���� ������ ������
//        ������ �ֽ��ϴ�.
//     => typedef�� ���ؼ� �ۼ��� Ÿ���� ����
//     => struct, union, enum�� ���ؼ� �����ϴ� Ÿ���� ����

#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(void)
{
    int result = add(10, 20);
    printf("%d\n", result);

    struct Complex a = { .real = 10, .image = 3 };
    struct Complex b = { .real = 10, .image = 3 };

    struct Complex r;
    Add(&a, &b, &r);

    PrintComplex(&r);

    return 0;
}