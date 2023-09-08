// 13_사용자정의타입10.c
#include <stdio.h>

#if 0
typedef struct User {
    char name[32];
    int age;
} USER; // USER == struct User

typedef struct Person {
    char name[32];
    int age;
} PERSON;
// 사용자정의 타입은 멤버가 동일하더라도, 태그가 다르면 다른 타입입니다.

int main(void)
{
    USER user = { .name = "Tom", .age = 42 };
    PERSON person = { .name = "Bob", .age = 100 };

    // user = person;
    // => 다른 타입이기 때문에 컴파일 오류가 발생합니다.

    return 0;
}
#endif

#if 0
typedef struct {
    char name[32];
    int age;
} USER;

typedef struct {
    char name[32];
    int age;
} PERSON;
// 태그가 없는 사용자 정의 타입은 다른 타입입니다.

int main(void)
{
    USER user = { .name = "Tom", .age = 42 };
    PERSON person = { .name = "Bob", .age = 100 };

    // user = person;

    return 0;
}
#endif

#if 0
// union 타입의 크기는 내부의 가장 큰 크기를 가지는 멤버에 의해서 결정됩니다.
typedef union Data {
    int n;
    double d;
} DATA;
// 마지막에 사용한 멤버가 유효한 데이터입니다.

int main(void)
{
    printf("%zu\n", sizeof(union Data));
    // union Data data;
    // DATA data = { .n = 42 }; // OK
    // DATA data = { .n = 42, .d = 3.14 }; // 미정의 동작
    DATA data = { .d = 3.14 }; // OK

    // - union 초기화는 가장 첫번째 멤버에 대한 초기화만 합니다.
    DATA data2 = { 42 };

    // - 멤버 와이즈 초기화를 사용할 경우, 하나의 멤버에 대한 초기화만 허용됩니다.

    data.n = 100;
    printf("%d\n", data.n);

    printf("%lf\n", data.d);

    return 0;
}
#endif

// 열거체는 정수형 상수를 정의할 수 있습니다.
// NO => 0
// OK => 1

#if 0
enum State {
    NO,
    OK
};

enum TaskState {
    STOPPED,
    RUNNING
};

int main(void)
{
    // int state = OK; // OK!
    enum State state = OK; // OK! => 권장됩니다.
    printf("%d\n", state);

    state = NO;
    printf("%d\n", state);

    state = STOPPED;
    // 다른 타입의 열거 상수를 대입하는 것을 컴파일 경고를 통해서
    // 확인할 수 있습니다.

    return 0;
}
#endif

#if 0
// 열거 상수는 다른 타입이어도 고유해야 합니다.
// 열거 상수를 정의할 때, 접두어를 통해서 이름 충돌을 방지해야 합니다.
#include <limits.h>
// INT_MAX

enum State {
    STATE_OK,
    STATE_NO
};

enum TaskState {
    TASK_STATE_OK = INT_MAX,
    // 정수(int) 타입에서 오버플로우의 문제가 발생하지 않아야 합니다.
    TASK_STATE_NO
};

int main(void)
{
    printf("%zu\n", sizeof(enum State));
    printf("%zu\n", sizeof(enum TaskState));

    return 0;
}
#endif