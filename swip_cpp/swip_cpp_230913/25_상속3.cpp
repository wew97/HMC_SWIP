// 25_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스의 private은 자식 클래스를 통해서
//    접근이 불가능합니다.

// 2. protected
//   : 외부에서 접근이 불가능하지만, 자식 클래스를 통해서는 접근이 가능합니다.

// 3. C++ 접근 지정자
//   - private: 외부 접근 불가능, 자식 클래스 접근 불가능,
//              friend 함수/클래스 접근 가능

//   - protected: 외부 접근 불가능, 자식 클래스 접근 가능

//   - public: 외부 접근 가능

// 부모 클래스의 멤버 데이터는 반드시 private으로 두고,
// 자식 클래스라고 하더라도 멤버 함수를 통해서 접근하도록 제어해야 합니다.
class Animal {
    // protected:
private:
    int age = 42;

protected:
    int GetAge() const { return age; }
};

class Dog : public Animal {
public:
    void PrintAge() const
    {
        // cout << age << endl;
        cout << GetAge() << endl;
    }
};

int main()
{
    Dog d;
    // cout << d.age << endl;

    d.PrintAge();
}
