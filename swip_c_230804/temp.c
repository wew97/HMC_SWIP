#include <stdio.h>

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