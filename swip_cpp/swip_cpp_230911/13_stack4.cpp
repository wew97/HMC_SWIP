// 13_stack4.cpp
#include <iostream>
using namespace std;

// 4. 객체를 생성하였을 때, 바로 사용할 수 있는 상태가 되어야 합니다.
//  => 객체가 메모리에 생성되는 시점에 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//    : 생성자(Constructor) 함수
//      "초기화"

// 생성자 함수
//  1) 함수의 이름은 클래스 이름과 동일합니다.
//  2) 반환 타입도 없고 반환 값도 없습니다.

class Stack {
    // 멤버 데이터 / property(속성)
    int buff[10];
    int top;

public:
    Stack()
    {
        cout << "Stack()" << endl;
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
    // s1.Init();
    // s2.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
