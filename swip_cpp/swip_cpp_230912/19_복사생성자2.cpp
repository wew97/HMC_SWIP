// 19_복사생성자2.cpp
#include <iostream>
using namespace std;

#if 1
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
};

// 복사 생성자가 호출되는 경우
// 1) 객체가 함수의 인자로 call by value로 전달될 때
//  : C++에서는 객체를 함수의 인자로 전달할 때,
//    call by value 대신 const&를 사용합니다.
//  => 불필요한 객체의 복사 생성자 / 소멸자의 비용을 제거하기 위해서

// void foo(Sample s) // Sample(const Sample&)
void foo(const Sample& s)
{
} // ~Sample()

int main()
{
    Sample s;

    cout << "-----------" << endl;
    foo(s);
    cout << "-----------" << endl;
}
#endif

#if 0
class Point {
public:
    int x;
    int y;
};

// void foo(const Point& pt)
void foo(Point pt)
{
    cout << pt.x << ", " << pt.y << endl;
}

int main()
{
}
#endif
