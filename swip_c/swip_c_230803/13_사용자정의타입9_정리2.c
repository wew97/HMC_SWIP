// 13_���������Ÿ��10.c
#include <stdio.h>

#if 0
typedef struct User {
    char name[32];
    int age;
} USER; // USER == struct User

typedef struct Person {
    char name[32];
    int age;
} PERSON;
// ��������� Ÿ���� ����� �����ϴ���, �±װ� �ٸ��� �ٸ� Ÿ���Դϴ�.

int main(void)
{
    USER user = { .name = "Tom", .age = 42 };
    PERSON person = { .name = "Bob", .age = 100 };

    // user = person;
    // => �ٸ� Ÿ���̱� ������ ������ ������ �߻��մϴ�.

    return 0;
}
#endif

#if 0
typedef struct {
    char name[32];
    int age;
} USER;

typedef struct {
    char name[32];
    int age;
} PERSON;
// �±װ� ���� ����� ���� Ÿ���� �ٸ� Ÿ���Դϴ�.

int main(void)
{
    USER user = { .name = "Tom", .age = 42 };
    PERSON person = { .name = "Bob", .age = 100 };

    // user = person;

    return 0;
}
#endif

#if 0
// union Ÿ���� ũ��� ������ ���� ū ũ�⸦ ������ ����� ���ؼ� �����˴ϴ�.
typedef union Data {
    int n;
    double d;
} DATA;
// �������� ����� ����� ��ȿ�� �������Դϴ�.

int main(void)
{
    printf("%zu\n", sizeof(union Data));
    // union Data data;
    // DATA data = { .n = 42 }; // OK
    // DATA data = { .n = 42, .d = 3.14 }; // ������ ����
    DATA data = { .d = 3.14 }; // OK

    // - union �ʱ�ȭ�� ���� ù��° ����� ���� �ʱ�ȭ�� �մϴ�.
    DATA data2 = { 42 };

    // - ��� ������ �ʱ�ȭ�� ����� ���, �ϳ��� ����� ���� �ʱ�ȭ�� ���˴ϴ�.

    data.n = 100;
    printf("%d\n", data.n);

    printf("%lf\n", data.d);

    return 0;
}
#endif

// ����ü�� ������ ����� ������ �� �ֽ��ϴ�.
// NO => 0
// OK => 1

#if 0
enum State {
    NO,
    OK
};

enum TaskState {
    STOPPED,
    RUNNING
};

int main(void)
{
    // int state = OK; // OK!
    enum State state = OK; // OK! => ����˴ϴ�.
    printf("%d\n", state);

    state = NO;
    printf("%d\n", state);

    state = STOPPED;
    // �ٸ� Ÿ���� ���� ����� �����ϴ� ���� ������ ��� ���ؼ�
    // Ȯ���� �� �ֽ��ϴ�.

    return 0;
}
#endif

#if 0
// ���� ����� �ٸ� Ÿ���̾ �����ؾ� �մϴ�.
// ���� ����� ������ ��, ���ξ ���ؼ� �̸� �浹�� �����ؾ� �մϴ�.
#include <limits.h>
// INT_MAX

enum State {
    STATE_OK,
    STATE_NO
};

enum TaskState {
    TASK_STATE_OK = INT_MAX,
    // ����(int) Ÿ�Կ��� �����÷ο��� ������ �߻����� �ʾƾ� �մϴ�.
    TASK_STATE_NO
};

int main(void)
{
    printf("%zu\n", sizeof(enum State));
    printf("%zu\n", sizeof(enum TaskState));

    return 0;
}
#endif