// 20_객체복사4.cpp
#include <iostream>
using namespace std;

// 복사 정책
// 3) 복사 금지
//  - 복사 생성자를 private 영역에 선언만 제공합니다.
//  => 클래스 외부에서는 접근할 수 없고, 내부에서 잘못 사용한 경우,
//     링크 오류를 의도합니다.
//  => C++11, delete function

class User {
    char* name;
    int age;

    User(const User& rhs) = delete;

public:
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
    // other.Print();
}
