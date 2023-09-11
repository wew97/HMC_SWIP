// 12_nullptr.cpp
#include <iostream>
using namespace std;

void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }

// NULL은 정수 타입인지 포인터 타입인지 모호합니다.
// => 타입 안정성이 없습니다.
#if 0
int main()
{
    int* p = 0;
    // 정수 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.

    // int* p2 = 100; /* 에러! */

    // #define NULL (void*)0
    int* p2 = NULL;

    foo(0);
    foo(NULL);
}
#endif

// C++11, NULL을 대체하는 nullptr 이 도입되었습니다.
// => NULL 대신 nullptr을 사용하는 것이 좋습니다.

// : nullptr은 nullptr_t 타입입니다.
//  => 포인터 타입으로의 암묵적인 변환이 허용되고,
//     논리식에서 사용할 경우,
//     거짓으로 판단됩니다.

int main()
{
    int* p = nullptr;
    if (p) {
    }

    if (!p) {
    }

    foo(0);
    foo(nullptr);
}
