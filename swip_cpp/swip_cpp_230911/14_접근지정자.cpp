// 14_접근지정자.cpp
#include <iostream>
using namespace std;

// 1. class의 기본 접근 지정자는 private 입니다.
//   struct의 기본 접근 지정자는 public 입니다.

// 2. private: 외부에서 접근이 불가능합니다.
//             public 멤버 함수를 통해서는 접근이 가능합니다.

//    public: 외부에서 접근이 가능합니다.

#if 0
struct Point {
    int x;
    int y;
};

int main()
{
    Point pt;
    pt.x = 10;
    pt.y = 100;
    cout << pt.x << ", " << pt.y << endl;
}
#endif

class Point {
    int x;
    int y;

public:
    // 접근자(Accessor) 메소드

    // - Setter
    void SetX(int a) { x = a; }
    void SetY(int a) { y = a; }

    // - Getter
    int GetX() { return x; }
    int GetY() { return y; }
};

int main()
{
    Point pt;
    // pt.x = 10;
    pt.SetX(10);

    // pt.y = 100;
    pt.SetY(100);

    cout << pt.GetX() << ", " << pt.GetY() << endl;
}
