// 20_객체복사5.cpp
#include <iostream>
using namespace std;

class User {
    char* name;
    int age;

public:
    // C++11, Move Constructor
    // => 소유권 이전
    User(User&& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
        rhs.name = nullptr;
    }

    // 복사 생성자
    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user1 { "Tom", 42 };
    user1.Print();

    // User other = user1;
    User other = std::move(user1);
    // std::move를 이용하면, lvalue를 rvalue로 변경할 수 있습니다.

    other.Print();
}

#if 0
int main()
{
    User user1 { "Tom", 42 };
    user1.Print();

    // User other = user1;
    User other = User { "Tom", 100 }; // Move Constructor
    other.Print();
}
#endif
