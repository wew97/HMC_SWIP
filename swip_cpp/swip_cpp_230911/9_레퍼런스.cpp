// 9_레퍼런스.cpp
#include <iostream>
using namespace std;

// 1. C++에는 레퍼런스 타입이 도입되었습니다.
//  => 기존 메모리에 새로운 이름을 부여합니다.

// 2. 포인터와 레퍼런스의 차이점을 이해해야 합니다.
//  => 포인터는 주소를 가지는 변수입니다.
//     포인터는 주소를 통해 메모리 접근해서 값을 읽거나 변경할 수 있습니다.
//  => 레퍼런스는 기존 메모리에 새로운 이름을 부여합니다.
//     새로운 이름을 통해 메모리에 접근해서, 값을 읽거나 변경할 수 있습니다.

#if 0
int main()
{
    int n = 100;

    int& r = n;

    n = 42;
    cout << r << endl;

    r = 100;
    cout << n << endl;
}
#endif

#if 0
int main()
{
    int n = 100;

    int* p = &n;

    n = 42;
    cout << *p << endl;

    *p = 100;
    cout << n << endl;
}
#endif

int main()
{
    int n = 100;

    // int* p = NULL;
    int* p = &n;
    // cout << p << endl;

    cout << &n << endl;
    cout << &p << endl;

    int& r = n;
    cout << &n << endl;
    cout << &r << endl;

    // int& r; /* 에러 */
    // - 레퍼런스는 반드시 초기화가 필요합니다.
    // int& r = NULL; /* 에러 */
    // - 레퍼런스는 유효한 메모리에 대한 초기화가 필요하고,
    //   널 레퍼런스 같은 개념도 존재하지 않습니다.
}
