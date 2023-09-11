// 14_접근지정자2.cpp
#include <iostream>
#include <string>
using namespace std;

// C++에서 friend 선언된 함수/클래스는 클래스의 private 멤버에 접근이 가능합니다.
// => 캡슐화의 정책을 깨뜨리지 않고, 경계를 확장할 수 있습니다.s

class User {
    string name;
    int age;

public:
    User(string s, int n)
    {
        name = s;
        age = n;
    }

    // string GetName() { return name; }
    // int GetAge() { return age; }

    friend void PrintUser(User user);
    friend class UserPrinter;
};

class UserPrinter {
public:
    void Print(User user)
    {
        cout << user.name << ", " << user.age << endl;
    }
};

void PrintUser(User user)
{
    cout << user.name << ", " << user.age << endl;
    // cout << user.GetName() << ", " << user.GetAge() << endl;
}

int main()
{
    // User user { "Tom", 42 };
    User user("Tom", 42);
    PrintUser(user);

    UserPrinter printer;
    printer.Print(user);
}
