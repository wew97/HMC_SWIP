// 9_함수4.c
#include <stdio.h>

// 1. 지역 변수는 다른 함수에서 접근이 불가능합니다.
// 2. 전역 변수는 함수의 밖에 정의되는 변수 입니다.
//    전역 변수는 모든 함수에서 접근이 가능합니다.
// 3. 전역 변수는 초기화하지 않는 경우,
//    0으로 초기화됩니다.

// int n = 100; // 전역 변수
#if 0
int n;

void foo(void);

int main(void)
{
    int local; // 쓰레기값

    foo();
    return 0;
}

void foo(void)
{
    printf("%d\n", n);
}
#endif

// 4. 함수가 시작할 때 생성되고, 함수가 끝나면 사라집니다.
// 5. 프로그램이 시작할 때 초기화되고, 프로그램이 끝날 때까지 유지됩니다.

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