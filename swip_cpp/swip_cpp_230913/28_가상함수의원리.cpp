// 28_가상함수의원리.cpp
#include <iostream>
using namespace std;

// 1. 가상 함수를 가지는 클래스의 객체는
//    가상 함수 테이블을 가르키는 포인터 멤버가 추가됩니다.
//    => 객체의 크기가 포인터 크기만큼 늘어납니다.

// 2. 가상 함수 테이블 비용
//    => 클래스가 소유한 가상 함수 개수만큼 테이블의 크기가 메모리 상에
//       필요합니다.

class Shape {
    int x;
    int y;

public:
    virtual void Draw() const { }
};

class Rect : public Shape {
    int width;
    int height;
};

int main()
{
    Shape s;
    cout << sizeof(s) << endl;
    Rect r;
    cout << sizeof(r) << endl;
}
