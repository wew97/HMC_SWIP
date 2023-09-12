// 20_객체복사3.cpp
#include <iostream>
using namespace std;

// 복사 정책
// 2) 참조 계수

class User {
    char* name;
    int age;
    int* ref;

public:
    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
        , ref { rhs.ref }
    {
        ++(*ref); // 참조 계수 증가!
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int { 1 };
    }

    ~User()
    {
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }
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

    User other = user1;
    other.Print();
}
