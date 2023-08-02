// 9_함수2.c
#include <stdio.h>

// C99 표준 이후로 선언되지 않은 함수에 대한 호출은
// 허용되지 않습니다.

// 선언
// - 함수의 프로토타입

int Add(int a, int b); // 1 - 인자의 이름을 명시해야 합니다.
// int Add(int, int);  // 2

int main(void)
{
    printf("Add: %d\n", Add(10, 20));

    return 0;
}

// * 함수의 선언만 존재하고, 정의가 제공되지 않는다면
//   컴파일은 성공하지만, 링크 과정에서 함수의 구현을 연결할 수 없다는
//   링크 오류가 발생합니다.

// 함수의 정의
// int Add(int a, int b) { return a + b; }