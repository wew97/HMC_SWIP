// 15_���������2.c
#include <stdio.h>
#include <string.h>
#include <errno.h> // errno ���� ����

// fopen�� ������ ���µ� ������ �� �ֽ��ϴ�.
// ������ ���, NULL�� ��ȯ�մϴ�.

// => ���� ������ �Լ��� �ݵ�� ������ ó���ؾ� �մϴ�.

// - ������ ó���ϴ� ���
// 1) C�� �Ϻ� �Լ��� ������ �߻��� ���,
//    ������ ������ errno�� ���� �� �� �ֽ��ϴ�.
//     #include <errno.h>

// 2) errno�� �ݵ�� ������ ������ �����ϰ� �� ������
//    �ٷ� Ȯ���ؾ� �մϴ�.

// 3) errno�� ���ؼ� ������ ������ ���ڿ��� ������ �� �ֽ��ϴ�.
//    strerror(errno)

// 3) ������ ����Ѵٸ�, perror �Լ��� �̿��ϸ� ���մϴ�.
//    #include <stdio.h>
#if 0
int main(void)
{
    printf("errno: %d\n", errno);
    FILE* fp = fopen("x.txt", "r");
    printf("errno: %d\n", errno);

    printf("fp: %p\n", fp);
    if (fp == NULL) {
        // printf("������ ���µ� �����Ͽ����ϴ�.\n");
        // printf("fopen(): %s\n", strerror(errno));
        perror("fopen()");
    }

    return 0;
}
#endif

int main(void)
{
    FILE* fp = fopen("a.txt", "w");
    // ������ ũ�Ⱑ ���� ä������ ������
    // ���� ���Ͽ� ��ϵ��� �ʽ��ϴ�.

    fprintf(fp, "Hello, world\n");
    fprintf(fp, "Hello, world\n");
    fprintf(fp, "Hello, world\n");

    fclose(fp); // ������ �ݽ��ϴ�.
    // 1) ������ �����ϱ� ���� ����ü�� �޸𸮸� �����մϴ�.
    // 2) ������ ���۸� ���ϴ�.

    int n;
    scanf("%d", &n);

    return 0;
}