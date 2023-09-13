// 26_다형성4.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있습니다.
//  => 함수 오버라이딩(Overriding)

// 2. 부모 클래스의 멤버 함수를 자식이 오버라이딩하였을 때,
//    부모의 포인터/레퍼런스를 통해 호출하였을 경우,
//    자식의 멤버 함수가 제대로 호출되지 않는 문제가 발생합니다.
//    => C++은 정적 바인딩 기반으로 함수를 호출합니다.
//       멤버 함수가 오버라이딩될 경우, 함수의 호출 방식을 동적 바인딩으로
//       변경해야 합니다.
//        : virtual

// 3. C++ 함수 바인딩: 어떤 함수를 호출할지 결정하는 것
//    Animal* p = &d;
//    p->Cry();
//    Animal& r = d;
//    r.Cry();
//   1) 정적 바인딩(static binding)
//    : 컴파일 시간에 컴파일러가 p/r의 타입을 보고,
//      어떤 함수를 호출할지 결정합니다.
//    - 인라인 최적화가 가능합니다.

//   2) 동적 바인딩(dynamic binding)
//    : 실행 시간에 객체의 타입을 조사해서,
//      어떤 함수를 호출할지 결정합니다.
//    - 컴파일러가 컴파일 시간에 어떤 함수를 호출할지 결정할 수 없으므로,
//      인라인 최적화가 불가능합니다.

class Animal {
public:
    virtual void Cry() const { cout << "Animal Cry" << endl; }
};

class Dog : public Animal {
public:
    virtual void Cry() const { cout << "Dog Cry" << endl; }
};

#if 1
int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Cry();

    p = &d;
    p->Cry();

    Animal& r = d;
    r.Cry();
}
#endif

#if 0
int main()
{
    Animal a;
    a.Cry();

    Dog d;
    d.Cry();
}
#endif
