// 23_상수멤버함수.cpp
#include <iostream>
using namespace std;

// * 상수 멤버 함수
// - 멤버 함수에서 객체의 멤버 데이터(상태)를 상수 취급합니다.
// => 멤버 함수 안에서 값을 변경할 수 없습니다.

// - 멤버 함수안에서 객체의 상태를 변경하지 않는 경우,
//   반드시 상수 멤버 함수로 만들어야 합니다.
// => 상수 포인터 또는 상수 참조를 통해 멤버 함수를 호출할 수 있습니다.
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const
    {
        // x = 100;
        // y = 200;
        cout << x << ", " << y << endl;
    }

    void SetX(int a) { x = a; }
    void SetY(int a) { y = a; }
};

// void foo(Point pt)
void foo(const Point& pt)
{
    pt.Print();
}

#if 0
int main()
{
    Point pt { 10, 20 };
    pt.SetX(100);
    pt.SetY(200);
    pt.Print();

    const Point pt2 { 10, 20 }; // 상수 객체, 불변 객체
    // 상수 멤버 함수만 호출이 가능합니다.
    pt2.Print();

    const Point* p = &pt;
    // 상수 멤버 함수만 호출이 가능합니다.
    p->Print();

    const Point& r = pt;
    // 상수 멤버 함수만 호출이 가능합니다.
    r.Print();

    foo(pt);
}
#endif

int main()
{
    // 상수성을 가지는 대상체를 참조하는 경우,
    // 반드시 const 포인터 / const 참조를 사용해야 합니다.
    const Point pt { 10, 20 };

    const Point* p1 = &pt;
    const Point& r1 = pt;
}
