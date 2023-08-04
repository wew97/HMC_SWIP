// 15_파일입출력3.c

#include <stdio.h>

// - fopen / fclose
// - 파일로부터 데이터를 읽을 때,
//   파일의 끝에 도달할 때까지 데이터를 읽어야 합니다.

// - scanf는 입력에 성공한 필드의 개수를 반환합니다.
//   실패할 경우, -1을 반환합니다.

// - 파일으로부터 입력을 처리할 때,
//   EOF가 도달하였을 때의 반환값을 체크해서
//   입력을 종료해야 합니다.
#if 0
int main(void)
{
    int n;
    int sum = 0;
    int ret;

    FILE* fp = fopen("a.txt", "r");
    if (fp != NULL) {

        while (1) {
            ret = fscanf(fp, "%d", &n);
            if (ret == -1) {
                break; // 파일의 끝(EOF)에 도달했다.
            }

            sum += n;
        }

        printf("sum: %d\n", sum);

        fclose(fp);
    }

    return 0;
}
#endif

// 핵심: 키보드로부터의 입력도, 파일(stdin)로부터의 입력입니다.
//  동일하게 파일의 끝(EOF)을 기준으로 입력을 종료하는 것이
//  좋습니다.

// - 키보드로 파일의 끝을 전달하는 방법
// Linux: Ctrl + D
// Windows: Ctrl + Z

// - 리다이렉션
// $ ./a.out < a.txt
//   : a.txt를 열어서 stdin으로 설정해서 실행합니다.

#if 0
int main(void)
{
    int n;
    int sum = 0;
    int ret;

    while (1) {
        ret = scanf("%d", &n);
        if (ret == -1) {
            break; // 파일의 끝(EOF)에 도달했다.
        }

        sum += n;
    }

    printf("sum: %d\n", sum);

    return 0;
}
#endif

// $ a.out > b.txt    "w"
//   a. out >> b.txt  "a"

// : b.txt를 stdout으로 설정합니다.

#if 0
int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("hello\n");
    }

    return 0;
}
#endif

// stdin:  0
// stdout: 1
// stderr: 2

// $ ./a.out 2> error.txt
//  - stderr를 파일로 지정합니다.

// $ ./a.out 2>> error.txt
//  - stderr를 파일로 지정합니다.
//  - Append mode

int main(void)
{
    fprintf(stderr, "File open error!\n");

    return 0;
}