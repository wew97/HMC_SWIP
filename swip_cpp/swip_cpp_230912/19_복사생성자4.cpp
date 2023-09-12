// 19_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
};

// 아래 코드는 미정의 동작을 야기합니다.
//  : 지역 객체는 반드시 값으로 반환해야 합니다.
#if 0
Sample& foo()
{
    Sample s;
    return s;
}
#endif

// C++ 컴파일러는 함수가 지역 객체를 값으로 반환할 때,
// 반환용 임시 객체의 복사 생성/제거 비용을 최적화합니다.
//  : RVO(Return Value Optimization)
//  => 반환할 때, 임시 객체를 반환해야 합니다.
//  : NRVO(Named Ruturn Value Optimization)
//  => 임시 객체가 아닌 일반적인 지역 객체도 반환용 임시 객체 복사 생성/제거
//     비용을 최적화합니다.

// 핵심: C++에서 지역 객체를 값으로 반환할 때,
//      불필요한 반환용 임시 객체의 복사/제거 비용이 발생하지 않습니다.
Sample foo()
{
    Sample s;
    return s;
    // return Sample(); // 임시 객체 생성 문법
}

int main()
{
    cout << "---------" << endl;
    foo();
    cout << "---------" << endl;
}
