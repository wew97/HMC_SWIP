// 13_���������Ÿ��6.c
#include <stdio.h>

// 1. ����ü Ÿ��(����� ���� Ÿ��)�� ũ���
//    ����� ���ؼ� �����˴ϴ�.
// => ����ü Ÿ���� ũ��� ����� ���հ� ��ġ���� ���� �� �ֽ��ϴ�.
//   "����ü �е�"

struct AAA {
    int a;
    char b;
    double c;
};

// 0       4       8              16
// |a|a|a|a|b|p|p|p|c|c|c|c|c|c|c|c|-|-|-|-|-|-|-|-|-|-|-|-|

struct BBB {
    char a;
    double b;
    int c;
};
// 0       4       8              16              24
// |a|p|p|p|p|p|p|p|b|b|b|b|b|b|b|b|c|c|c|c|p|p|p|p|-|-|-|-|

// int a
// 0       4       8
// |x|x|p|p|a|a|a|a|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|

// double d;
// 0       4       8
// |x|x|p|p|p|p|p|p|d|d|d|d|d|d|d|d|-|-|-|-|-|-|-|-|-|-|-|-|
//-----
// => CPU�� �޸𸮿� ȿ�������� �����ϱ� ���ؼ�
//    ������ ��ġ�� �� �� ����(����̸�Ʈ)�� ����˴ϴ�.
//    ���ķ� ���ؼ�, �е��� �߻��մϴ�.

int main(void)
{
    printf("%zu\n", sizeof(struct AAA));
    printf("%zu\n", sizeof(struct BBB));

    int a = 10;
    double b = 3.14;

    printf("%lu\n", (unsigned long)&a);
    printf("%lu\n", (unsigned long)&b);

    return 0;
}