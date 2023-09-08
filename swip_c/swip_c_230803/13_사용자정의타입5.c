// 13_���������Ÿ��5.c
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h>

#if 0
int main(void)
{
    int x[3] = { 10, 20, 30 };
    int y[3];

    // y = x; => �Ұ����մϴ�.
    for (int i = 0; i < 3; i++) {
        y[i] = x[i];
    }

    return 0;
}
#endif

#if 0
int main(void)
{
    int a = 10;
    int b;

    b = a;
    printf("%d\n", b);

    return 0;
}
#endif

#if 0
struct User {
    char name[32];
    int age;
};

int main(void)
{
    struct User user1 = { .name = "Tom", .age = 42 };
    struct User user2;

    user2 = user1;

    printf("%s(%d)\n", user2.name, user2.age);

    return 0;
}
#endif

// ����ü�� ������ ����� ������ ���� ���,
// ���縦 �����ϰ� �Ǹ�, ������ �ڿ��� �����մϴ�.
// �� �޸𸮸� �ı��ϰ� �Ǹ�, �������� free�� ����� ���ɼ��� �ְ�
// ������ ������ �߻��մϴ�.
#if 0
struct User {
    char* name;
    int age;
};

void InitUser(struct User* user, const char* name, int age)
{
    user->name = malloc(strlen(name) + 1);
    strcpy(user->name, name);

    user->age = age;
}

void DelUser(struct User* user)
{
    free(user->name);
    user->name = NULL;

    user->age = 0;
}

int main(void)
{
    struct User user;
    InitUser(&user, "Tom", 42);

    struct User other;
    other = user;

    DelUser(&user);
    DelUser(&other);

    return 0;
}
#endif

// ����ü�� ��� �� ������ ����� �ִٸ�,
// ������ ����� �����ؾ� �մϴ�.
//  => ���� ����
#if 0
struct User {
    char* name;
    int age;
};

void InitUser(struct User* user, const char* name, int age)
{
    user->name = malloc(strlen(name) + 1);
    strcpy(user->name, name);

    user->age = age;
}

void CopyUser(struct User* dest, const struct User* src)
{
    dest->name = malloc(strlen(src->name) + 1);
    strcpy(dest->name, src->name);

    dest->age = src->age;
}

void DelUser(struct User* user)
{
    free(user->name);
    user->name = NULL;

    user->age = 0;
}

int main(void)
{
    struct User user;
    InitUser(&user, "Tom", 42);

    struct User other;
    // other = user;
    CopyUser(&other, &user);

    DelUser(&user);
    DelUser(&other);

    return 0;
}
#endif

struct User {
    char* name;
    int age;
};

void InitUser(struct User* user, const char* name, int age)
{
    user->name = malloc(strlen(name) + 1);
    strcpy(user->name, name);

    user->age = age;
}

void CopyUser(struct User* dest, const struct User* src)
{
    // 1) dest�� src�� ������ �ּ����� Ȯ���մϴ�.
    if (dest == src) {
        return;
    }

    // 2) �̹� �Ҵ�� �ڿ��� �ִٸ� �����ؾ� �մϴ�.
    if (dest->name) {
        free(dest->name);
    }

    // 3) ���縦 �����մϴ�.
    dest->name = malloc(strlen(src->name) + 1);
    strcpy(dest->name, src->name);

    dest->age = src->age;
}

void DelUser(struct User* user)
{
    free(user->name);
    user->name = NULL;

    user->age = 0;
}

int main(void)
{
    struct User user;
    InitUser(&user, "Tom", 42);

    struct User other;
    InitUser(&other, "Bob", 36);

    // other = user;
    CopyUser(&user, &user);

    DelUser(&user);
    DelUser(&other);

    return 0;
}