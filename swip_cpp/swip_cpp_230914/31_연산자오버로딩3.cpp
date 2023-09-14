// 31_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

#if 0
namespace xstd {
class istream {
public:
    istream& operator>>(int& r)
    {
        scanf("%d", &r);
        return *this;
    }

    istream& operator>>(double& r)
    {
        scanf("%lf", &r);
        return *this;
    }
};

istream cin;
}

using std::cout;
using std::endl;
using xstd::cin;

int main()
{
    int n;
    double d;

    cin >> n >> d;
    // cin.operator>>(n).operator>>(d)

#if 0
    cin >> n;
    // cin.operator>>(n) : int&
    cin >> d;
    // cin.operator>>(d); : double&
#endif

    cout << n << d << endl;
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

    friend istream& operator>>(istream& is, Point& pt);
    friend ostream& operator<<(ostream& os, const Point& pt);
};

istream& operator>>(istream& is, Point& pt)
{
    return is >> pt.x >> pt.y;
}

ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;
}

int main()
{
    Point pt { 10, 20 };

    cin >> pt;
    cout << pt;

    cout << endl;
}
