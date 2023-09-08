// 13_���������Ÿ��4.c
#include <stdio.h>

#if 0
struct Complex {
    int real;
    int image;
};

// ����ü�� ��ȯ�� ��, ������ ������尡 �ֽ��ϴ�.

struct Complex Add(const struct Complex* lhs,
    const struct Complex* rhs)
{
    struct Complex result;
    result.real = lhs->real + rhs->real;
    result.image = lhs->image + rhs->image;

    return result;
}

int main(void)
{
    struct Complex c1 = { .real = 2, .image = 3 }; //  2+3i
    struct Complex c2 = { .real = 10, .image = 1 }; // 10+3i

    struct Complex result = Add(&c1, &c2);
    printf("%d + %di\n", result.real, result.image);

    return 0;
}
#endif

#if 0
struct Complex {
    int real;
    int image;
};

// ���� ���� ����(������� �޸�)�� �ּҸ� �Լ��� ���� ��ȯ�ϸ� �ȵ˴ϴ�.
// �ش� �޸��� ������ ������ �����Դϴ�.

struct Complex* Add(const struct Complex* lhs,
    const struct Complex* rhs)
{
    struct Complex result;
    result.real = lhs->real + rhs->real;
    result.image = lhs->image + rhs->image;

    return &result;
}

int* foo(void)
{
    int x[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    return x;
}

int main(void)
{
    int* x = foo();
    for (int i = 0; i < 10; i++) {
        printf("%d\n", x[i]);
    }

    struct Complex c1 = { .real = 2, .image = 3 }; //  2+3i
    struct Complex c2 = { .real = 10, .image = 1 }; // 10+3i

    struct Complex* result = Add(&c1, &c2);
    printf("%d + %di\n", result->real, result->image);

    return 0;
}
#endif

#if 0
struct Complex {
    int real;
    int image;
};

// ��� 1) ���� �޸�(���� ����, ���� ���� ����)
//   => ������ �޸��� �ּҰ� �׻� ��ȯ�˴ϴ�.
//      ���� �޸𸮿� �����ϴ� �Լ��� "������" �Ұ����մϴ�.
//      ���ü� ���α׷��ֿ��� ����ȭ�� �̽��� �߻��մϴ�.
//   : strtok

struct Complex* Add(const struct Complex* lhs,
    const struct Complex* rhs)
{
    static struct Complex result;
    result.real = lhs->real + rhs->real;
    result.image = lhs->image + rhs->image;

    return &result;
}

int* foo(void)
{
    static int x[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    return x;
}

void goo(void)
{
    struct Complex a = { .real = 12, .image = 13 };
    struct Complex b = { .real = 20, .image = 4 };

    struct Complex* r = Add(&a, &b);
    printf("%p\n", r);
    printf("%d + %di\n", r->real, r->image);
}

int main(void)
{
    // int* x = foo();
    // for (int i = 0; i < 10; i++) {
    //     printf("%d\n", x[i]);
    // }

    struct Complex c1 = { .real = 2, .image = 3 }; //  2+3i
    struct Complex c2 = { .real = 10, .image = 1 }; // 10+3i

    struct Complex* result = Add(&c1, &c2);
    printf("%p\n", result);
    goo();

    printf("%d + %di\n", result->real, result->image);

    return 0;
}
#endif

#if 0
#include <stdlib.h> // malloc, free
// ��� 2) ���� �޸� �Ҵ�
//   - �޸� �Ҵ翡 �����Ͽ��� ���, �Լ��� ������ �� �ֽ��ϴ�.
//     �Լ��� ����ϴ� ����ڵ��� �ݵ�� ���� ���ɼ��� ���ؼ� ���� ó���� �ؾ� �մϴ�.
//   - �޸� �Ҵ��� ���� �ּҸ� ��ȯ�ϴ� �Լ��� ����ڴ�
//     �ݵ�� �޸� ������ �ڵ带 �ۼ��ؾ� �մϴ�.
//    : strdup
struct Complex* Add(const struct Complex* lhs,
    const struct Complex* rhs)
{
    struct Complex* result = malloc(sizeof(struct Complex));
    if (result != NULL) {
        result->real = lhs->real + rhs->real;
        result->image = lhs->image + rhs->image;
    }

    return result;
}

void goo(void)
{
    struct Complex a = { .real = 12, .image = 13 };
    struct Complex b = { .real = 20, .image = 4 };

    struct Complex* r = Add(&a, &b);
    if (r != NULL) {
        printf("%p\n", r);
        printf("%d + %di\n", r->real, r->image);

        free(r); // !!!
    }
}

int main(void)
{

    struct Complex c1 = { .real = 2, .image = 3 }; //  2+3i
    struct Complex c2 = { .real = 10, .image = 1 }; // 10+3i

    struct Complex* result = Add(&c1, &c2);
    if (result != NULL) {
        printf("%p\n", result);
        goo();

        printf("%d + %di\n", result->real, result->image);

        free(result); // !!!
    }

    return 0;
}
#endif

// ����
// 1) ����ü�� ������ ��ȯ�ϸ�, ������ ������尡 �ֽ��ϴ�.
// 2) �Լ����� �ּ�(������)�� ��ȯ�ϴ� ���
//   - ���� ������ �ּҸ� ��ȯ�ϸ� ������ �����Դϴ�.
//   - ���� ����(���� ���� ����, ���� ����)�� �ּҸ� ��ȯ�ϸ�
//     �׻� ������ �޸𸮿� ���� �ּҰ� ��ȯ�˴ϴ�.
//      "�������� �Ұ����� �Լ�"
//  - ���� �޸� �Ҵ��� �ּҸ� ��ȯ�ϸ�, �Լ��� ���� ���ɼ��� �ְ�,
//    �޸� ����(free)�� ������ ���, ������ ���輺�� �����մϴ�.

// ���: �Լ����� ����� ��ȯ�� ��,
//      �ּҸ� ��ȯ�ϴ� ���� ������ �ֽ��ϴ�.
//     => �Լ��� ���ڸ� ���ؼ� ����� �����ϴ� ���

struct Complex {
    int real;
    int image;
};

// �ذ� ���
// => Out Parameter
//  ����: �Լ��� ����� ��ȯ���� ���� �����ϴ� ���� �ƴ϶�, �Լ��� ���ڸ� ���� �����մϴ�.
//      - ����� ���� ������ �ּҸ� �����ؾ� �մϴ�.

void Add(
    const struct Complex* lhs,
    const struct Complex* rhs,
    struct Complex* result) /* Out Parameter */
{
    result->real = lhs->real + rhs->real;
    result->image = lhs->image + rhs->image;
}

int main(void)
{
    struct Complex c1 = { .real = 2, .image = 3 }; //  2+3i
    struct Complex c2 = { .real = 10, .image = 1 }; // 10+3i

    struct Complex result;
    Add(&c1, &c2, &result);
    printf("%d + %di\n", result.real, result.image);

    return 0;
}