// 30_다운캐스팅.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() { } // 부모의 소멸자는 가상이어야 합니다.
};

class Dog : public Animal {
    int color = 10;

public:
    int GetColor() const { return color; }
};

class Cat : public Animal { };

// 1. static_cast를 이용하면,
//    부모의 포인터(참조) 타입을 자식의 포인터(참조) 타입으로 변환할 수 있습니다.
//    => 다운 캐스팅이 가능합니다.
//    주의사항: 잘못된 캐스팅을 확인할 수 없습니다.
// 2. dynamic_cast
//   : 실행시간에 객체의 타입을 조사해서, 다운 캐스팅을 수행합니다.
//     실패할 경우, nullptr을 반환합니다.
//     클래스의 가상 함수 테이블이 존재하지 않는 경우,
//     컴파일 오류가 발생합니다.

// [결론]
// C++에서 다운 캐스팅을 수행하는 연산자는 2개가 있습니다.
// - static_cast
//  : 실패 가능성이 없는 다운 캐스팅에서 수행해야 합니다.
//    컴파일 시간에 수행되므로, 성능에 영향이 없습니다.

// - dynamic_cast
//  : 실패 가능성이 존재하는 다운 캐스팅에서 수행해야 합니다.
//    실행시간에 객체의 타입을 조사해서, 잘못된 다운 캐스팅을 확인할 수 있습니다.

#if 0
int main()
{
    Animal* p = new Dog;

    // cout << p->GetColor() << endl;
    //  해결방법: 부모의 포인터(참조) 타입을 자식의 포인터(참조) 타입으로의
    //          명시적인 변환이 필요합니다.
    Dog* pDog = static_cast<Dog*>(p);
    cout << pDog->GetColor() << endl;
}
#endif

int main()
{
    // Animal* p = new Cat;
    Animal* p = new Dog;

    // Dog* pDog = static_cast<Dog*>(p);
    // 캐스팅을 실행할 때, 실행 시간에 객체의 타입을 조사해서,
    // 잘못된 캐스팅 여부를 확인해야 합니다.
    // 잘못된 캐스팅인 경우, nullptr을 반환합니다.
    //  => dynamic_cast
    Dog* pDog = dynamic_cast<Dog*>(p);
    if (pDog) {
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog가 아닙니다." << endl;
    }
}
