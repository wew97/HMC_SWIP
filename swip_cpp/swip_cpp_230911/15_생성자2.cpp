// 15_생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(int a) { cout << "Sample(int)" << endl; }

    ~Sample() { cout << "~Sample()" << endl; }
};

// 1. malloc을 통해 객체를 생성할 경우,
//    생성자가 호출되지 않습니다.

// 2. free를 통해 객체의 메모리를 해지한 경우,
//    소멸자가 호출되지 않습니다.

// 3. new를 통해 객체를 생성하였을 때,
//    생성자가 호출됩니다.
//  * new 연산
//  1) 동적 메모리 할당
//  2) 생성자 호출

// 4. delete를 통해 객체의 메모리를 해지한 경우,
//    소멸자가 호출됩니다.
//  * delete 연산
//  1) 소멸자 호출
//  2) 동적 메모리 해지

int main()
{
    // Sample* p = new Sample[3];
    Sample* p = new Sample[3] {
        Sample(10), // { 10 },
        { 30 },
        { 50 },
    };

    delete[] p; // !!
}

#if 0
int main()
{
    // Sample* p = new Sample; // Sample()

    // Sample* p = new Sample(10); // Sample(int)
    Sample* p = new Sample { 10 };
    delete p;
}
#endif

#if 0
int main()
{
    Sample* p = static_cast<Sample*>(malloc(sizeof(Sample)));
    free(p);
}
#endif
