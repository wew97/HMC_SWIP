// 13_stack8.cpp
#include <iostream>
using namespace std;

// 클래스도 템플릿으로 만들 수 있습니다.
template <typename TYPE>
class Stack {
    TYPE* buff;
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
        buff = new TYPE[10];
        top = 0;
    }

    Stack(size_t size)
    {
        cout << "Stack(int)" << endl;
        buff = new TYPE[size];
        top = 0;
    }

    void Push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE Pop()
    {
        return buff[--top];
    }
};

#include <string>

int main()
{
    Stack<string> s;
    s.Push("hello");
    s.Push("world");
    s.Push("money");

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}

#if 0
// 클래스 템플릿은 템플릿의 타입을 결정하기 어려운 경우가 많습니다.
// 명시적으로 타입을 지정해야 합니다.
int main()
{
    Stack<double> s1 { 100 };

    s1.Push(3.14);
    s1.Push(20.5);
    s1.Push(30.14);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif
