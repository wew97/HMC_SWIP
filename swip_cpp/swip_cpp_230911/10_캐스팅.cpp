// 10_캐스팅.cpp
#include <iostream>
using namespace std;

#include <cstdlib>

// C++에서 명시적인 캐스팅이 필요한 경우가 있습니다.
// 1) Uniform Initialization
//     - 실수 -> 정수
//     - 큰 표현 범위 정수 -> 작은 표현 범위 정수
// 2) void* -> 구체적인 포인터 타입
//     - C 에서는 암묵적인 변환이 허용되지만, C++에서는 암묵적인 변환이
//       허용되지 않습니다.
// 3) 메모리 재해석
//     - 포인터 타입간의 변환
// 4) const T* -> T*
//     - const를 제거하는 연산도 명시적인 캐스팅이 필요합니다.

// * C 캐스팅 연산자의 문제점
//  => 용도와 목적에 따라 동일한 연산자를 사용하므로,
//     목적을 알기 어렵다.
//  => C++은 용도와 목적에 따라 구분해서 사용해야 합니다.
#if 0
int main()
{
    double d = 3.14;
    int n1 { (int)d };

    long long l = 100000LL;
    int n2 { (int)l };

    int* p = (int*)malloc(sizeof(int));

    int x = 0x12345678;
    char* px = (char*)&x;
    printf("%X %X %X %X\n", px[0], px[1], px[2], px[3]);

    int x2 = 100;
    const int* px2 = &x2;

    // const int* -> int*
    int* pn = (int*)px2;
}
#endif

// C++은 캐스팅 연산자 - 4가지
// 1) static_cast
//  : 가장 기본적인 C++의 캐스팅 연산자입니다.
//  "연관성 있는 타입간의 안전한 캐스팅에서 사용합니다."
//   : 실수 -> 정수
//     큰 표현 범위 정수 -> 작은 표현 범위 정수
//     void* -> T*

// 2) reinterpret_cast
//  : 메모리를 재해석하는 목적으로 사용하는 연산자입니다.

// 3) const_cast
//  : 메모리의 상수성을 제거해서, 타입의 불일치 문제를 해결하기 위한
//    용도로 사용합니다.

// 4) dynamic_cast
//  : 이후 시간에 살펴봅니다.

int main()
{
    double d = 3.14;
    int n1 { static_cast<int>(d) };

    long long l = 10000LL;
    int n2 { static_cast<int>(l) };

    void* p = &n1;
    int* pn = static_cast<int*>(p);

    int x = 0x12345678;
    // char* px = static_cast<char*>(&x);
    char* px = reinterpret_cast<char*>(&x);
    printf("%X %X %X %X\n", px[0], px[1], px[2], px[3]);

    long long* pl = reinterpret_cast<long long*>(&x);
    // *pl = 1000000000000LL; /* 미정의 동작 */

    const int* pc = &n1;
    // int* pn2 = static_cast<int*>(pc);
    // int* pn2 = reinterpret_cast<int*>(pc);
    int* pn2 = const_cast<int*>(pc);
}
