// 4_변수5.cpp
#include <iostream>
using namespace std;

#if 0
// typedef
// => Type aliasing
//    변수를 정의하듯, 타입의 별칭을 만들 수 있습니다.
typedef int ARR3[3]; // ARR3 = int[3]
typedef int (*PARR3)[3]; // PARR3 = int(*)[3]

int main()
{
    ARR3 x;
    x[0] = 100;

    PARR3 p = &x;
}
#endif

// C++11, typedef를 대체하는 새로운 문법이 도입되었습니다.
//  => using
//    1) namespace
//        using 선언 / using 지시어
//    2) type aliasing, C++11
// typedef int ARR3[3]; // ARR3 = int[3]
using ARR3 = int[3];

// typedef int (*PARR3)[3]; // PARR3 = int(*)[3]
using PARR3 = int (*)[3];

int main()
{
    ARR3 x;
    x[0] = 100;

    PARR3 p = &x;
}
