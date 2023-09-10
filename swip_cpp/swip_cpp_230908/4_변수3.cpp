// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    // int x[3] = { 10, 20, 30 };
    int x[3] { 10, 20, 30 };
    // x의 타입은 무엇인가요?
    //  : int[3]

    // 문제점: x의 타입이 다른 타입으로 변경되면,
    //       아래 코드도 수정되어야 합니다.
    int* p = x; // &x[0]
    int e = x[0];
    int(*p2)[3] = &x;
}
#endif

// auto(Type deduction, C++11)
// 1) 컴파일 시간에 변수의 타입을 우항을 통해 결정합니다.
// 2) 의존성있는 타입을 표현할 때,
//    변수의 타입이 변경되어도, 코드를 수정할 필요가 없습니다.
// 3) 더 이상 사용하지 않는 지역 변수의 auto 키워드를 C++11부터
//    다른 의미로 사용합니다.
#if 0
int main()
{
    // auto int n;

    int x[3] { 10, 20, 30 };

    // auto a; // 컴파일 오류!
    //  - 반드시 우항(초기화)가 필요합니다.

    // int* p = x; // &x[0]
    auto p = x;

    // int e = x[0];
    auto e = x[0];

    // int(*p2)[3] = &x;
    auto p2 = &x;
}
#endif

// auto는 우항의 타입과 동일한 타입으로 만들어지지 않습니다.

int main()
{
    const int n = 42;
    // auto는 const가 따라오지 않습니다.
    // auto x = n;

    // const를 별도로 지정해야 합니다.
    const auto x = n;
    // x = 100; // x는 const int이기 때문에, 컴파일 오류!
}
