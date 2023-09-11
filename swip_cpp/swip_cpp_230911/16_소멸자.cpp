// 16_소멸자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 소멸자를 제공합니다.
//    ~Person() {}

#if 0
class Person {
};

int main()
{
    Person p;
    // Person::Person();

} // Person::~Person();
#endif

// 2. 클래스 내부에서 자원(메모리, 파일 등)을 할당한 경우,
//    소멸자를 통해 객체가 파괴되는 시점에 자원을 해지해야 합니다.
class Person {
    char* name;

public:
    Person(const char* s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    // 소멸자는 인자 없는 한개만 제공할 수 있습니다.
    ~Person()
    {
        delete[] name;
    }
};

int main()
{
    Person p { "Bob" };
    // Person::Person();

} // Person::~Person();
