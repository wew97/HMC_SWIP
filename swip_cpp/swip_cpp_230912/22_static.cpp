// 22_static.cpp
#include <iostream>
using namespace std;

#if 0
int cnt = 0;
// 자동차 객체가 생성된 갯수

class Car {
public:
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

int main()
{
    Car car[5];
    cout << cnt << endl;

    Car* p = new Car[3];
    cout << cnt << endl;

    delete[] p;
    cout << cnt << endl;
}
#endif

// 정적 멤버 데이터
//  1) 클래스의 접근 제어를 사용할 수 있는 전역 변수입니다.
//  2) 반드시 선언과 정의를 분리해야 합니다.

#if 0
class Car {
public:
    static int cnt; // 선언

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

int Car::cnt = 0; // 정의

int main()
{
    // 정적 멤버 데이터에 접근하는 방법
    // 1) 클래스::cnt
    cout << Car::cnt << endl;

    // 2) 객체.cnt
    Car c;
    cout << Car::cnt << endl;
    cout << c.cnt << endl;
}
#endif

#if 0
class Car {
    // 정적 멤버 데이터
    static int cnt;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    // 멤버 함수는 객체 없이 호출이 불가능합니다.

    // 정적 멤버 함수
    // => 객체 없이 호출이 가능한 멤버 함수입니다.
    // => 일반 함수와 동일합니다.
    //    클래스의 접근 제어를 사용할 수 있습니다.
    static int GetCount()
    {
        return cnt;
    }
};

int Car::cnt = 0;

int main()
{
    // 2. 클래스::정적멤버함수();
    cout << Car::GetCount() << endl;

    // 1. 객체.정적멤버함수();
    Car car;
    cout << car.GetCount() << endl;
}
#endif

class Point {
    // 멤버 데이터: 객체 상태
    int x;
    int y;

    // 정적 멤버 데이터: 클래스 상태
    static int count;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
        ++count;
    }

    ~Point() { --count; }

    // 멤버 함수: 객체 행위
    void Print()
    {
        cout << x << ", " << y << endl;
    }

    // 정적 멤버 함수: 클래스 행위
    static int GetCount() { return count; }
};

int Point::count = 0;

int main()
{
}
