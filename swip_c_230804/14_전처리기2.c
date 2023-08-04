// 14_전처리기2.c
#include <stdio.h>

// 2) #define
//  => 매크로
//  => 전처리 과정에서 텍스트를 치환합니다.

// 활용 1) 매크로 상수
// => 상수에 이름을 부여해서 사용할 수 있습니다.
#if 0
#define MY_PROJECT_NAME "Hello World"
#define PI 3.141592

int main(void)
{
    printf("%s\n", MY_PROJECT_NAME);
    printf("%lf\n", PI);

    return 0;
}
#endif

// 활용 2) 매크로를 이용해서 조건부 컴파일
// #define DEBUG
// gcc 14_전처리기2.c -DDEBUG
// : 컴파일 명령을 통해 컴파일시에 조건부 컴파일을 위한
//   매크로를 주입할 수 있습니다.

// - #ifdef - #else - #endif
// - #ifndef - #else - #endif
// - #if defined(DEBUG) - #else - #endif
#if 0
int main(void)
{
#ifdef DEBUG
    printf("프로그램 시작..\n");
#else
    printf("DEBUG가 정의되어 있지 않습니다.\n");
#endif

#ifndef DEBUG
    printf("DEBUG가 정의되어 있지 않습니다.\n");
#else
    printf("프로그램 시작..\n");
#endif

    return 0;
}
#endif

// => include guard
// => 헤더 파일을 작성할 때, 중복 포함의 문제가 발생하지 않도록
//    헤더에는 반드시 include guard를 작성해야 합니다.
#if 1
#ifndef ADD_H
#define ADD_H

int a;

#endif

#ifndef ADD_H
#define ADD_H
int a;
#endif

int main(void)
{
    return 0;
}
#endif

// 아래 표현도 동일한 방법입니다.
#if !defined(ADD_H)
#define ADD_H
int a;
#endif

#if !defined(ADD_H)
#define ADD_H
int a;
#endif

#define AAA
#define BBB

int main(void)
{
#if defined(AAA) && defined(BBB)
    printf("AAA와 BBB 모두 정의되어 있습니다.\n");
#endif

#if defined(AAA) || defined(BBB)
    printf("AAA와 BBB 둘중 하나라도 정의되어 있습니다.\n");
#endif

    return 0;
}