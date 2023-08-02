// foo.c
#include <stdio.h>

// 전역 변수 / 전역 함수의 앞에 static을 붙이면 내부 연결을 갖습니다.
// => static(통용 범위 지정자)

static int count = 0;
// 전역 변수 앞에 static 붙이면
// Internal linkage로 변경됩니다.
// => 다른 파일에서는 접근이 불가능하고
//    같은 파일에서만 접근이 가능합니다.

static void goo(void)
{
    printf("goo\n");
}

void foo(void)
{
    goo();
    printf("count: %d\n", ++count);
}