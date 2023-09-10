// 7_함수6.cpp
#include <iostream>
using namespace std;

#if 0
int add(int a, int b) { return a + b; }

int (*foo())[3]
{
    static int x[3] = { 10, 20, 30 };
    return &x; // int(*)[3]
}

int (*goo())(int, int)
{
    return &add; // int(*)(int, int)
}
#endif

// C++11, 함수를 정의하는 새로운 방법을 제공합니다.
//   : Trailing Return Type

// int add(int a, int b) { return a + b; }
auto add(int a, int b) -> int { return a + b; }

// int (*foo())[3]
// auto foo() -> int (*)[3]
auto foo()
{
    static int x[3] = { 10, 20, 30 };
    return &x; // int(*)[3]
}

// auto goo() -> int (*)(int, int)
auto goo()
{
    return &add; // int(*)(int, int)
}

// Trailnig Return Type
// 1) 복잡한 반환 타입을 표현할 때 유용합니다.
// 2) 반환 타입을 추론할 수 있습니다.

int main()
{
}
