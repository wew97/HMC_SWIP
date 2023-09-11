// 13_stack5.cpp
#include <iostream>
using namespace std;

// 5. 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
//    객체를 생성할 때, 사용자로부터 정보를 전달 받을 수 있습니다.
//    => 생성자

//    Stack s;        -> Stack::Stack()
//    Stack s(10);    -> Stack::Stack(int)

//    * 생성자는 인자 정보에 따라 여러개를 제공할 수 있습니다.
//     => 생성자는 오버로딩이 가능합니다.
//      "객체를 생성하는 다양한 방법을 제공할 수 있습니다."

class Stack {
    // 멤버 데이터 / property(속성)
    int* buff;
    int top;

public:
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
