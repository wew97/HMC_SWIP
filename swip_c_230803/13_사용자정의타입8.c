// 13_사용자정의타입8.c
#include <stdio.h>

// 1. struct
// 2. union
// 3. enum(열거체)

#if 0
enum ProcessState {
    TASK_RUNNING = 100,
    TASK_STOPPED = 200,
    TASK_WAITING = 300
    // 열거 상수
};

enum {
    ARRAY_SIZE = 10 // 상수 - 컴파일 타임 상수
};

const int array_size = 10; // 상수
// C 에서는 const 상수는 런타임 상수이기 때 문에,
// 상수 표현식으로 사용할 수 없습니다.

// C 에서는 전역 변수나 정적 지역 변수의 초기화에서
// 상수 표현식이 필요합니다.

int main(void)
{
    // int arr[array_size]; => 컴파일 오류!
    int arr[ARRAY_SIZE];

    int task_state = TASK_RUNNING;

    return 0;
}
#endif

// 심볼링 상수
// => 상수에 이름을 부여하는 문법
// 1) const
//  : 다양한 타입에 대해서 상수를 지정할 수 있지만,
//    런타임 상수이기 때문에, 상수 표현식에서는 사용이 불가능합니다.

// 2) enum
//  : 컴파일 타임 상수이기 때문에, 상수 표현식에서 사용할 수 있습니다.
//    정수 상수만 사용이 가능합니다.

// 3) 매크로

// 한계점: 정수 상수만 만들 수 있습니다.
enum State {
    STATE_A = 100,
    STATE_B,
    STATE_C
}; // 자동으로 1씩 증가

int main(void)
{
    printf("%d\n", STATE_A); // 100
    printf("%d\n", STATE_B); // 101
    printf("%d\n", STATE_C); // 102

    return 0;
}