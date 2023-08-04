// 14_��ó����3.c
#include <stdio.h>

#if 0
// �ɺ��� ���
// 1) const
//  : ��� ǥ������ �ƴմϴ�.

// 2) enum
//  : ���ǥ���� �Դϴ�.
//    ���� ���� ����� ǥ���� �� �ֽ��ϴ�.

// 3) #define
//  : ��� ǥ���� �Դϴ�.
//    ��ó�� ���Ŀ� �ɺ��� ������ ������ϴ�.
//    �����Ϸ��� �ɺ��� ������ �� �� �����ϴ�.

// ��� ǥ�������� ����� �� �ֽ��ϴ�.
#define PI 3.14
#define BUFSIZE 1024

int main(void)
{
    int x[BUFSIZE];

    return 0;
}
#endif

// ��ó����
// 1. �Լ� ȣ���� ������尡 �ֽ��ϴ�.
// 2. �Լ� ȣ���� ������带 �����ϱ� ���ؼ�,
//    ��ũ�� �Լ��� ����Ͽ����ϴ�.

// ���ڸ� ���޹޾� ġȯ�ϴ� ��ũ�θ� "��ũ�� �Լ�"��� �մϴ�.
#if 0
#define SQUARE(x) x* x

int Square(int x) { return x * x; }

int main(void)
{
    int a = 10;
    printf("%d\n", Square(a));
    printf("%d\n", SQUARE(a));

    printf("%d\n", a * a);

    return 0;
}
#endif

// ��ũ�� �Լ��� �߸� ����� ���,
// "�켱����" ������ �߻��մϴ�.
#if 0
int square(int x) { return x * x; }
int dbl(int x) { return x + x; }

// 1) ��ũ���� ������ ġȯ������ ��ȣ�� �����־�� �մϴ�.
// #define SQUARE(x) x * x
// #define SQUARE(x) (x) * (x)
#define SQUARE(x) ((x) * (x))

// 2) ��ũ�� �Լ��� ��ü ġȯ ������ ��ȣ�� �����־�� �մϴ�.
// #define DBL(x) (x) + (x)
#define DBL(x) ((x) + (x))

int main(void)
{
    int x = 10;
    int result = 0;

    result = DBL(x) * DBL(x);
    printf("result: %d\n", result);

    result = dbl(x) * dbl(x);
    printf("result: %d\n", result);

    result = SQUARE(x + x);
    printf("result: %d\n", result);

    result = square(x + x);
    printf("result: %d\n", result);

    return 0;
}
#endif

int square(int x) { return x * x; }
int dbl(int x) { return x + x; }

// ��ũ�� �Լ��� ���ڰ� �ϳ��� �Ŀ��� �ι��̻� ġȯ�Ǵ� ���,
// ++, --�� ������ ���޵� ���, ������ ������ �߻��մϴ�.
// => �ݵ�� ��ũ�� �Լ��� ����� ��, ���ڿ��� ������ �����ϸ� �ȵ˴ϴ�.

#define SQUARE(x) ((x) * (x))
#define DBL(x) ((x) + (x))

int main(void)
{
    int x = 10;
    printf("%d\n", square(++x));

    // printf("%d\n", SQUARE(++x));
    //             (++x) * (++x) /* ������ ���� */

    ++x; // �ݵ�� �и��ؾ� �մϴ�.
    printf("%d\n", SQUARE(x));

    return 0;
}