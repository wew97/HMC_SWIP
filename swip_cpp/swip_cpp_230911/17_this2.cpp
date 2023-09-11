// 17_this2.cpp
#include <iostream>
using namespace std;

#if 0
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

int main()
{
    Sample s;
    // Sample::Sample()
} // Sample::~Sample();
#endif

// private 소멸자
//   의도
//   - 지역 객체와 전역 객체를 생성할 수 없습니다.
//   => new를 통해서만 객체를 생성하도록 하겠다.
//      수명 관리 기법을 사용하는 경우에 많이 적용됩니다.

class Sample {
private:
    ~Sample() { cout << "~Sample()" << endl; }

public:
    Sample() { cout << "Sample()" << endl; }

    // void Destroy(Sample* this)
    void Destroy()
    {
        delete this;
    }
};

// Sample s;

int main()
{
    Sample* p = new Sample;

    // delete p;
    p->Destroy();
    // Sample::Destroy(p);

    // Sample s;
}
