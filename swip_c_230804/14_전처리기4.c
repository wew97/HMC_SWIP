// 14_전처리기4.c
#include <stdio.h>

// 1. 문제점: 동일한 이름의 지역 변수를 생성할 수 없습니다.
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

// 2. 문제점: 지역 변수를 생성할 수는 있지만,
//          세미콜론을 사용하지 않아도 컴파일 오류가 발생하지 않습니다.
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

// - 매크로 함수에서 여러개의 문장으로 이루어지거나,
// 내부에서 변수를 생성하고 있을 경우,
// do-while(0)를 통해 묶어줍니다.
// - 매크로 함수 내에서 정의하는 변수의 이름은 충돌이 발생하지 않도록
//   주의해야 합니다.

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