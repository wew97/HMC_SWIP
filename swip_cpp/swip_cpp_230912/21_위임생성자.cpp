// 21_위임생성자.cpp
#include <iostream>
using namespace std;

class Color {
    int red;
    int green;
    int blue;

    // 외부에서 호출할 필요가 없고, 내부에서만 수행되는 멤버 함수는
    // private 영역으로 제공하는 것이 좋습니다.
    void InitProcess1() { cout << "초기화1" << endl; }
    void InitProcess2() { cout << "초기화2" << endl; }

public:
    Color(int r, int g, int b)
        : red { r }
        , green { g }
        , blue { b }
    {
        InitProcess1();
        InitProcess2();
    }

    // 클래스의 기본 생성자를 제공하는 것이 편리할 때가 많습니다.
    // C++11, 위임 생성자
    //  정의: 자신의 다른 생성자를 통해 객체를 초기화할 수 있습니다.
    //      "생성자에서 다른 생성자를 호출할 수 있습니다."
    // => 생성자에서 발생하는 중복된 코드를 제거할 수 있습니다.
    Color()
        : Color(0, 0, 0) // 위임 생성자!
    {
    }

#if 0
    Color()
        : red { 0 }
        , green { 0 }
        , blue { 0 }
    {
        InitProcess1();
        InitProcess2();
    }
#endif
};

int main()
{
    Color c { 10, 20, 155 };

    Color x;
}
