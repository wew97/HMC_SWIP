// 25_상속.cpp
#include <iostream>
#include <string>
using namespace std;

// 상속
// : 각 클래스가 제공하는 공통의 기능을 부모 클래스로 캡슐화할 수 있습니다.

#if 0
class Dog {
    int age;
    string name;

public:
    int GetAge() const { return age * 10; }
};

class Cat {
    int age;
    int speed;

public:
    int GetAge() const { return age * 10; }
};

int main()
{
    Dog d;
    Cat c;

    cout << sizeof(d) << endl;
    cout << sizeof(c) << endl;

    cout << d.GetAge() << endl;
    cout << c.GetAge() << endl;
}
#endif

// Dog와 Cat의 공통의 속성을 캡슐화합니다.
class Animal {
    int age;

public:
    int GetAge() const { return age; }
};

class Dog : public Animal {
    string name;
};

class Cat : public Animal {
    int speed;
};

int main()
{
    Dog d;
    Cat c;

    cout << sizeof(d) << endl;
    cout << sizeof(c) << endl;

    cout << d.GetAge() << endl;
    cout << c.GetAge() << endl;
}
