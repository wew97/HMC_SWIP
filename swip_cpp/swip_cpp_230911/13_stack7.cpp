// 13_stack7.cpp
#include <iostream>
using namespace std;

#include "stack.h"

int main()
{
    Stack s1 { 100 };

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
