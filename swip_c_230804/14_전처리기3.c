// 14_전처리기3.c
#include <stdio.h>

#if 0
// 심볼릭 상수
// 1) const
//  : 상수 표현식이 아닙니다.

// 2) enum
//  : 상수표현식 입니다.
//    오직 정수 상수만 표현할 수 있습니다.

// 3) #define
//  : 상수 표현식 입니다.
//    전처리 이후에 심볼의 정보가 사라집니다.
//    컴파일러가 심볼의 정보를 알 수 없습니다.

// 상수 표현식으로 사용할 수 있습니다.
#define PI 3.14
#define BUFSIZE 1024

int main(void)
{
    int x[BUFSIZE];

    return 0;
}
#endif

// 전처리기
// 1. 함수 호출은 오버헤드가 있습니다.
// 2. 함수 호출의 오버헤드를 제거하기 위해서,
//    매크로 함수를 사용하였습니다.

// 인자를 전달받아 치환하는 매크로를 "매크로 함수"라고 합니다.
#if 0
#define SQUARE(x) x* x

int Square(int x) { return x * x; }

int main(void)
{
    int a = 10;
    printf("%d\n", Square(a));
    printf("%d\n", SQUARE(a));

    printf("%d\n", a * a);

    return 0;
}
#endif

// 매크로 함수는 잘못 사용할 경우,
// "우선순위" 문제가 발생합니다.
#if 0
int square(int x) { return x * x; }
int dbl(int x) { return x + x; }

// 1) 매크로의 인자의 치환영역을 괄호로 감싸주어야 합니다.
// #define SQUARE(x) x * x
// #define SQUARE(x) (x) * (x)
#define SQUARE(x) ((x) * (x))

// 2) 매크로 함수의 전체 치환 영역을 괄호로 감싸주어야 합니다.
// #define DBL(x) (x) + (x)
#define DBL(x) ((x) + (x))

int main(void)
{
    int x = 10;
    int result = 0;

    result = DBL(x) * DBL(x);
    printf("result: %d\n", result);

    result = dbl(x) * dbl(x);
    printf("result: %d\n", result);

    result = SQUARE(x + x);
    printf("result: %d\n", result);

    result = square(x + x);
    printf("result: %d\n", result);

    return 0;
}
#endif

int square(int x) { return x * x; }
int dbl(int x) { return x + x; }

// 매크로 함수의 인자가 하나의 식에서 두번이상 치환되는 경우,
// ++, --의 연산이 전달될 경우, 미정의 동작이 발생합니다.
// => 반드시 매크로 함수를 사용할 때, 인자에서 연산을 수행하면 안됩니다.

#define SQUARE(x) ((x) * (x))
#define DBL(x) ((x) + (x))

int main(void)
{
    int x = 10;
    printf("%d\n", square(++x));

    // printf("%d\n", SQUARE(++x));
    //             (++x) * (++x) /* 미정의 동작 */

    ++x; // 반드시 분리해야 합니다.
    printf("%d\n", SQUARE(x));

    return 0;
}