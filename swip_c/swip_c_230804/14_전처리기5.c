// 14_��ó����5.c
#include <stdio.h>

// C/C++ ���� �̸� ���ǵǾ� �ִ� ��ũ�ΰ� �ֽ��ϴ�.
// 1) __FILE__: �������� �ҽ� �ڵ��� ���ϸ�
// 2) __LINE__: ���� �ҽ� �ڵ��� ������ġ
// 3) __STDC_VERSION__: ���� �����ϵǴ� C ǥ�� ����(long)

#if 0
void LOG(const char* message)
{
    printf("%s:%d> %s\n", __FILE__, __LINE__, message);
}
#endif
// __LINE__ ������ �̿��ϴ� �Լ��� ����� ���ؼ���,
// ��ũ�� �Լ��� �����ؾ� �մϴ�.
// #define DEBUG

#ifdef DEBUG
#define LOG(message) \
    printf("%s:%d> %s\n", __FILE__, __LINE__, message)
#else
#define LOG(message) (void)0
// (void)�� ĳ�����ϸ�, ���� �ڵ尡 ��������� �ʽ��ϴ�.
// (void)0�� �ǹ̴� ���� �ݷ��� ���ؼ� ����մϴ�. NO-OP
#endif

int main(void)
{
    LOG("hello");
    LOG("bye");

    printf("%ld\n", __STDC_VERSION__);
    // 201112 => C11
    // 199901 => C99

#if __STDC_VERSION__ == 199901L
    printf("C99 ǥ���Դϴ�.\n");
#elif __STDC_VERSION__ == 201112L
    printf("C11 ǥ���Դϴ�.\n");
#endif

    return 0;
}