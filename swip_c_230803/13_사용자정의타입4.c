// 13_사용자정의타입4.c
#include <stdio.h>

#if 0
struct Complex {
    int real;
    int image;
};

// 구조체를 반환할 때, 복사의 오버헤드가 있습니다.

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

// 절대 지역 변수(사라지는 메모리)의 주소를 함수를 통해 반환하면 안됩니다.
// 해당 메모리의 접근은 미정의 동작입니다.

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

// 방법 1) 정적 메모리(전역 변수, 정적 지역 변수)
//   => 동일한 메모리의 주소가 항상 반환됩니다.
//      정적 메모리에 의존하는 함수는 "재진입" 불가능합니다.
//      동시성 프로그래밍에서 동기화의 이슈가 발생합니다.
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
// 방법 2) 동적 메모리 할당
//   - 메모리 할당에 실패하였을 경우, 함수가 실패할 수 있습니다.
//     함수를 사용하는 사용자들은 반드시 실패 가능성에 대해서 오류 처리를 해야 합니다.
//   - 메모리 할당을 통해 주소를 반환하는 함수의 사용자는
//     반드시 메모리 해지의 코드를 작성해야 합니다.
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

// 정리
// 1) 구조체를 값으로 반환하면, 복사의 오버헤드가 있습니다.
// 2) 함수에서 주소(포인터)를 반환하는 방법
//   - 지역 변수의 주소를 반환하면 미정의 동작입니다.
//   - 정적 변수(정적 지역 변수, 전역 변수)의 주소를 반환하면
//     항상 동일한 메모리에 대한 주소가 반환됩니다.
//      "재진입이 불가능한 함수"
//  - 동적 메모리 할당의 주소를 반환하면, 함수가 실패 가능성이 있고,
//    메모리 해지(free)를 누락된 경우, 누수의 위험성이 존재합니다.

// 결론: 함수에서 결과를 반환할 때,
//      주소를 반환하는 것은 문제가 있습니다.
//     => 함수의 인자를 통해서 결과를 전달하는 방법

struct Complex {
    int real;
    int image;
};

// 해결 방법
// => Out Parameter
//  정의: 함수의 결과를 반환값을 통해 전달하는 것이 아니라, 함수의 인자를 통해 전달합니다.
//      - 결과를 받을 변수의 주소를 전달해야 합니다.

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