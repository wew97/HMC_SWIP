// 7_함수2.cpp
#include <iostream>
using namespace std;

#if 0
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }

int main()
{
    cout << squarei(10) << endl;
    cout << squared(3.14) << endl;
}
#endif

// C++은 동일한 이름의 함수를 여러개 제공할 수 있습니다.
//  : 함수의 이름은 동일하지만, 함수의 인자 정보(인자의 타입, 개수)가 다른 경우에 대해서만 허용합니다.

//  * 함수 오버로딩(Overloading, 중복 적재)
// 원리: 컴파일시 컴파일러가 함수의 이름을 함수의 인자정보를 포함하는 형태로
//      생성합니다.
//      "Name Mangling"

//  C++에서 C로 컴파일된 함수를 호출하거나,
//  C에서 C++로 컴파일된 함수를 호출하기 위해서는
//  C++에서 함수의 선언에 extern "C"가 지정되어야 합니다.
//  => C++에서 C의 함수를 호출하거나, C에서 C++의 함수를 호출할 수 있습니다.

#if 0
// __Z3squarei
int square(int x)
{
    return x * x;
}

// __Z3squared
double square(double x)
{
    return x * x;
}

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
}
#endif

// 함수 오버로딩 주의사항
// 1) 함수의 인자 정보가 동일하고, 반환 타입만 다른 경우,
//    함수 오버로딩은 허용되지 않습니다.
// int foo() { }
// void foo() { }

// 2) 파라미터 기본값과 함께 사용하는 경우,
//    컴파일러는 어떤 함수를 호출할지 결정할 수 없는
//    모호성의 오류가 발생할 수 있습니다.
//    : 함수 오버로딩과 파라미터 기본값은 같이 사용하지 않는 것이
//      좋습니다.

// void foo(int n = 100) { cout << "foo(int)" << endl; }
void foo(int n) { cout << "foo(int)" << endl; }
void foo() { cout << "foo()" << endl; }

int main()
{
    foo();
}
