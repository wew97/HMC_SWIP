// 7_함수5.cpp
#include <iostream>
using namespace std;

int square(int x) { return x * x; }

// C++에서 함수를 금지할 수 있습니다.
// 1) 함수 오버로딩을 선언만 제공합니다.
//  => 링크 오류를 의도합니다.
//   - 문제의 원인을 파악하기 어렵습니다.
//   - 의도를 전달하기 어렵습니다.
/*
Undefined symbols for architecture arm64:
  "square(double)"
*/

// 2) C++11, Delete function
/*
7_함수5.cpp:24:13: error: call to deleted function 'square'
    cout << square(3.14) << endl;
*/

double square(double x) = delete;

int main()
{
    cout << square(10) << endl;
    // cout << square(3.14) << endl;
}
