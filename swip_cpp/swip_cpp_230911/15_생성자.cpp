// 15_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 인자 없는 생성자를 만들어줍니다.
#if 0
class Point {
    int x;
    int y;

public:
    // Point() {} // 기본 생성자(인자 없는 생성자)
};

int main()
{
    Point pt; // Point()
}
#endif

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.
#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point pt { 10, 20 }; // Point(int, int)

    // Point pt; /* 오류! */
}
#endif

// 3. 생성자는 인자 정보가 다를 경우, 여러개 제공할 수 있습니다.
//  => 생성자 오버로딩이 가능합니다.
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    Point()
    {
        x = 0;
        y = 0;
    }
};

int main()
{
    Point pt { 10, 20 }; // Point(int, int)

    Point pt; // Point()
}
