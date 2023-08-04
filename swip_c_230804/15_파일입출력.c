// 15_파일입출력.c
#include <stdio.h>
// #include <unistd.h> Linux에서만 지원

// Linux / Unix
// => 모든 것이 파일입니다.
//    파일의 연산을 통해 일반 파일, 디바이스 파일, 소켓 파일...
//    을 다룰 수 있습니다.

// printf ==> stdout 파일에 출력하고 있습니다.
// scanf  ==> stdin  파일로부터 입력하고 있습니다.

// int printf(const char *format, ...)
// int fprintf(FILE* stream, const char *format, ...)

#if 0
int main(void)
{
    // printf("Hello, world\n");
    fprintf(stdout, "Hello, world\n");

    int n;
    // scanf("%d", &n);
    fscanf(stdin, "%d", &n);

    fprintf(stdout, "n: %d\n", n);

    return 0;
}
#endif

// - FILE *fopen(const char* path, const char* mode);

// 파일의 경로(위치)
// - 절대 경로
//   : C:\Users\Administrator\Deskop\a.txt
//     /home/user1/Destop/a.txt

// - 상대 경로
//  => . : 현재 디렉토리
//    .. : 부모 디렉토리
//   기준(현재 작업 디렉토리)
//  => 파일을 다룰 때, 절대 경로 기반 보다는 상대 경로를 사용하는 것이
//     일반적입니다.

#if 0
int main(void)
{
    char buf[1024];
    getcwd(buf, sizeof buf);

    printf("%s\n", buf);

    return 0;
}
#endif

#if 0
int main(void)
{
    // FILE* fp = fopen("/Users/ourguide/Desktop/hyundai_230731/a.txt", "w");
    FILE* fp = fopen("./a.txt", "a"); // - Unix 형식
    // FILE* fp = fopen(".\\a.txt", "w");  // - Windows 형식

    fprintf(fp, "Hello, World!!!\n");

    return 0;
}
#endif

// - FILE *fopen(const char* path, const char* mode);
// 파일의 오픈 모드
// - "w"
//  : 파일을 쓰기 모드로 엽니다.
//    파일이 존재하지 않을 경우, 새로운 파일을 생성합니다.
//    파일이 존재할 경우, 파일의 크기를 0으로 바꿉니다.

// - "r"
//  : 파일을 읽기 모드로 엽니다.
//    파일이 존재하지 않을 경우, 실패합니다.

// - "w+"
//  : 파일을 읽기/쓰기 모드로 엽니다.
//    파일이 존재하지 않을 경우, 새로운 파일을 생성합니다.
//    파일이 존재할 경우, 파일의 크기를 0으로 바꿉니다.

// - "r+"
//  : 파일을 읽기/쓰기 모드로 엽니다.
//    파일이 존재하지 않을 경우, 실패합니다.

// - "a"
//  : 파일을 쓰기 모드로 엽니다.
//    파일이 존재하지 않으면 새로운 파일을 생성합니다.
//    파일이 존재할 경우, 파일의 마지막부터 작성됩니다.

// - "a+"
//  : 파일을 읽기/쓰기 모드로 엽니다.
//    파일이 존재하지 않으면 새로운 파일을 생성합니다.
//    파일이 존재할 경우, 파일의 마지막부터 작성됩니다.

int main(void)
{
    FILE* fp = fopen("a.txt", "r");

    int n;
    fscanf(fp, "%d", &n);
    printf("%d\n", n);

    fscanf(fp, "%d", &n);
    printf("%d\n", n);

    fscanf(fp, "%d", &n);
    printf("%d\n", n);

    fscanf(fp, "%d", &n);
    printf("%d\n", n);

    return 0;
}