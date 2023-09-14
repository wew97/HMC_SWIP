// 31_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 기본 생성자를 제공합니다.

// 2. 사용자가 복사 생성자를 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.

// 3. 사용자가 대입 연산자를 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 대입 연산자를 제공합니다.

// 4. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 소멸자를 제공합니다.

class Point {
    int x;
    int y;

public:
    // 대입 연산자 오버로딩
    // => 멤버 함수를 통해서만 제공할 수 있습니다.
    Point& operator=(const Point& rhs)
    {
        cout << "operator=(const Point&)" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this;
    }

    Point(const Point& rhs)
        : x { rhs.x }
        , y { rhs.y }
    {
        cout << "Point(const Point&)" << endl;
    }

    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt { 10, 20 };

    Point other = pt; // Point(const Point&) : 복사 생성자
    other.Print();

    other = pt;
    // operator=(const Point&) : 대입 연산자
    // other.operator=(pt)

    other.Print();
}

// int a, b, c;
// a = b = c = 10;

// a = 10
//   C: 대입 연산자의 결과는 대입된 값입니다. => 10
// C++: 대입 연산자의 결과는 피연산자의 참조 입니다. => a
