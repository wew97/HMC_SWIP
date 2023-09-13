// 26_다형성.cpp
#include <iostream>
using namespace std;

// 상속의 목적?
// => "상속"의 목적은 "다형성" 입니다.

class Animal { };
class Dog : public Animal { };
// is-a 관계
// : 부모 클래스와 자식 클래스는 is-a 관계가 성립합니다.
//  <자식 클래스> is a(n) <부모 클래스>
//  : Dog is an Animal

// 부모 클래스의 포인터/참조 타입을 통해
// 자식 객체를 참조할 수 있습니다.
//  : Upcasting
//   * 자식의 포인터 또는 참조 타입은
//     부모의 포인터 또는 참조 타입으로의
//     암묵적인 변환이 허용됩니다.

int main()
{
    Animal a;
    Dog d;

    Animal* p1 = &a;
    Animal& r1 = a;

    Animal* p2 = &d;
    Animal& r2 = d;
}
