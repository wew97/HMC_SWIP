// 27_추상클래스3.cpp
#include <iostream>
using namespace std;

// 1. 원인
//   Car --------<> Camera
//  : Car 클래스가 Camera 구체적인 타입에 의존하고 있습니다.
//   => 강한 결합
//      : 교체가 불가능합니다.

// 2. 해결 방법
//   => 약한 결합 / 느슨한 결합
//   : 구체적인 타입에 의존하는 것이 아니라, 인터페이스/추상클래스에 의존합니다.
//    "교체 가능한 유연한 설계"
//      : 인터페이스는 OCP를 만족합니다.

//   Car --------<> <<BlackBox>>
//                       |
//                   ----------
//                   |        |
//                Camera   FHDCamera

// 1) 카메라의 제작자와 자동차의 제작자는 사용방법(함수)을 약속합니다.
//   => 인터페이스 / 프로토콜
//   : C++은 인터페이스를 위한 별도의 키워드를 제공하지 않습니다.
class BlackBox {
public:
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 약속된 인터페이스를 이용하는 형태로 코드를
//    작성합니다.
class Car {
    BlackBox* camera;

public:
    Car(BlackBox* p)
        : camera { p }
    {
    }

    void Go()
    {
        camera->StartRecording();
        cout << "Go" << endl;
        camera->StopRecording();
    }
};

// 3) 모든 카메라의 제작자는 BlackBox의 인터페이스를 구현해서,
//    카메라의 기능을 구현합니다.
//  => 인터페이스는 "상속한다" 라고 하지 않고, "구현한다" 고 표현합니다.
//   class Camera extends BlackBox {}
//   class Camera implements BlackBox {}

class Camera : public BlackBox {
public:
    void StartRecording() override { }
    void StopRecording() override { }
};

class FHDCamera : public BlackBox {
public:
    void StartRecording() override { }
    void StopRecording() override { }
};

int main()
{
    FHDCamera camera;
    Car car { &camera };

    car.Go();
}
