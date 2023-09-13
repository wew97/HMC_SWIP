// 26_다형성2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog {
    int age;
    // ...

public:
    int GetAge() const { return age; }
};

class Cat {
    int age;
    // ...

public:
    int GetAge() const { return age; }
};

void PrintAge(const Dog& d)
{
    cout << d.GetAge() << endl;
}
void PrintAge(const Cat& c)
{
    cout << c.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
#endif

class Animal {
    int age;

public:
    int GetAge() const { return age; }
};

class Dog : public Animal {
};

class Cat : public Animal {
};

// Upcasting 활용 1.
//  : 동종을 처리하는 함수를 정의할 수 있습니다.
void PrintAge(const Animal& a)
{
    cout << a.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);
    Cat c;
    PrintAge(c);
}
