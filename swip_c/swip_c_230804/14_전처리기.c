// 14_전처리기.c

// 1. 빌드 과정
// : a.c
//    전처리 => 컴파일|------
//   b.c                 |-> 링크(a.o + b.o) -> a.exe(실행 파일)
//    전처리 => 컴파일|------

// 2. 전처리기(preprocessor)
//  - 텍스트 처리
// 1) #include
//     => 파일의 모든 내용을 현재 소스 코드에 합쳐줍니다.
//     => 헤더 파일은 다른 파일에서 제공하는 함수의 선언 / 전역 변수의 선언을
//        가지고 있습니다.
//     => typedef를 통해서 작성된 타입의 정보
//     => struct, union, enum을 통해서 제공하는 타입의 정보

#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(void)
{
    int result = add(10, 20);
    printf("%d\n", result);

    struct Complex a = { .real = 10, .image = 3 };
    struct Complex b = { .real = 10, .image = 3 };

    struct Complex r;
    Add(&a, &b, &r);

    PrintComplex(&r);

    return 0;
}