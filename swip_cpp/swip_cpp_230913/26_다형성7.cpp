// 26_다형성7.cpp
#include <iostream>
using namespace std;

// 가상 소멸자
// 1. 부모의 포인터를 통해 자식 객체를 delete 할 때,
//    소멸자가 정적 바인딩을 하기 때문에, 자식의 소멸자를 제대로 호출하지
//    못하는 문제가 발생합니다.
// 2. 부모 클래스는 반드시 소멸자를 가상 소멸자로 만들어야 합니다.
// 3. 부모의 소멸자가 가상이면, 자식 클래스의 소멸자도 자동으로 가상이 됩니다.

class Animal {
public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal {
public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }
    // 소멸자에 override를 지정하면,
    // 부모 클래스의 소멸자가 가상 소멸자가 아닌 경우,
    // 컴파일 오류가 발생합니다.
};

int main()
{
    Animal* p = new Dog;

    delete p;
}

#if 0
int main()
{
    Dog d;
}
#endif
