// foo.c
#include <stdio.h>

// ���� ���� / ���� �Լ��� �տ� static�� ���̸� ���� ������ �����ϴ�.
// => static(��� ���� ������)

static int count = 0;
// ���� ���� �տ� static ���̸�
// Internal linkage�� ����˴ϴ�.
// => �ٸ� ���Ͽ����� ������ �Ұ����ϰ�
//    ���� ���Ͽ����� ������ �����մϴ�.

static void goo(void)
{
    printf("goo\n");
}

void foo(void)
{
    goo();
    printf("count: %d\n", ++count);
}