// 18_초기화리스트3.cpp
#include <iostream>
using namespace std;

// 멤버 데이터를 만들 때, 다른 이름 규칙을 사용합니다.
// 1) member_
// 2) m_member
// 3) mMember
// 4) _member => 표준 라이브러리의 이름 규칙, 이름 충돌의 가능성이 있습니다.
#if 0
class Point {
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_ { x }
        , y_ { y }
    {
    }

    void SetX(int x)
    {
        x_ = x;
    }
};
#endif

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }
};

// 초기화 리스트를 반드시 정의해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 클래스의 객체 멤버

class Rect {
    Point leftTop;

public:
    // 컴파일러가 만들어주는 기본 생성자의 형태
    // => 멤버 데이터 객체의 기본 생성자를 통해 초기화하도록 만들어줍니다.
#if 0
    Rect()
        : leftTop {}
    {
    }
#endif

    Rect()
        : leftTop { 0, 0 } // leftTop(0, 0)
    {
    }
};

int main()
{
    Rect r;
}
