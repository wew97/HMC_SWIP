// 8_제어문.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };
    // for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {

    constexpr int len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; i++) {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        cout << e << endl;
    }
}
#endif

int process()
{
    return 0;
    // 성공시 0, 실패시 0이 아닌 값
}
// 실패 가능성이 존재하는 함수를 사용한 경우,
// 반드시 반환값을 통해 오류 여부를 검증해야 합니다

int* process2()
{
    // 실패할 경우, NULL을 반환합니다.
    return NULL;
}

enum TaskState {
    TASK_RUNNING,
    TASK_STOPPED
};

TaskState GetState() { return TASK_RUNNING; }

// C++17, If/switch statement with initializer
int main()
{
    switch (TaskState state = GetState(); state) {
    case TASK_RUNNING:
        break;
    case TASK_STOPPED:
        break;
    default:
        break;
    }

    if (int ret = process(); ret != 0) {
        // ...
    }

    if (int* ret = process2(); ret != 0) {
    }
}

#if 0
int main()
{
    int ret = process();
    if (ret != 0) {
        // ...
    }

    int* ret2 = process2();
    if (ret2 != 0) {
    }
}
#endif
