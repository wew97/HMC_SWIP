// 10_포인터4.c
#include <stdio.h>

// 1. 배열을 함수로 전달할 때,
//    배열 전체를 복사해서 전달하지 않습니다.
//    => 복사할 경우, 배열의 크기가 커질수록 오버헤드가 있기 때문입니다.
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
    // x의 타입은 무엇인가요?
    //   int[3]

    // * 배열의 이름(x)은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
    //  => Decay(부식된다)
    printf("%p\n", &x[0]);
    printf("%p\n", x);

    return 0;
}
#endif

// * 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
//  => Decay
//  => 예외
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

// 포인터의 산술 연산
//  1) 포인터 + 상수
//  2) 포인터 - 상수
//  3) 포인터 - 포인터
//  4) 포인터 + 포인터 연산은 허용하지 않습니다.
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
//          상쇄

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