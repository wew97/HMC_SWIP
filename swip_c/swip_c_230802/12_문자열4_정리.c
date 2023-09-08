// 12_���ڿ�4.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. �ι���('\0')�� ����Ǵ� char �迭�� ���ڿ��Դϴ�.
// 2. ���ڿ��� ������ �����ϱ� ���ؼ���,
//    string.h�� ���ؼ� �����Ǵ� �Լ��� ����ؾ� �մϴ�.
//  - ���ڿ� ����: strlen
//  size_t strlen(const char *s);

//  - ���ڿ� ����: strcpy
//  char* strcpy(char* dest, const char* src);

//  - ���ڿ� ����: strcat
//  char* strcat(char* dest, const char* src);

//  - ���ڿ� ��
//  int strcmp(const char* lhs, const char* rhs);
//   lhs < rhs: ����
//   lhs > rhs: ���
//  lhs == rhs: 0

// 3. ���ڿ� ������ ����� ��,
//    ��ȿ�� �޸� ������ ���ؼ� ������ ����Ǵ��� �����ؾ� �մϴ�.
#if 0
int main(void)
{
    char str[32] = "hello";
    const char* s = "hello";

    return 0;
}
#endif
// 4. char *strtok(char* str, const char* sep);
//   : ���� �޸�(���� ����, ���� ���� ����)�� �ּҰ� ��ȯ�˴ϴ�.
//    char *strdup(const char *s1);
//   : ���� �޸� �Ҵ��� �ּҸ� ��ȯ�մϴ�.

#if 0
int main(void)
{
    char str[32] = "hello,world,show,me,the,money"; // CSV

    char* p = NULL; // �����ʹ� ������� ���� ��, �׻� NULL�� �ʱ�ȭ�ؾ� �մϴ�.

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

    char* p = NULL; // �����ʹ� ������� ���� ��, �׻� NULL�� �ʱ�ȭ�ؾ� �մϴ�.

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

// �������� C ���̺귯���� �������� �Ұ����� �Լ��� ���ؼ�
// ������ ������ ������ ������ �������ݴϴ�.
//  ex) strtok_r
//   - ǥ���� �ƴմϴ�.
//   char *strtok_r(char *str, const char *sep, char ** lasts);

int main(void)
{
    char str[32] = "hello,world,show,me,the,money"; // CSV

    char* p = NULL; // �����ʹ� ������� ���� ��, �׻� NULL�� �ʱ�ȭ�ؾ� �մϴ�.
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
//   : ���� �޸� �Ҵ��� �ּҸ� ��ȯ�մϴ�.

// ����ڷκ��� ���ڿ�(CSV)�� �Է� �޾Ƽ�,
// �Ľ��ϴ� ���α׷��� �ۼ��غ��ô�.

// 6. fgets �Լ��� �̿��ؼ�, �Է��� �޴� ���� �����մϴ�.

int main(void) {
    // int n;
    // scanf("%d", &n);

    // ���ڿ��� �Է� ���� ��, scanf�� �����մϴ�.
    // : Buffer Overflow ������ ���輺�� �ֽ��ϴ�.
    
    char buf[64];
    // scanf("%s", buf);
    fgets(buf, sizeof(buf), stdin); // 64B�� �Ѿ�� �Է��ص� 64B������

    printf("%s\n", buf);

    // ���� �޸� �Ҵ��� ���ؼ� ���纻�� �����մϴ�.
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
    
    free(src); // strdup ���ķ� free �ʼ�!

    return 0;
}