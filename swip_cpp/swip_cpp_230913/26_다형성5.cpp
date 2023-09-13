// 26_다형성5.cpp
#include <iostream>
using namespace std;

// * 문제점
// 1. 부모의 멤버 함수가 가상 함수일 때만, 자식 클래스가 오버라이딩
//    해야 합니다.
//  => 부모의 포인터/참조를 통해 해당 기능을 이용할 때,
//     무조건 부모의 멤버 함수만 호출됩니다.

// 2. C++에서 오버라이딩을 의도했지만, 오버라이딩이 아닌
//    새로운 멤버 함수를 만드는 문제가 발생하는 경우가 있습니다.

//  C++11, override 키워드가 도입되었습니다.
//  1) 부모가 제공하는 멤버 함수가 가상함수가 아니면,
//     컴파일 오류가 발생합니다.
//  2) 오버라이딩을 의도 했지만, 잘못된 오버라이딩이 수행된 경우
//     컴파일 오류가 발생합니다.
//  핵심: 반드시 오버라이딩 메소드의 마지막에 override를 지정해야 합니다.

class Animal {
public:
    virtual void Hello() const { cout << "Hello" << endl; }
};

// 자식 클래스가 재정의한 부모의 멤버 함수가 가상함수이면,
// 자식의 멤버 함수도 자동으로 가상 함수가 됩니다.
class Dog : public Animal {
public:
    void Hello() const override { cout << "Hello, Dog" << endl; }
};

int main()
{
    Dog d;
    Animal& r = d;
    r.Hello();
}
