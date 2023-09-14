// 31_연산자오버로딩5.cpp
#include <iostream>
using namespace std;

// 1. 연산자를 재정의할 때,
//    기본 타입이 동작하는 형태와 유사하게 작성되어야 합니다.

// 2. 사용자 정의 타입을 기본 타입과 유사한 형태로 동작하도록 만들어 줄 수 있습니다.

// 3. 사용자 정의 타입의 연산자 오버로딩은 인라인 최적화를 통해 기본 타입을 직접 다루는 것과
//    비슷합니다.

// 클래스안에 멤버 함수의 구현을 제공한 경우(헤더 파일에 구현이 제공된 경우)
// 인라인 함수 취급합니다.

class Integer {
    int value;

public:
    inline Integer(int n = 0)
        : value { n }
    {
    }

    // ++n
    inline Integer& operator++()
    {
        ++value;
        return *this;
    }

    // n++
    inline Integer operator++(int)
    {
        // 1. 증가되기 이전의 복사본
        Integer temp { *this };

        // 2. 자기 자신의 값은 증가합니다.
        ++value;

        // 3. 복사본을 반환합니다.
        return temp;
    }

    // 아래 함수는 일반 함수입니다.
    // 클래스 안에 구현도 제공할 수 있습니다.
    friend inline ostream& operator<<(ostream& os, const Integer& n)
    {
        return os << n.value;
    }
};

int main()
{
    Integer n1 { 0 };
    // ++ ++n1;
    // n1.operator++().operator++()
    ++n1;

    n1++;
    // n1.operator++(int) // ++n, n++을 구분하기 위해서

    cout << n1 << endl;

    int n2 { 0 };
    // ++ ++ ++n2;
    ++n2;
    n2++;
    cout << n2 << endl;
}

// ++n;
//   C: 연산의 결과는 증가된 값
// C++: 연산의 결과는 증가된 자기 자신의 참조
//

// n++;
//   C: 연산의 결과는 증가되기 이전의 값
// C++: 연산의 결과로 증가되고, 증가되기 이전의 복사본

// for (int i = 0 ; i < 10; i++) {} - C
// for (int i = 0 ; i < 10; ++i) {} - C++
