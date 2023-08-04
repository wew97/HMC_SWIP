// 15_파일입출력2.c
#include <stdio.h>
#include <string.h>
#include <errno.h> // errno 전역 변수

// fopen은 파일을 여는데 실패할 수 있습니다.
// 실패할 경우, NULL을 반환합니다.

// => 실패 가능한 함수는 반드시 오류를 처리해야 합니다.

// - 에러를 처리하는 방법
// 1) C의 일부 함수는 에러가 발생한 경우,
//    에러의 원인을 errno를 통해 알 수 있습니다.
//     #include <errno.h>

// 2) errno는 반드시 실패한 연산을 수행하고 난 다음에
//    바로 확인해야 합니다.

// 3) errno를 통해서 에러의 원인을 문자열로 변경할 수 있습니다.
//    strerror(errno)

// 3) 에러를 출력한다면, perror 함수를 이용하면 편리합니다.
//    #include <stdio.h>
#if 0
int main(void)
{
    printf("errno: %d\n", errno);
    FILE* fp = fopen("x.txt", "r");
    printf("errno: %d\n", errno);

    printf("fp: %p\n", fp);
    if (fp == NULL) {
        // printf("파일을 여는데 실패하였습니다.\n");
        // printf("fopen(): %s\n", strerror(errno));
        perror("fopen()");
    }

    return 0;
}
#endif

int main(void)
{
    FILE* fp = fopen("a.txt", "w");
    // 버퍼의 크기가 일정 채워지기 전까지
    // 실제 파일에 기록되지 않습니다.

    fprintf(fp, "Hello, world\n");
    fprintf(fp, "Hello, world\n");
    fprintf(fp, "Hello, world\n");

    fclose(fp); // 파일을 닫습니다.
    // 1) 파일을 관리하기 위한 구조체의 메모리를 해지합니다.
    // 2) 파일의 버퍼를 비웁니다.

    int n;
    scanf("%d", &n);

    return 0;
}