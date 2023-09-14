// 31_연산자오버로딩8.cpp
#include <iostream>
using namespace std;

// 객체의 호출 연산자를 오버로딩 할 수 있습니다.
//  => 함수 객체(Functor)
class Func {
public:
    // 함수 호출 연산자: ()
    // 연산자 재정의 함수: operator()
    //  => 반환 타입과 인자를 자유롭게 만들 수 있습니다.
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

int main()
{
    Func add;

    int result = add(10, 20);
    //           add.operator()(10, 20)

    cout << result << endl;
}
