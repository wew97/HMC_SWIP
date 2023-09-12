// 19_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
};

// 복사 생성자가 호출되는 시점
// 2) 함수가 객체를 값으로 반환할 때

Sample s;
// 위의 객체는 foo 함수와 상관없이 유효합니다.
// 참조로 반환할 수 있습니다.

Sample& foo()
{
    return s;
}

#if 0
Sample foo()
{

    return s;
    // 1. 함수가 객체를 값으로 반환하면,
    //    반환용 임시 객체가 복사 생성자를 통해 생성됩니다.
}
#endif

int main()
{
    cout << "---------" << endl;
    foo();
    // 2. 반환용 임시 객체의 소멸자가 호출됩니다.
    cout << "---------" << endl;
}
