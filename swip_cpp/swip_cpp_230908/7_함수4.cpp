// 7_함수4.cpp
#include <iostream>
using namespace std;

#if 0
int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }
#endif
// - 함수의 인자와 반환 타입만 다르고, 구현(알고리즘)이 동일할 때
//   코드를 컴파일러에 의해 생성할 수 있습니다.

// Template
//   컴파일러가 컴파일 시간에 필요한 타입에 따른 코드를 자동으로
//   생성합니다.
//  장점
//   - 적은 코드로 모든 타입에서 동작하는 일반적인 함수를 정의할 수 있습니다.
//  단점
//   - 사용자가 필요한 만큼의 함수를 생성하기 때문에,
//     코드 메모리 사용량이 증가됩니다.
//    => 인라인 최적화가 수행될 경우, 코드 메모리 사용량이 최적화됩니다.

//   - 컴파일 시간이 늘어납니다.
#if 0
template <typename TYPE>
TYPE square(TYPE x)
{
    return x * x;
}

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(1000000000LL) << endl;
}
#endif

template <typename TYPE>
TYPE square(TYPE x)
{
    return x * x;
}

template <typename T1, typename T2> // 타입 파라미터
void foo(T1 a, T2 b) // 값 파라미터
{
}

int main()
{
    foo<int, double>(10, 3.14);
    // ------------- ---------
    //  Type 인자      값 인자

    square(10);
    // 컴파일러가 전달된 인자를 기반으로 TYPE을 int로 결정해서
    // 코드를 생성합니다.
    //  => 암묵적으로 추론
    //  int square(int x) { return x * x; }

    short x = 100;
    square<int>(x);
    // => 명시적으로 TYPE을 지정할 수 있습니다.
}
