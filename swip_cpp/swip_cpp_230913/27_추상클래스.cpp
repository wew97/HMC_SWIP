// 27_추상클래스.cpp
#include <iostream>
using namespace std;

// 결론: 순수 가상 함수를 가지는 클래스를 "추상 클래스"라고 합니다.
//    1) 추상 클래스는 객체를 생성할 수 없습니다.
//    2) 자식 클래스가 부모 클래스가 제공하는 순수 가상 함수를 오버라이딩 하지 않으면
//       자식 클래스도 추상 클래스가 됩니다.
//     => 자식 클래스의 입장에서 반드시 제공해야 합니다.

// 순수 가상 함수를 1개 이상 가지는 클래스는
// 객체를 생성할 수 없는 추상 클래스가 됩니다.
class Shape {
public:
    int type = 0;

    virtual ~Shape() { }

    // Shape의 객체를 생성하지 않습니다.
    // 아래의 함수도 절대 호출되지 않습니다.

    // 부모의 입장에서는 아래의 구현을 제공할 필요가 없고,
    // 자식의 입장에서는 반드시 아래의 구현을 오버라이딩 해야 합니다.
    // => 순수 가상 함수(pure virtual function)
    virtual void Draw() const = 0;
    virtual Shape* Clone() = 0;
};

// 자식 클래스가 부모 클래스가 제공하는 순수 가상함수를 재정의하지 않으면,
// 자식 클래스도 추상 클래스가 되어, 객체를 생성할 수 없습니다.
// => 부모가 제공하는 Draw / Clone을 반드시 구현해야 합니다.
class Rect : public Shape {
public:
    void Draw() const override { }
    Shape* Clone() override { return nullptr; }
};

int main()
{
    // Shape s;
    Rect r;
}
