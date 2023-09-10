// 4_변수.cpp
#include <iostream>
using namespace std;

// C의 사용자 정의 타입
// 1) struct
// 2) union
// 3) enum

#if 0
struct complex {
    // --------
    //      tag

    int re;
    int im;
};

union data {
    int i32;
    long long i64;
};

enum task_state {
    TASK_RUNNING,
    TASK_STOPPED
};

// C 에서는 struct, union, enum을 명시해야 합니다.
int main()
{
    struct complex c1;
    union data d1;
    enum task_state s1;
}
#endif

// C++에서 사용자 정의 타입(struct, union, enum)의 변수를 만들 때,
// 더 이상 struct, union, enum을 명시할 필요가 없습니다.
// => 사용자 정의 타입의 태그가 타입입니다.
struct complex {
    int re;
    int im;
};
// typedef struct complex COMPLEX;
//  : C++에서는 굳이 타입 별칭을 지정할 필요가 없습니다.

union u_data {
    int i32;
    long long i64;
};

enum task_state {
    TASK_RUNNING,
    TASK_STOPPED
};

// 보일러플레이트(상용구)
//  : 반드시 필요하지만 반복적으로 발생하는 코드

int main()
{
    // struct complex c1;
    complex c1;
    // union u_data d1;
    u_data d1;

    // enum task_state s1;
    task_state s1;
}
