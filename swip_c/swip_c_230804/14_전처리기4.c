// 14_��ó����4.c
#include <stdio.h>

// 1. ������: ������ �̸��� ���� ������ ������ �� �����ϴ�.
#if 0
#define SWAP(lhs, rhs) \
    int temp = lhs;    \
    lhs = rhs;         \
    rhs = temp

int main(void)
{
    int a = 10;
    int b = 20;

    SWAP(a, b);
    printf("%d, %d\n", a, b);

    return 0;
}
#endif

// 2. ������: ���� ������ ������ ���� ������,
//          �����ݷ��� ������� �ʾƵ� ������ ������ �߻����� �ʽ��ϴ�.
#if 0
#define SWAP(lhs, rhs)  \
    {                   \
        int temp = lhs; \
        lhs = rhs;      \
        rhs = temp;     \
    }

int main(void)
{
    int a = 10;
    int b = 20;
    int temp;

    SWAP(a, b)
        printf("%d, %d\n", a, b);

    return 0;
}
#endif

// - ��ũ�� �Լ����� �������� �������� �̷�����ų�,
// ���ο��� ������ �����ϰ� ���� ���,
// do-while(0)�� ���� �����ݴϴ�.
// - ��ũ�� �Լ� ������ �����ϴ� ������ �̸��� �浹�� �߻����� �ʵ���
//   �����ؾ� �մϴ�.

#define SWAP(lhs, rhs)    \
    do {                  \
        int __temp = lhs; \
        lhs = rhs;        \
        rhs = __temp;     \
    } while (0)

int main(void)
{
    int temp = 10;
    int b = 20;

    SWAP(temp, b);
    printf("%d, %d\n", temp, b);

    return 0;
}