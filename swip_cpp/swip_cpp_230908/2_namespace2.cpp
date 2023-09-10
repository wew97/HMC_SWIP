// 2_namespace2.cpp
#include <iostream>

// namespace를 이용하는 방법 3가지
// 1) 전체 이름을 명시하는 방법
#if 0
namespace audio {
void Play() { std::cout << "Audio Play" << std::endl; }
}

int main()
{
    audio::Play();
    std::cout << "Hello, C++" << std::endl;
}
#endif

// 2) using 선언(declaration)
#if 0
using std::cout;
using std::endl;

namespace audio {
void Play() { cout << "Audio Play" << endl; }
}

using audio::Play;

int main()
{
    Play();
    cout << "Hello, C++" << endl;
}
#endif

#if 0
// 3) using 지시어(directive)
// - 특정 이름 공간의 모든 요소를 암묵적으로 접근할 수 있습니다.
// - 이름 충돌의 문제가 발생할 수 있습니다.
//   현업에서는 사용하지 않는 것이 좋습니다.
using namespace std;

namespace audio {
void Play() { cout << "Audio Play" << endl; }
}

using namespace audio;

int main()
{
    Play();
    cout << "Hello, C++" << endl;
}
#endif

#if 0
using std::cout;
using std::endl;
// using namespace std;
// std::count와 전역 이름 공간의 count의 이름 충돌의 문제가 발생하였습니다.

int count = 0;
// 전역 이름 공간(global namespace)

int main()
{
    cout << count << endl;
}
#endif

// #include <stdio.h>
#include <cstdio>
// C의 모든 헤더를 c의 접두를 가지는 확장자가 없는 형태로
// 사용할 수 있습니다.
//  stdlib.h -> cstdlib
//  string.h -> cstring

int main()
{
    // C++은 C의 모든 기능을 std 이름 공간 안에서 사용할 수 있습니다.
    std::printf("Hello, C\n");
}
