// 9_함수.c
#include <stdio.h>

// * 코드를 중복해서, 여러곳에서 사용할 경우
//   요구사항의 변경이나 추가로 인해서 코드의 변경이 여러곳에서
//   이루어져야 합니다.
//   => 유지보수 비용의 증가!
//   * SRP(Single Reponsibility Principle)
//   : 단일 책임의 원칙
//   - 단 하나의 책임을 가져야 한다.
//   * DRY(Don't Repeat Yourself)
#if 0
int main(void)
{
    printf("[메뉴]\n");
    printf("1. 짜장면\n");
    printf("2. 짬뽕\n");
    printf("3. 라면\n");
    printf("4. 칼국수\n");

    printf("[메뉴]\n");
    printf("1. 짜장면\n");
    printf("2. 짬뽕\n");
    printf("3. 라면\n");
    printf("4. 칼국수\n");

    printf("[메뉴]\n");
    printf("1. 짜장면\n");
    printf("2. 짬뽕\n");
    printf("3. 라면\n");
    printf("4. 칼국수\n");

    return 0;
}
#endif

// 함수: 입력을 받아서, 주어진 연산을 수행한 후 결과를 반환하는
//      코드의 집합
// C에서 함수를 만드는 방법
// 함수의_결과_타입 함수의_이름(함수의 입력 ...)

// 결과: void
// 입력: void
// 이름: PrintMenu
#if 0
void PrintMenu(void)
{
    printf("[메뉴]\n");
    printf("1. 짜장면\n");
    printf("2. 짬뽕\n");
    printf("3. 라면\n");
}

int main(void)
{
    PrintMenu();

    PrintMenu();

    PrintMenu();
}
#endif

// 함수의 결과 타입: int
// 함수의 입력: int a, int b
// 함수의 이름: Add
#if 0
int Add(int a, int b) { return a + b; }
// 함수의 결과는 return을 통해서 전달합니다.

// int Add(int a, int b) { } /* 미정의 동작 */

int main(void)
{
    int result;

    result = Add(10, 20);
    //      -------------
    //          30

    printf("result: %d\n", result);

    return 0;
}
#endif

// 입력받은 N(양수)까지의 합을 출력하는 함수를 만들어봅시다.
#if 0
void PrintSum(int n)
{
    // Early exit
    // => MISRA에서는 허용하지 않습니다.
    if (n <= 0) {
        return;
        // void를 반환하는 함수(반환값이 없는 함수)에서도
        // return을 통해 함수를 명시적으로 종료할 수 있습니다.
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum: %d\n", sum);
}
#endif

// MISRA C++ / AutoSAR => MISRA C++ 202x

// 함수가 단일 종료 지점을 갖도로 만들어야 합니다 => MISRA C 2023
void PrintSum(int n)
{
    if (n > 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        printf("Sum: %d\n", sum);
    }
}

int main(void)
{

    return 0;
}