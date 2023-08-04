// 14_��ó����2.c
#include <stdio.h>

// 2) #define
//  => ��ũ��
//  => ��ó�� �������� �ؽ�Ʈ�� ġȯ�մϴ�.

// Ȱ�� 1) ��ũ�� ���
// => ����� �̸��� �ο��ؼ� ����� �� �ֽ��ϴ�.
#if 0
#define MY_PROJECT_NAME "Hello World"
#define PI 3.141592

int main(void)
{
    printf("%s\n", MY_PROJECT_NAME);
    printf("%lf\n", PI);

    return 0;
}
#endif

// Ȱ�� 2) ��ũ�θ� �̿��ؼ� ���Ǻ� ������
// #define DEBUG
// gcc 14_��ó����2.c -DDEBUG
// : ������ ����� ���� �����Ͻÿ� ���Ǻ� �������� ����
//   ��ũ�θ� ������ �� �ֽ��ϴ�.

// - #ifdef - #else - #endif
// - #ifndef - #else - #endif
// - #if defined(DEBUG) - #else - #endif
#if 0
int main(void)
{
#ifdef DEBUG
    printf("���α׷� ����..\n");
#else
    printf("DEBUG�� ���ǵǾ� ���� �ʽ��ϴ�.\n");
#endif

#ifndef DEBUG
    printf("DEBUG�� ���ǵǾ� ���� �ʽ��ϴ�.\n");
#else
    printf("���α׷� ����..\n");
#endif

    return 0;
}
#endif

// => include guard
// => ��� ������ �ۼ��� ��, �ߺ� ������ ������ �߻����� �ʵ���
//    ������� �ݵ�� include guard�� �ۼ��ؾ� �մϴ�.
#if 1
#ifndef ADD_H
#define ADD_H

int a;

#endif

#ifndef ADD_H
#define ADD_H
int a;
#endif

int main(void)
{
    return 0;
}
#endif

// �Ʒ� ǥ���� ������ ����Դϴ�.
#if !defined(ADD_H)
#define ADD_H
int a;
#endif

#if !defined(ADD_H)
#define ADD_H
int a;
#endif

#define AAA
#define BBB

int main(void)
{
#if defined(AAA) && defined(BBB)
    printf("AAA�� BBB ��� ���ǵǾ� �ֽ��ϴ�.\n");
#endif

#if defined(AAA) || defined(BBB)
    printf("AAA�� BBB ���� �ϳ��� ���ǵǾ� �ֽ��ϴ�.\n");
#endif

    return 0;
}