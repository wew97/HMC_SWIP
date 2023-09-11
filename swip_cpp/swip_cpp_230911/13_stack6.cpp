// 13_stack5.cpp
#include <iostream>
using namespace std;

// 6. 객체 내부에서 new를 통해 메모리가 할당되었다면,
//    객체가 파괴되기 전에 반드시 할당된 메모리가 delete 되어야 합니다.
// : 객체가 메모리에 파괴되기 직전에, 호출되는 약속된 멤버 함수가 있습니다.
//    - 소멸자(Destructor) 함수
//  1) 함수의 이름은 ~클래스이름 입니다.
//  2) 반환값도 없고, 반환 타입도 명시하지 않습니다.
//  3) 소멸자는 인자 없는 형태 1개만 제공할 수 있습니다.

class Stack {
    // 멤버 데이터 / property(속성)
    int* buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    Stack()
    {
        cout << "Stack()" << endl;
        buff = new int[10];
        top = 0;
    }

    Stack(size_t size)
    {
        cout << "Stack(int)" << endl;
        buff = new int[size];
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
    // Stack s1(100);
    Stack s1 { 100 };
    // Stack s1;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
