// 17_this.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    // void Set(Point* this, int a, int b)
    //   => thiscall
    void Set(int a, int b)
    {
        cout << "this: " << this << endl;

        // this는 멤버 함수의 첫번째 인자를 통해,
        // 멤버 함수를 호출한 객체의 주소가 전달됩니다.
        x = a;
        // this->x = a;

        y = b;
        // this->y = b;
    }
};

void Set(int a, int b)
{
}

int main()
{
    Set(10, 20);
    /*
        mov     edx, 20
        mov     ecx, 10
        call    void Set(int,int)
    */

    Point pt1, pt2;

    cout << "&pt1: " << &pt1 << endl;
    pt1.Set(10, 20);
    /*
        mov     r8d, 20
        mov     edx, 10
        lea     rcx, QWORD PTR pt1$[rsp] ; rcx = &pt1;
        call    void Point::Set(int,int)
    */

    cout << "&pt2: " << &pt2 << endl;
    pt2.Set(100, 200);

    // cout << sizeof(Point) << endl;
}
