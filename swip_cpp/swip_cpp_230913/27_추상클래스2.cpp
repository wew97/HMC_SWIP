// 27_추상클래스2.cpp
#include <iostream>
using namespace std;

class Camera {
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Start Recording" << endl; }
};

class FHDCamera {
public:
    void StartRecording() { cout << "[FHD]Start Recording" << endl; }
    void StopRecording() { cout << "[FHD]Start Recording" << endl; }
};

// 새로운 카메라가 추가될 때마다, 자동차의 코드는 수정되어야 합니다.
//  => OCP를 만족하지 않습니다.
class Car {
    Camera* camera;

public:
    Car(Camera* p)
        : camera { p }
    {
    }

    void Go()
    {
        camera->StartRecording();
        cout << "Car go" << endl;
        camera->StopRecording();
    }
};

int main()
{
    Camera camera;
    Car car { &camera };

    car.Go();
}
