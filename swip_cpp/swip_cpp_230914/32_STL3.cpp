// 32_STL3.cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

#if 0
void Print(vector<int>::iterator begin, vector<int>::iterator end)
{
    auto p = begin;
    while (p != end) {
        cout << *p << endl;
        ++p;
    }
}

void Print(list<int>::iterator begin, list<int>::iterator end)
{
    auto p = begin;
    while (p != end) {
        cout << *p << endl;
        ++p;
    }
}
#endif

// 3. 알고리즘
//  선형적인 자료구조의 알고리즘은 타입만 다르고 알고리즘은 유사합니다.
//   vector
//   list  -----> 반복자 ------> 알고리즘 일반 함수
//   deque                  : 정렬, 탐색, 이진검색 ...

template <typename T>
void Print(T begin, T end)
{
    auto p = begin;
    while (p != end) {
        cout << *p << endl;
        ++p;
    }
}

int main()
{
    // vector<int> x = { 1, 2, 3, 4, 5 };
    int x[5] = { 1, 2, 3, 4, 5 };
    Print(begin(x), end(x));
}
