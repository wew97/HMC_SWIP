// 8_배열.c
#include <stdio.h>

// 사용자에게 5개의 정수를 입력받고 싶습니다.
//  - 문제점: 각 변수의 이름이 다르기 때문에
//          반복문을 통해 코드를 일반화할 수 없습니다.
#if 0
int main(void)
{
    int a, b, c, d, e;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    printf("%d\n", e);

    return 0;
}
#endif

// int a, b, c, d, e;
// |----|xx|----|----|xx|----|----|
//   a        b    c      d    e
// - 메모리가 연속적으로 할당되는 것이 보장되지 않습니다.

// int a[5];
// |----|----|----|----|----|
//  a[0] a[1] a[2] a[3] a[4]
// - 동일한 이름을 통해 접근이 가능합니다.
//   => 반복문을 통해 일반화하는 것이 가능합니다.
// - 연속된 메모리가 할당되는 것이 보장됩니다.

#if 0
int main(void)
{
    int a[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
#endif

#if 0
int main(void)
{
    // int a[3]; // 초기화하지 않으면 쓰레기값을 가집니다.

    // int a[3] = { 1, 2, 3 };
    // int a[3] = { 1, 2, 3, 4 }; // 미정의 동작!

    // int a[3] = { 1, 2 }; // 허용되는 코드입니다.
    // 나머지는 0으로 초기화됩니다.

    // int a[3] = {}; // 표준이 아닙니다.
    // 반드시 1개 이상 초기화를 해야 합니다.

    // int a[3] = { 0 }; // OK!
    int a[3] = {
        1,
        3,
        2,
    }; // Trailing Comma => OK!

    for (int i = 0; i < 3; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
#endif

#if 0
int main(void)
{
    int a[] = { 10, 20 };
    // 초기화를 통해서 배열의 크기가 결정이 됩니다.

    printf("%zu\n", sizeof(a));
    // a의 타입은 무엇인가요?
    //  int[2]

    return 0;
}
#endif

// OCP
// => Open Close Principle
// => 개방 폐쇄 원칙
//   "확장에는 열려 있고, 수정에는 닫혀 있어야 한다."
//   "새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다."

//  * size_t len = sizeof(a) / sizeof(a[0]);
// 배열의 길이를 구하는 방법은 위의 방법을 사용해야 합니다.

// 배열의 길이를 구하는 방법
#if 0
int main(void)
{
    int a[20] = { 1, 2, 3, 4, 5 };

    // size_t len = sizeof(a) / sizeof(int);
    //  => 배열의 요소 타입이 변경될 경우, 코드는 수정되어야 합니다.

    size_t len = sizeof(a) / sizeof(a[0]);
    // sizeof의 결과는 size_t 이기 때문에
    // sizeof의 결과의 나눗셈도 size_t로 해야 한다.

    for (int i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
#endif

// int x[10 / 5]; // OK!
// 배열의 크기는 상수 표현식만 허용합니다.

// int x[sizeof(int) * 10];

#if 0
const int N = 10; // 상수
int x[N];
// 위의 코드는 C에서는 허용되지 않습니다.

int main(void)
{
    int n;
    scanf("%d", &n);

    // 아래처럼 사용하는 것은
    // 표준이 아닙니다.
    // => 배열의 크기는 실행 시간이 컴파일 시간에 결정되어야 합니다.
#if 0
    int x[n];
    printf("%zu\n", sizeof(x) / sizeof(x[0]));
#endif

    return 0;
}
#endif

#if 0
// 상수
// - 핵심은 C의 상수(const로 지정된 변수)는 런타임 상수입니다.
//   C++은 상수를 사용할 때, 컴파일 타임 상수도 될 수 있고,
//   런타임 상수도 될 수 있습니다.

// - 런타임 상수
//  : 실행 시간에 변경할 수 없는 변수
//    런타임 상수의 값을 읽는 것은 메모리로부터 값을 읽어야 합니다.

// - 컴파일 타임 상수
//  : 컴파일러가 컴파일 타임 상수에 대한 모든 접근을
//    상수값으로 변경합니다.
//    메모리에 대한 접근이 없기 때문에
//    빠르게 처리가 가능합니다.
int main(void)
{
    const int N1 = 10; // 컴파일 타임 상수
    printf("%d\n", N1);

    int n;
    scanf("%d", &n);
    const int N2 = n; // 런타임 상수
    printf("%d\n", N2);

    return 0;
}
#endif