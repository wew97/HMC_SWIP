// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. C++은 사용자 정의 타입에서 데이터 뿐 아니라 데이터를 조작하는 함수도
//    묶을 수 있습니다.
//  => 캡슐화: 상태 + 행위

// 변수(상태, 행위) => 객체(object)
// : 상태와 행위를 가지는 변수

// * 객체의 상태는 멤버 함수를 통해서만 접근할 수 있어야 합니다.
// => 정보 은닉(Information Hiding)
//   : 접근 지정자
//   1) public: 외부에서 접근이 가능합니다.
//   2) private: 외부에서 접근이 불가능하고, 오직 멤버 함수를 통해서만 접근이 가능합니다.
//   struct: 기본 접근 지정자가 public 입니다.
//    class: 기본 접근 지정자가 private 입니다.

// struct Stack {
class Stack {
    // 멤버 데이터 / property(속성)
    int buff[10];
    int top;

public:
    // 멤버 함수 / method(메소드)
    void Init()
    {
        top = 0;
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};

int main()
{
    Stack s1, s2;
    s1.Init();
    s2.Init();

    // s1.top = 100;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
