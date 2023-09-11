// stack.cpp
#include "stack.h"
#include <iostream>

Stack::~Stack()
{
    delete[] buff;
}

Stack::Stack()
{
    buff = new int[10];
    top = 0;
}

Stack::Stack(size_t size)
{
    buff = new int[size];
    top = 0;
}
