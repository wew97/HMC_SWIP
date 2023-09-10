// 7_함수.cpp
#include <iostream>
using namespace std;

#if 0
int add(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int main()
{
    cout << add(10, 20, 30, 40) << endl;

    cout << add(10, 20, 30, 0) << endl;

    cout << add(10, 20, 0, 0) << endl;
}
#endif

// Default Parameter(파라미터 기본값)
// 정의: 전달되지 않은 함수의 인자를 파라미터 기본값으로 컴파일러가
//      자동으로 처리합니다.

// 주의사항 2가지
// 1) 반드시 뒤에서부터 지정해야 합니다.
// 2) 함수가 선언과 구현으로 분리되서 제공될 경우,
//    선언부에 파라미터 기본값이 작성됩니다.

int add(int a, int b, int c = 0, int d = 0);

int main()
{
    cout << add(10, 20, 30, 40) << endl;

    cout << add(10, 20, 30) << endl;
    //      add(10, 20, 30, 0)

    cout << add(10, 20) << endl;
    //      add(10, 20, 0, 0)
}

// 함수의 구현부에서 파라미터 기본값 여부를 주석으로 표현하는 경우가 있습니다.
int add(int a, int b, int c /*=0*/, int d /*=0*/)
{
    return a + b + c + d;
}
