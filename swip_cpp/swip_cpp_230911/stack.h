// stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
    int* buff;
    int top;

public:
    ~Stack();
    Stack();

    Stack(size_t size);

    inline void Push(int n);
    inline int Pop();
};

// 인라인 최적화
// : 인라인 함수의 구현은 헤더를 통해서 제공되어야 합니다.
void Stack::Push(int n)
{
    buff[top++] = n;
}

int Stack::Pop()
{
    return buff[--top];
}

#endif
