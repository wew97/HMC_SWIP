// 10_������4.c
#include <stdio.h>

// 1. �迭�� �Լ��� ������ ��,
//    �迭 ��ü�� �����ؼ� �������� �ʽ��ϴ�.
//    => ������ ���, �迭�� ũ�Ⱑ Ŀ������ ������尡 �ֱ� �����Դϴ�.
#if 0
void Inc(int x[5]) // void Inc(int* x)
{
    for (int i = 0; i < 5; i++) {
        x[i] += 10;
        // *(x + i) += 10;
    }
}

int main(void)
{
    int x[5] = { 10, 20, 30, 40, 50 };

    Inc(x); // Inc(&x[0])

    for (int i = 0; i < 5; i++) {
        printf("%3d", x[i]);
    }
    printf("\n");

    return 0;
}
#endif

#if 0
int main(void)
{
    int x[3] = { 10, 20, 30 };
    // x�� Ÿ���� �����ΰ���?
    //   int[3]

    // * �迭�� �̸�(x)�� �迭�� ù��° ������ ���� �ּҷ� �ؼ��˴ϴ�.
    //  => Decay(�νĵȴ�)
    printf("%p\n", &x[0]);
    printf("%p\n", x);

    return 0;
}
#endif

// * �迭�� �̸��� �迭�� ù��° ������ ���� �ּҷ� �ؼ��˴ϴ�.
//  => Decay
//  => ����
//    1) sizeof
#if 0
// void foo(int x[3]) // void foo(int* x)
void foo(int* x)
{
    printf("foo: %zu\n", sizeof(x));
}

int main(void)
{
    int x[3] = { 10, 20, 30 };

    printf("main: %zu\n", sizeof(x));
    foo(x);

    return 0;
}
#endif

// �������� ��� ����
//  1) ������ + ���
//  2) ������ - ���
//  3) ������ - ������
//  4) ������ + ������ ������ ������� �ʽ��ϴ�.
#if 0
int main(void)
{
    // T* p;
    // p + 1 => p + sizeof(T) * 1
    // p + 2 => p + sizeof(T) * 2

    int x[5] = { 10, 20, 30, 40, 50 };
    int* px = &x[0];
    printf("%lu\n", (unsigned long)px);
    printf("%lu\n", (unsigned long)(px + 1));

    double d[3] = { 3.14, 5.5, 1.1 };
    double* pd = &d[0];
    printf("%lu\n", (unsigned long)pd);
    printf("%lu\n", (unsigned long)(pd + 1));

    return 0;
}
#endif

// : x[N] ==> *(x + N)
// &x[0] ==> &*(x + 0) ==> x + 0 ===> x
//          ---
//          ���

int main(void)
{
    //           p   p+1
    //           |    |
    int x[5] = { 10, 20, 30, 40, 50 };

    // int* p = &x[0];
    int* p = x;
    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));
    printf("%d\n", p[0]);
    printf("%d\n", p[1]);
    printf("%d\n", p[2]);

    printf("%d\n", *x);
    printf("%d\n", *(x + 1));
    printf("%d\n", *(x + 2));
    printf("%d\n", x[0]);
    printf("%d\n", x[1]);
    printf("%d\n", x[2]);

    return 0;
}