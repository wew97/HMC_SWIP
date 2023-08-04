// 15_���������.c
#include <stdio.h>
// #include <unistd.h> Linux������ ����

// Linux / Unix
// => ��� ���� �����Դϴ�.
//    ������ ������ ���� �Ϲ� ����, ����̽� ����, ���� ����...
//    �� �ٷ� �� �ֽ��ϴ�.

// printf ==> stdout ���Ͽ� ����ϰ� �ֽ��ϴ�.
// scanf  ==> stdin  ���Ϸκ��� �Է��ϰ� �ֽ��ϴ�.

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

// ������ ���(��ġ)
// - ���� ���
//   : C:\Users\Administrator\Deskop\a.txt
//     /home/user1/Destop/a.txt

// - ��� ���
//  => . : ���� ���丮
//    .. : �θ� ���丮
//   ����(���� �۾� ���丮)
//  => ������ �ٷ� ��, ���� ��� ��� ���ٴ� ��� ��θ� ����ϴ� ����
//     �Ϲ����Դϴ�.

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
    FILE* fp = fopen("./a.txt", "a"); // - Unix ����
    // FILE* fp = fopen(".\\a.txt", "w");  // - Windows ����

    fprintf(fp, "Hello, World!!!\n");

    return 0;
}
#endif

// - FILE *fopen(const char* path, const char* mode);
// ������ ���� ���
// - "w"
//  : ������ ���� ���� ���ϴ�.
//    ������ �������� ���� ���, ���ο� ������ �����մϴ�.
//    ������ ������ ���, ������ ũ�⸦ 0���� �ٲߴϴ�.

// - "r"
//  : ������ �б� ���� ���ϴ�.
//    ������ �������� ���� ���, �����մϴ�.

// - "w+"
//  : ������ �б�/���� ���� ���ϴ�.
//    ������ �������� ���� ���, ���ο� ������ �����մϴ�.
//    ������ ������ ���, ������ ũ�⸦ 0���� �ٲߴϴ�.

// - "r+"
//  : ������ �б�/���� ���� ���ϴ�.
//    ������ �������� ���� ���, �����մϴ�.

// - "a"
//  : ������ ���� ���� ���ϴ�.
//    ������ �������� ������ ���ο� ������ �����մϴ�.
//    ������ ������ ���, ������ ���������� �ۼ��˴ϴ�.

// - "a+"
//  : ������ �б�/���� ���� ���ϴ�.
//    ������ �������� ������ ���ο� ������ �����մϴ�.
//    ������ ������ ���, ������ ���������� �ۼ��˴ϴ�.

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