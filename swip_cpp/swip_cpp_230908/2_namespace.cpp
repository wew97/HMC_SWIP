// 2_namespace.cpp
#include <iostream>

// 1. C에서는 이름 충돌을 위한 언어적 기능이 제공되지 않습니다.
// => 다른 이름을 약속해야 합니다.

// 2. 이름 충돌의 문제를 해결하기 위해,
//    namespace 문법을 지원합니다.

// 3. C++ 표준의 모든 요소는 std의 이름공간을 통해서
//    제공됩니다.

// 4. namespace를 사용하면, 프로그램의 각 요소를 관련된 요소끼리
//    그룹화할 수 있습니다.

// 5. namespace의 이름은 소문자로 하는 것이 일반적입니다.

namespace audio {
void Init() { std::cout << "Audio Init" << std::endl; }

int global = 100;
}

namespace video {
void Init() { std::cout << "Video Init" << std::endl; }

namespace mp3 {
    void Play() { }
}

namespace mp4 {
    void Play() { }
}

int global = 0;
}

int main()
{
    std::cout << audio::global << std::endl;
    std::cout << video::global << std::endl;

    video::mp3::Play();
    video::mp4::Play();

    audio::Init();
    video::Init();
}
