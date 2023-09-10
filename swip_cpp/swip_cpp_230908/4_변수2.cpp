// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

#if 0
int main()
{
    // Copy Initialization
    int n1 = 42;
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization
    int n2(42);
    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

// C++11, Uniform Initialization(일관된 초기화)
#if 0
int main()
{
    // Copy Initialization
    int n1 = { 42 }; // !

    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization
    int n2 { 42 }; // !

    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

// C/C++
// - 실수 타입이 정수 타입으로의 암묵적인 변환이 허용됩니다.
// - 더 큰 표현 범위의 정수 타입이 더 작은 표현 범위의 정수 타입으로의
//   암묵적인 변환이 허용됩니다.

// => 정수의 Overflow는 많은 문제의 원인입니다.
//    위험합니다.

#if 0
int main()
{
    double d = 123123213123312.3;

    int n1(d); // Overflow
    cout << n1 << endl;

    long long l = 1231231289039012321LL;
    cout << l << endl;

    int n2(l);
    cout << n2 << endl;
}
#endif

// Uniform Initialization
// => Preventing Narrow
// => 실수가 정수로의 암묵적인 변환과 더 큰 표현 범위를 가지는 정수가
//    더 작은 표현범위를 가지는 정수로의 암묵적인 변환을 허용하지 않습니다.
//  : 명시적인 변환을 사용해야 합니다.
int main()
{
    double d = 123123213123312.3;

    if (d > INT_MAX || d < INT_MIN) {
        cout << "Overflow" << endl;
    } else {
        int n1 { (int)d };
        cout << n1 << endl;
    }

    long long l = 1231231289039012321LL;

    if (l > INT_MAX || l < INT_MIN) {
        cout << "Overflow" << endl;
    } else {
        int n2 { (int)l };
        cout << n2 << endl;
    }
}
