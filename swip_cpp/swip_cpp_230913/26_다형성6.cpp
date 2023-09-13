// 26_다형성6.cpp
#include <iostream>
using namespace std;

// Car
//  |
// Sedan
//  |
// Genesis

class Car {
public:
    virtual void Start() { cout << "Car Start" << endl; }
};

class Sedan : public Car {
public:
    // 모든 Sedan의 Start는 Sedan Start로 동작해야 합니다.
    //  => C++11, 오버라이딩 금지 => final
    void Start() override final { cout << "Sedan Start" << endl; }
};

// => C++11, 상속 금지 => final
class Genesis final : public Sedan {
public:
    // void Start() override { cout << "Genesis Start" << endl; }
};

// class Genesis2 : public Genesis { };

int main()
{
    Car* p;

    Sedan s;
    Genesis g;

    p = &s;
    p->Start();

    p = &g;
    p->Start();
}
