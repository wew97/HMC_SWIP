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
    // 1) dest와 src가 동일한 주소인지 확인합니다.
    if (dest == src) {
        return;
    }

    // 2) 이미 할당된 자원이 있다면 해지해야 합니다.
    if (dest->name) {
        free(dest->name);
    }

    // 3) 복사를 수행합니다.
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