// 12_문자열4.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. 널문자('\0')로 종료되는 char 배열이 문자열입니다.
// 2. 문자열의 연산을 수행하기 위해서는,
//    string.h를 통해서 제공되는 함수를 사용해야 합니다.
//  - 문자열 길이: strlen
//  size_t strlen(const char *s);

//  - 문자열 복사: strcpy
//  char* strcpy(char* dest, const char* src);

//  - 문자열 복사: strcat
//  char* strcat(char* dest, const char* src);

//  - 문자열 비교
//  int strcmp(const char* lhs, const char* rhs);
//   lhs < rhs: 음수
//   lhs > rhs: 양수
//  lhs == rhs: 0

// 3. 문자열 연산을 사용할 때,
//    유효한 메모리 영역에 대해서 연산이 수행되는지 주의해야 합니다.
#if 0
int main(void)
{
    char str[32] = "hello";
    const char* s = "hello";

    return 0;
}
#endif
// 4. char *strtok(char* str, const char* sep);
//   : 정적 메모리(전역 변수, 정적 지역 변수)의 주소가 반환됩니다.
//    char *strdup(const char *s1);
//   : 동적 메모리 할당의 주소를 반환합니다.

#if 0
int main(void)
{
    char str[32] = "hello,world,show,me,the,money"; // CSV

    char* p = NULL; // 포인터는 사용하지 않을 때, 항상 NULL로 초기화해야 합니다.

    p = strtok(str, ",");
    printf("%s\n", p);

    p = strtok(NULL, ",");
    printf("%s\n", p);

    p = strtok(NULL, ",");
    printf("%s\n", p);

    p = strtok(NULL, ",");
    printf("%s\n", p);

    p = strtok(NULL, ",");
    printf("%s\n", p);

    p = strtok(NULL, ",");
    printf("%s\n", p);

    p = strtok(NULL, ",");
    printf("%s\n", p);

    return 0;
}
#endif

#if 0
void foo(void)
{
    char str[32] = "Tom,Alice,Bob"; // CSV
    char* p = NULL;
    p = strtok(str, ",");

    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, ",");
    }
}

int main(void)
{
    char str[32] = "hello,world,show,me,the,money"; // CSV

    char* p = NULL; // 포인터는 사용하지 않을 때, 항상 NULL로 초기화해야 합니다.

    p = strtok(str, ",");

    foo();

    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, ",");
    }

    return 0;
}
#endif

#if 0
void foo(void)
{
    char str[32] = "Tom,Alice,Bob"; // CSV
    char* p = NULL;
    char* lasts = NULL;
    p = strtok_r(str, ",", &lasts);

    while (p != NULL) {
        printf("%s\n", p);
        p = strtok_r(NULL, ",", &lasts);
    }
}

// 리눅스의 C 라이브러리는 재진입이 불가능한 함수에 대해서
// 재진입 가능한 버전을 별도로 제공해줍니다.
//  ex) strtok_r
//   - 표준이 아닙니다.
//   char *strtok_r(char *str, const char *sep, char ** lasts);

int main(void)
{
    char str[32] = "hello,world,show,me,the,money"; // CSV

    char* p = NULL; // 포인터는 사용하지 않을 때, 항상 NULL로 초기화해야 합니다.
    char* lasts = NULL;

    p = strtok_r(str, ",", &lasts);

    foo();

    while (p != NULL) {
        printf("%s\n", p);
        p = strtok_r(NULL, ",", &lasts);
    }

    return 0;
}
#endif

// 5. char *strdup(const char* s1);
//   : 동적 메모리 할당의 주소를 반환합니다.

// 사용자로부터 문자열(CSV)를 입력 받아서,
// 파싱하는 프로그램을 작성해봅시다.

// 6. fgets 함수를 이용해서, 입력을 받는 것이 안전합니다.

int main(void) {
    // int n;
    // scanf("%d", &n);

    // 문자열을 입력 받을 때, scanf는 위험합니다.
    // : Buffer Overflow 공격의 위험성이 있습니다.
    
    char buf[64];
    // scanf("%s", buf);
    fgets(buf, sizeof(buf), stdin); // 64B가 넘어가게 입력해도 64B까지만

    printf("%s\n", buf);

    // 동적 메모리 할당을 통해서 복사본을 저장합니다.
    // char* src = malloc(strlen(buf) + 1);
    // strcpy(src, buf);

    char* src = strdup(buf);

    for (char* p = strtok(buf, ","); 
        p != '\0';
        p = strtok(NULL, ",")) 
    {
        printf("%s\n", p);
    }

    printf("buf: %s\n", src);
    
    free(src); // strdup 이후로 free 필수!

    return 0;
}