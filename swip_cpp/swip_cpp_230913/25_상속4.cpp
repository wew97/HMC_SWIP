// 25_상속4.cpp
#include <iostream>
using namespace std;

// 1. 자식 객체를 생성하면, 부모의 생성자를 통해 부모의 영역을 초기화됩니다.
// 2. 자식 객체를 파괴하면, 부모의 소멸자를 통해 부모의 영역을 정리합니다.

class Base {
public:
    Base() { cout << "Base()" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    // Derived() : Base()
    //   자식의 생성자의 초기화리스트에서 부모의 기본 생성자를 호출하는
    //   코드를 컴파일러가 자동으로 처리합니다.
    //  2) Base::Base()
    Derived()
    {
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    } // 2> 컴파일러는 자식 클래스의 소멸자의 마지막에 부모의 소멸자를 호출하는
    //      코드를 자동으로 처리합니다.
    //      Base::~Base()
};

int main()
{
    Derived d; // 1) Derived::Derived()
} // 1> Derived::~Derived()
