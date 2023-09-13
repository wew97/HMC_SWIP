// 25_상속2.cpp
#include <iostream>
using namespace std;

// 부모 클래스 / Base / Super
class Animal {
    int age;
};

// 자식 클래스 / Derived / Sub
// * 상속: class 자식클래스 : public 부모클래스
// - 객체 지향 설계에서 의미하는 상속은
//   C++에서는 public 상속을 의미합니다.
// - C++의 private 상속은 다른 목적으로 사용되는 C++ 고유의 개념입니다.
class Dog : public Animal {
};

int main()
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Dog) << endl;
}
