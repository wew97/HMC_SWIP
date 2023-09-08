// 12_���ڿ�.c
#include <stdio.h>

// 1. C�� ���� Ÿ��
//   char

// 2. �޸𸮿��� ����/�Ǽ��� �����մϴ�.
//    �� ���ڿ� ������ ��ȣ�� �����ϰ�, �� ���� ���� ��ӵ� ���ڸ�
//    ����մϴ�.
//   : ASCII
//  A: 65
//  a: 97
//  0: 48

// 3. �ѱ� ���� ���ڸ� ǥ���ϱ� ���ؼ���
//    ASCII�� ���ؼ��� ǥ���� �Ұ����մϴ�.
//  => �����ڵ�
//      UTF-8 / UTF-16 / UTF-32
//  => MBCS(Multibyte Character Set)
//      euc-kr / CP949
//  : wchar_t

#if 0
int main(void)
{
    // char ch = 65;
    char ch = 'A';

    printf("%c\n", ch);
    printf("%hhd\n", ch);

    return 0;
}
#endif

#if 0
#include <wchar.h>

int main(void)
{
    wchar_t ch = L'��';
    wprintf(L"%lc\n", ch);

    return 0;
}
#endif

// ���ڿ�
//  ����: 0���� ������ char �迭�Դϴ�.
#if 0
int main(void)
{
    char str[6];

    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    // str[5] = 0; /* ���ڿ��� ���� �ǹ��մϴ�. */
    str[5] = '\0'; /* ���ڿ��� ���� �ǹ��մϴ�. */

    printf("%s\n", str);

    return 0;
}
#endif

// - ���ڿ� ���ڿ��� ���̸� �����ؾ� �մϴ�.
// 'A' : [ 65 ]       => char
// "A" : [ 65 ][ 0 ]  => char[2]
#if 0
int main(void)
{
    char str[6] = "hello";
    // char �迭�� ���ڿ��� ���̿� �ι��ڱ��� ���ԵǴ� ũ�⸦
    // ����� Ȯ���ؾ� �մϴ�.

    printf("%zu\n", sizeof("hello"));
    printf("%s\n", str);

    return 0;
}
#endif

// .TEXT ������ ���ڿ��̳� �����ϵ� ���� �ڵ尡 ����˴ϴ�.
// => ���� �Ұ����� �޸�(Read Only)
#if 0
int main(void)
{
    printf("%p\n", "hello");
    printf("%p\n", "hello");

    const char* s = "hello";
    // ���ڿ��� �����͸� ���ؼ� ������ ��,
    // �ݵ�� const char*�� ����ؾ� �մϴ�!

    char str[] = "hello";

    printf("%s\n", s);
    // s[0] = 'X'; /* ������ ���� */
    str[0] = 'X'; /* OK! */

    return 0;
}
#endif

#if 0
int main(void)
{
    const int n = 10; // const int
    const int* p = &n; // const int*

    printf("%d\n", *p);
    // *p = 100; /* ���ü�� ���� ������ �� �����ϴ� */

    int x = 20;
    const int* px = &x; /* OK! */
    // �ǵ�: x�� ���� ������ �޸�����, ������ px�� ���ؼ�
    // ���� �б⸸ �ϰ� �������� �ʰڴ�.

    return 0;
}
#endif

// p -------> [ n ]

// - * ��ȣ�� �տ� const�� ������
//  p -------> n
//           <const>
//  : �����͸� ���ؼ� ���ü�� ���� ������ �� �����ϴ�.

// - * ��ȣ�� �ڿ� const�� ������
//    p -------> n
// <const>
//  : �����͸� �ٸ� �ּҷ� ������ �� �����ϴ�.

int main(void)
{
    int n = 100;

    const int* pn1 = &n;
    int const* pn2 = &n;
    // ���ü�� const �Դϴ�.
    // �����͸� ���ؼ� ���� ������ �� �����ϴ�.

    int* const pn3 = &n;
    // ������ ������ const �Դϴ�.
    // ���ü�� ������ �� ������, �ڱ� �ڽ��� �ٸ� �ּҷ�
    // ������ �� �����ϴ�.

    const int* const pn4 = &n;
    int const* const pn5 = &n;

    return 0;
}