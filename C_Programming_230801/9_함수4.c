// 9_�Լ�4.c
#include <stdio.h>

// 1. ���� ������ �ٸ� �Լ����� ������ �Ұ����մϴ�.
// 2. ���� ������ �Լ��� �ۿ� ���ǵǴ� ���� �Դϴ�.
//    ���� ������ ��� �Լ����� ������ �����մϴ�.
// 3. ���� ������ �ʱ�ȭ���� �ʴ� ���,
//    0���� �ʱ�ȭ�˴ϴ�.

// int n = 100; // ���� ����
#if 0
int n;

void foo(void);

int main(void)
{
    int local; // �����Ⱚ

    foo();
    return 0;
}

void foo(void)
{
    printf("%d\n", n);
}
#endif

// 4. �Լ��� ������ �� �����ǰ�, �Լ��� ������ ������ϴ�.
// 5. ���α׷��� ������ �� �ʱ�ȭ�ǰ�, ���α׷��� ���� ������ �����˴ϴ�.

int call_count = 0;
void foo(void)
{
    // int call_count = 0;

    printf("foo: %d\n", ++call_count);
}

int main(void)
{
    foo(); // 1
    foo(); // 2

    return 0;
}