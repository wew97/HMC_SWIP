// 25_상속5.cpp
#include <iostream>
#include <string>
using namespace std;

// * 초기화 리스트를 반드시 정의해야 하는 경우 4가지
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자가 존재하지 않는 클래스 멤버
// 4) 기본 생성자가 존재하지 않는 부모 클래스
class Animal {
    int age;

public:
    Animal(int n)
        : age { n }
    {
    }
};

// 부모 클래스가 기본 생성자를 제공하지 않는 경우,
// 반드시 초기화리스트를 통해, 부모 클래스의 생성자를 명시적으로
// 수행해야 합니다.

// 자식 클래스는 부모 클래스의 생성자를 호출해야 하는 책임이 있습니다.
// 부모 클래스가 생성자의 인자를 전달받아야 하는 경우, 자식의 생성자를 통해
// 부모 클래스의 생성자에 전달해야 합니다.

// * 초기화리스트 순서
//  : 부모 클래스 생성자 호출 -> 선언된 멤버 순서대로 초기화
class Dog : public Animal {
    string name;

public:
    // 초기화 리스트를 작성할 때, 부모 클래스의 생성자 호출부터 작성해야 합니다.
    Dog(int n, const string& s)
        : Animal { n }
        , name { s }

    {
    }
};

int main()
{
    Dog d { 42, "Bob" };
}
