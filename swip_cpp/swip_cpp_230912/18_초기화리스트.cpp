// 18_초기화리스트.cpp
#include <iostream>
using namespace std;

// 초기화와 대입의 차이점을 이해해야 합니다.
// => 초기화: 변수를 메모리에 할당하면서, 초기값을 지정하는 행위
//     대입: 이미 할당된 메모리의 값을 변경하는 행위

// 초기화가 필요한 타입
// 1) const
// 2) reference
#if 0
int main()
{
    // const int c; /* 에러! */
    // int& r; /* 에러! */
}
#endif

// 핵심
// - 생성자에서 멤버 데이터를 초기화하기 위해서는
//   초기화리스트의 문법을 이용해야 합니다.

// 초기화리스트를 반드시 사용해야 하는 경우
// 1) const 멤버 데이터
// 2) reference 멤버 데이터

class Sample {
    const int x;
    const int y;
    int& r;

public:
    Sample(int a, int b, int& ra)
        // : x(a) ,y(b)
        : x { a }
        , y { b }
        , r { ra }
    {
    }

#if 0
    Sample(int a, int b)
    {
        x = a; /* 초기화가 아니라 대입입니다. */
        y = b; /* 초기화가 아니라 대입입니다. */
    }
#endif
};

int main()
{
    int n = 100;
    Sample s { 10, 20, n };
}
