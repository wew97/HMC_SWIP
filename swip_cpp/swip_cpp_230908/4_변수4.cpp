// 4_변수4.cpp
#include <iostream>
using namespace std;

// C++11, decltype(표현식)
// => 주어진 표현식의 정확한 타입을 구하는 연산자입니다.
// 1) auto와 달리, 우항이 필요하지 않습니다.
// 2) 정확한 타입을 구할 수 있습니다.

int main()
{
    int n = 10;

    // n과 동일한 타입의 변수를 만들고 싶습니다.
    decltype(n) x;

    const int c1 = 100;
    decltype(c1) c2 = 1000; // const int c2 = 1000;
}
