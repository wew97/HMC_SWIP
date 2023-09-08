// 15_���������3.c

#include <stdio.h>

// - fopen / fclose
// - ���Ϸκ��� �����͸� ���� ��,
//   ������ ���� ������ ������ �����͸� �о�� �մϴ�.

// - scanf�� �Է¿� ������ �ʵ��� ������ ��ȯ�մϴ�.
//   ������ ���, -1�� ��ȯ�մϴ�.

// - �������κ��� �Է��� ó���� ��,
//   EOF�� �����Ͽ��� ���� ��ȯ���� üũ�ؼ�
//   �Է��� �����ؾ� �մϴ�.
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
                break; // ������ ��(EOF)�� �����ߴ�.
            }

            sum += n;
        }

        printf("sum: %d\n", sum);

        fclose(fp);
    }

    return 0;
}
#endif

// �ٽ�: Ű����κ����� �Էµ�, ����(stdin)�κ����� �Է��Դϴ�.
//  �����ϰ� ������ ��(EOF)�� �������� �Է��� �����ϴ� ����
//  �����ϴ�.

// - Ű����� ������ ���� �����ϴ� ���
// Linux: Ctrl + D
// Windows: Ctrl + Z

// - �����̷���
// $ ./a.out < a.txt
//   : a.txt�� ��� stdin���� �����ؼ� �����մϴ�.

#if 0
int main(void)
{
    int n;
    int sum = 0;
    int ret;

    while (1) {
        ret = scanf("%d", &n);
        if (ret == -1) {
            break; // ������ ��(EOF)�� �����ߴ�.
        }

        sum += n;
    }

    printf("sum: %d\n", sum);

    return 0;
}
#endif

// $ a.out > b.txt    "w"
//   a. out >> b.txt  "a"

// : b.txt�� stdout���� �����մϴ�.

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
//  - stderr�� ���Ϸ� �����մϴ�.

// $ ./a.out 2>> error.txt
//  - stderr�� ���Ϸ� �����մϴ�.
//  - Append mode

int main(void)
{
    fprintf(stderr, "File open error!\n");

    return 0;
}