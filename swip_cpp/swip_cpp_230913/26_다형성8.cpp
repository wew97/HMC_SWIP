// 26_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 각 도형의 클래스를 설계합니다.
// 2. 부모 클래스
//   => 동종을 보관하는 컨테이너

// 3. 자식 클래스의 공통의 기능을 부모 클래스의 포인터/참조 타입을 통해
//    이용하기 위해서는 해당 특징이 반드시 부모로부터 비롯되어야 합니다.
//    그래야 해당 기능을 부모의 포인터(참조)를 통해 이용할 수 있습니다.
//   => LSP(Liskov Substitution Principle, 리스코프 치환 원칙)
//     : 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.

// 4. 자식이 재정의하는 모든 부모의 멤버 함수는 반드시 가상함수이어야 합니다.
// 5. 부모 클래스의 소멸자도 반드시 가상이어야 합니다.

// 6. OCP(Open Close Principle, 개방 폐쇄 원칙)
//   : 확장에는 열려 있고,(새로운 기능이 추가되어도)
//     수정에는 닫혀 있어야 한다.(기존 코드는 수정되면 안된다.)
//   => 다형성은 OCP를 만족합니다.

class Shape {
public:
    virtual ~Shape() { }
    virtual void Draw() const { cout << "Draw Shape" << endl; }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
};

class Triangle : public Shape {
public:
    void Draw() const override { cout << "Draw Triangle" << endl; }
};

int main()
{
    vector<Shape*> shapes;

    while (true) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        } else if (cmd == 3) {
            shapes.push_back(new Triangle);
        }

        else if (cmd == 9) {
            for (auto e : shapes) {
                e->Draw();
                // e가 Rect 타입이면  Rect::Draw()
                //    Circle       Circle::Draw()
                //    Triangle     Triangle::Draw()
                // => Polymorphism(다형성)
            }
        }
    }
}
