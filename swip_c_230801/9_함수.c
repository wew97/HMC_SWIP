// 9_�Լ�.c
#include <stdio.h>

// * �ڵ带 �ߺ��ؼ�, ���������� ����� ���
//   �䱸������ �����̳� �߰��� ���ؼ� �ڵ��� ������ ����������
//   �̷������ �մϴ�.
//   => �������� ����� ����!
//   * SRP(Single Reponsibility Principle)
//   : ���� å���� ��Ģ
//   - �� �ϳ��� å���� ������ �Ѵ�.
//   * DRY(Don't Repeat Yourself)
#if 0
int main(void)
{
    printf("[�޴�]\n");
    printf("1. ¥���\n");
    printf("2. «��\n");
    printf("3. ���\n");
    printf("4. Į����\n");

    printf("[�޴�]\n");
    printf("1. ¥���\n");
    printf("2. «��\n");
    printf("3. ���\n");
    printf("4. Į����\n");

    printf("[�޴�]\n");
    printf("1. ¥���\n");
    printf("2. «��\n");
    printf("3. ���\n");
    printf("4. Į����\n");

    return 0;
}
#endif

// �Լ�: �Է��� �޾Ƽ�, �־��� ������ ������ �� ����� ��ȯ�ϴ�
//      �ڵ��� ����
// C���� �Լ��� ����� ���
// �Լ���_���_Ÿ�� �Լ���_�̸�(�Լ��� �Է� ...)

// ���: void
// �Է�: void
// �̸�: PrintMenu
#if 0
void PrintMenu(void)
{
    printf("[�޴�]\n");
    printf("1. ¥���\n");
    printf("2. «��\n");
    printf("3. ���\n");
}

int main(void)
{
    PrintMenu();

    PrintMenu();

    PrintMenu();
}
#endif

// �Լ��� ��� Ÿ��: int
// �Լ��� �Է�: int a, int b
// �Լ��� �̸�: Add
#if 0
int Add(int a, int b) { return a + b; }
// �Լ��� ����� return�� ���ؼ� �����մϴ�.

// int Add(int a, int b) { } /* ������ ���� */

int main(void)
{
    int result;

    result = Add(10, 20);
    //      -------------
    //          30

    printf("result: %d\n", result);

    return 0;
}
#endif

// �Է¹��� N(���)������ ���� ����ϴ� �Լ��� �����ô�.
#if 0
void PrintSum(int n)
{
    // Early exit
    // => MISRA������ ������� �ʽ��ϴ�.
    if (n <= 0) {
        return;
        // void�� ��ȯ�ϴ� �Լ�(��ȯ���� ���� �Լ�)������
        // return�� ���� �Լ��� ��������� ������ �� �ֽ��ϴ�.
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum: %d\n", sum);
}
#endif

// MISRA C++ / AutoSAR => MISRA C++ 202x

// �Լ��� ���� ���� ������ ������ ������ �մϴ� => MISRA C 2023
void PrintSum(int n)
{
    if (n > 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        printf("Sum: %d\n", sum);
    }
}

int main(void)
{

    return 0;
}