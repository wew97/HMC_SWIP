// 13_사용자정의타입5.c
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h>

#if 0
int main(void)
{
    int x[3] = { 10, 20, 30 };
    int y[3];

    // y = x; => 불가능합니다.
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

// 구조체가 포인터 멤버를 가지고 있을 경우,
// 복사를 수행하게 되면, 동일한 자원을 참조합니다.
// 각 메모리를 파괴하게 되면, 이중으로 free가 수행될 가능성이 있고
// 미정의 동작이 발생합니다.
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

// 구조체의 멤버 중 포인터 멤버가 있다면,
// 복사의 방법을 제공해야 합니다.
//  => 깊은 복사
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