// 14_전처리기5.c
#include <stdio.h>

// C/C++ 에는 미리 정의되어 있는 매크로가 있습니다.
// 1) __FILE__: 컴파일한 소스 코드의 파일명
// 2) __LINE__: 현제 소스 코드의 라인위치
// 3) __STDC_VERSION__: 현재 컴파일되는 C 표준 버전(long)

#if 0
void LOG(const char* message)
{
    printf("%s:%d> %s\n", __FILE__, __LINE__, message);
}
#endif
// __LINE__ 정보를 이용하는 함수를 만들기 위해서는,
// 매크로 함수로 제공해야 합니다.
// #define DEBUG

#ifdef DEBUG
#define LOG(message) \
    printf("%s:%d> %s\n", __FILE__, __LINE__, message)
#else
#define LOG(message) (void)0
// (void)로 캐스팅하면, 기계어 코드가 만들어지지 않습니다.
// (void)0의 의미는 세미 콜론을 위해서 사용합니다. NO-OP
#endif

int main(void)
{
    LOG("hello");
    LOG("bye");

    printf("%ld\n", __STDC_VERSION__);
    // 201112 => C11
    // 199901 => C99

#if __STDC_VERSION__ == 199901L
    printf("C99 표준입니다.\n");
#elif __STDC_VERSION__ == 201112L
    printf("C11 표준입니다.\n");
#endif

    return 0;
}