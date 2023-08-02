// 12_문자열.c
#include <stdio.h>

// 1. C의 문자 타입
//   char

// 2. 메모리에는 정수/실수만 저장합니다.
//    각 문자에 고유의 번호를 지정하고, 각 값에 따른 약속된 문자를
//    출력합니다.
//   : ASCII
//  A: 65
//  a: 97
//  0: 48

// 3. 한글 등의 문자를 표현하기 위해서는
//    ASCII를 통해서는 표현이 불가능합니다.
//  => 유니코드
//      UTF-8 / UTF-16 / UTF-32
//  => MBCS(Multibyte Character Set)
//      euc-kr / CP949
//  : wchar_t

#if 0
int main(void)
{
    // char ch = 65;
    char ch = 'A';

    printf("%c\n", ch);
    printf("%hhd\n", ch);

    return 0;
}
#endif

#if 0
#include <wchar.h>

int main(void)
{
    wchar_t ch = L'한';
    wprintf(L"%lc\n", ch);

    return 0;
}
#endif

// 문자열
//  정의: 0으로 끝나는 char 배열입니다.
#if 0
int main(void)
{
    char str[6];

    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    // str[5] = 0; /* 문자열의 끝을 의미합니다. */
    str[5] = '\0'; /* 문자열의 끝을 의미합니다. */

    printf("%s\n", str);

    return 0;
}
#endif

// - 문자와 문자열의 차이를 이해해야 합니다.
// 'A' : [ 65 ]       => char
// "A" : [ 65 ][ 0 ]  => char[2]
#if 0
int main(void)
{
    char str[6] = "hello";
    // char 배열이 문자열의 길이에 널문자까지 포함되는 크기를
    // 충분히 확보해야 합니다.

    printf("%zu\n", sizeof("hello"));
    printf("%s\n", str);

    return 0;
}
#endif

// .TEXT 영역은 문자열이나 컴파일된 기계어 코드가 저장됩니다.
// => 수정 불가능한 메모리(Read Only)
#if 0
int main(void)
{
    printf("%p\n", "hello");
    printf("%p\n", "hello");

    const char* s = "hello";
    // 문자열을 포인터를 통해서 참조할 때,
    // 반드시 const char*를 사용해야 합니다!

    char str[] = "hello";

    printf("%s\n", s);
    // s[0] = 'X'; /* 미정의 동작 */
    str[0] = 'X'; /* OK! */

    return 0;
}
#endif

#if 0
int main(void)
{
    const int n = 10; // const int
    const int* p = &n; // const int*

    printf("%d\n", *p);
    // *p = 100; /* 대상체의 값을 변경할 수 없습니다 */

    int x = 20;
    const int* px = &x; /* OK! */
    // 의도: x는 수정 가능한 메모리지만, 포인터 px를 통해서
    // 값을 읽기만 하고 변경하지 않겠다.

    return 0;
}
#endif

// p -------> [ n ]

// - * 기호의 앞에 const가 있으면
//  p -------> n
//           <const>
//  : 포인터를 통해서 대상체의 값을 변경할 수 없습니다.

// - * 기호의 뒤에 const가 있으면
//    p -------> n
// <const>
//  : 포인터를 다른 주소로 변경할 수 없습니다.

int main(void)
{
    int n = 100;

    const int* pn1 = &n;
    int const* pn2 = &n;
    // 대상체가 const 입니다.
    // 포인터를 통해서 값을 변경할 수 없습니다.

    int* const pn3 = &n;
    // 포인터 변수가 const 입니다.
    // 대상체를 변경할 수 있지만, 자기 자신을 다른 주소로
    // 변경할 수 없습니다.

    const int* const pn4 = &n;
    int const* const pn5 = &n;

    return 0;
}