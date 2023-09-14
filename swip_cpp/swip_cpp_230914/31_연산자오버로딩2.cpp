// 31_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

#if 0
// cout: 표준 출력 객체
//  cin: 표준 입력 객체
namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }
};

ostream cout;

}

using xstd::cout;

int main()
{
    int n = 42;
    // cout << n;
    // cout.operator<<(n); // int

    double d = 3.14;
    // cout << d;
    // cout.operator<<(d); // double

    cout << n << d;
    cout.operator<<(n).operator<<(d);
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

    friend ostream& operator<<(ostream& os, const Point& pt);
};

// 사용자 정의 타입을 ostream을 이용해서,
// 출력하기 위해서는 연산자 재정의 함수를 일반 함수로 제공해야 합니다.
ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;
}

int main()
{
    Point pt { 10, 20 };
    cout << pt;
    // operator<<(cout, pt);

    cout << endl;
}
