// 26_다형성9.cpp
#include <iostream>
#include <vector>
using namespace std;

// * 다형성은 OCP를 만족합니다.
// * Refactoring(리팩토링, 마틴 파울러)
//  : 코드의 기능을 변경하지 않고, 구조를 개선하는 작업
//    "코드의 유지보수성을 떨어뜨리는 요소" => 냄새
//  - Replace type code with polymorphism

class Shape {
public:
    int type = 0;

    virtual ~Shape() { }

    virtual void Draw() const { cout << "Draw Shape" << endl; }
    virtual Shape* Clone() { return new Shape { *this }; }
};

class Rect : public Shape {
public:
    Rect() { type = 1; }

    void Draw() const override { cout << "Draw Rect" << endl; }
    Shape* Clone() override { return new Rect { *this }; }
};

class Circle : public Shape {
public:
    Circle() { type = 2; }

    void Draw() const override { cout << "Draw Circle" << endl; }
    Shape* Clone() override { return new Circle { *this }; }
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
        }

        else if (cmd == 0) {
            cout << "몇번째 도형을 복제하겠습니까? ";
            int index;
            cin >> index;

            // 문제점: 새로운 타입의 도형이 추가될 때마다, 아래 코드는 수정되어야 합니다.
            //   => OCP를 만족하지 않습니다.
            Shape* copy = shapes[index]->Clone();
            shapes.push_back(copy);
#if 0
            if (shapes[index]->type == 1) { // Rect
                // Rect 복제
            } else if (shapes[index]->type == 2) { // Circle
                // Circle 복제
            } else if (shapes[index]->type == 3) {
                // ...
            }
#endif

        }

        else if (cmd == 9) {
            for (auto e : shapes) {
                e->Draw();
            }
        }
    }
}
