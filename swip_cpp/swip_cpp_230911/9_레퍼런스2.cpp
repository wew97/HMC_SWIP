// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

#if 0
void Increment1(int x)
{
    ++x;
}

void Increment2(int* px)
{
    if (px) {
        ++(*px);
    }
}

// 포인터를 레퍼런스로 대체할 수 있다면,
// 레퍼런스를 사용하는 것이 좋습니다.
// 1) 포인터는 유효하지 않을 경우, 널로 초기화되어야 합니다.
// 2) 포인터는 사용하기 전에, 유효성 체크를 반드시 해야 합니다.
void Increment3(int& rx)
{
    ++rx;
}

int main()
{
    int x = 10;
    // Increment1(x); // Call by value
    // Increment2(&x); // Call by pointer

    Increment3(x); // Call by reference

    cout << x << endl;
}
#endif

// 배열이 함수로 전달될 때, 배열의 첫번째 원소의 주소를 전달하기 때문에
// 배열의 길이를 알 수 없습니다.
#if 0
void PrintArray(int* x, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << x[i] << endl;
    }
}

int main()
{
    int x[3] = { 10, 20, 30 };
    PrintArray(x, 3);
}
#endif

#if 0
void PrintArray(int (&r)[3])
{
    for (auto e : r) {
        cout << e << endl;
    }
}

void PrintArray(int (&r)[5])
{
    for (auto e : r) {
        cout << e << endl;
    }
}
#endif

template <typename TYPE>
inline void PrintArray(TYPE& r)
{
    for (auto e : r) {
        cout << e << endl;
    }
}

int main()
{
    int x[3] = { 10, 20, 30 };
    int arr[5] = { 1, 2, 3, 4, 5 };

    // int* p = x;
    // 레퍼런스는 디케이가 되지 않습니다.

    int(&r)[3] = x;

    PrintArray(x);
    PrintArray(arr);
}
