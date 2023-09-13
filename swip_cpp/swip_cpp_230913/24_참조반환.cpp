// 24_참조반환.cpp
#include <iostream>
using namespace std;

#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const { cout << x << ", " << y << endl; }

    void Move(int ax, int ay)
    {
        x += ax;
        y += ay;
    }
};

int main()
{
    Point pt { 10, 20 };

    pt.Move(10, 20);
    pt.Move(10, 20);
    pt.Move(10, 20);
    pt.Move(10, 20);
    pt.Print();
}
#endif

#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const { cout << x << ", " << y << endl; }

    Point* Move(int ax, int ay)
    {
        x += ax;
        y += ay;

        return this;
    }
};

int main()
{
    Point pt { 10, 20 };

    pt.Move(10, 20)
        ->Move(10, 20)
        ->Move(10, 20)
        ->Move(10, 20)
        ->Print();
}
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

    void Print() const { cout << x << ", " << y << endl; }

    Point& Move(int ax, int ay)
    {
        x += ax;
        y += ay;

        return *this;
        // this를 역참조하면 자기 자신의 참조를 얻을 수 있습니다.
    }
};

int main()
{
    Point pt { 10, 20 };

    // Chaining
    //  => 자기 자신의 참조를 반환하는 멤버 함수
    pt.Move(10, 20)
        .Move(10, 20)
        .Move(10, 20)
        .Move(10, 20)
        .Print();
}
