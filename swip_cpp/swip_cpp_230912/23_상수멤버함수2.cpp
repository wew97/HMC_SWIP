// 23_상수멤버함수2.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Move(int a, int b)
    {
        x = a;
        y = b;
    }

    void Print() const { cout << x << ", " << y << endl; }
};

class Rect {
    Point leftTop;

public:
    Rect(int x, int y)
        : leftTop { x, y }
    {
    }

    // 복사를 수행하는 것이, 내부의 상태가 외부에서 함부로 변경되지 않습니다.
    // => 안전하다!
    // Point GetLeftTop() const { return leftTop; }

    const Point& GetLeftTop() const { return leftTop; }
    Point& GetLeftTop() { return leftTop; }
    // 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공할 수 있습니다.
    // => 객체의 멤버를 참조로 반환할 때, 사용됩니다.
};

// 상수멤버함수 & 비상수멤버함수
//       Rect  r;   -> 비상수멤버함수
// const Rect  r;   -> 상수멤버함수
// const Rect* r;   -> 상수멤버함수
// const Rect& r;   -> 상수멤버함수

// 상수멤버함수
//       Rect  r;   -> 상수멤버함수
// const Rect  r;   -> 상수멤버함수
// const Rect* r;   -> 상수멤버함수
// const Rect& r;   -> 상수멤버함수

// 비상수멤버함수
//       Rect  r;   -> 비상수멤버함수
// const Rect  r;   -> X
// const Rect* r;   -> X
// const Rect& r;   -> X

int main()
{
    Rect r { 10, 20 };
    Point& p = r.GetLeftTop();
    p.Move(10, 20);
    p.Print();

    const Rect r2 { 100, 200 };
    const Point& p2 = r2.GetLeftTop();
    p2.Print();
}
