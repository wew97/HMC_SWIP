// 25_상속6.cpp
#include <iostream>
using namespace std;

// * protected 생성자
// : 부모 클래스의 객체는 생성하지 않고,
//   자식 클래스의 객체만 생성하고 싶습니다.
// - 부모 클래스를 추상(abstract)적인 개념으로 사용할 때,
//   객체를 생성하지 않아야 합니다.
// => 부모 클래스의 생성자를 protected 영역에 두면 됩니다.
class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    Dog()
        : Animal {} // protected 부모 생성자를 접근할 수 있습니다.
    {
    }
};

int main()
{
    // Animal a;
    Dog d; // Dog::Dog()
}
