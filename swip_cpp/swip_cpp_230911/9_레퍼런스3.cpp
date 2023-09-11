// 9_레퍼런스3.cpp
// : 우선 개념적으로 정리가 필요합니다.

#include <iostream>
using namespace std;

// 1. int&
//   : lvalue reference
//  => lvalue만 참조할 수 있습니다.

// 2. const int&
//   : const lvalue reference
//  => const lvalue와 lvalue와 rvalue를 참조할 수 있습니다.

// lvalue: 왼쪽항과 오른쪽항에 모두 사용할 수 있습니다.
//  => lvalue는 & 연산자를 사용할 수 있습니다.

// rvalue: 오른쪽항에서만 사용할 수 있습니다.
//  => rvalue는 & 연산자를 사용할 수 없습니다.

void foo(const int& r)
{
    cout << "const lvalue&" << endl;
}

void foo(int&& rr)
{
    cout << "rvalue&" << endl;
}

// 3. C++11, rvalue reference
//  : rvalue만 참조할 수 있습니다.
//  int&&

int main()
{
    int a = 10;
    int& r1 = a; /* OK, a는 lvalue 입니다. */
    // int& r2 = 10; /* NO, 10은 rvalue 입니다. */

    // int&& rr1 = a; /* NO, a는 lvalue 입니다. */
    int&& rr2 = 10; /* OK, 10은 rvalue 입니다.*/

    foo(a);
    foo(10);
}
