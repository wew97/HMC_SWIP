// 13_���������Ÿ��8.c
#include <stdio.h>

// 1. struct
// 2. union
// 3. enum(����ü)

#if 0
enum ProcessState {
    TASK_RUNNING = 100,
    TASK_STOPPED = 200,
    TASK_WAITING = 300
    // ���� ���
};

enum {
    ARRAY_SIZE = 10 // ��� - ������ Ÿ�� ���
};

const int array_size = 10; // ���
// C ������ const ����� ��Ÿ�� ����̱� �� ����,
// ��� ǥ�������� ����� �� �����ϴ�.

// C ������ ���� ������ ���� ���� ������ �ʱ�ȭ����
// ��� ǥ������ �ʿ��մϴ�.

int main(void)
{
    // int arr[array_size]; => ������ ����!
    int arr[ARRAY_SIZE];

    int task_state = TASK_RUNNING;

    return 0;
}
#endif

// �ɺ��� ���
// => ����� �̸��� �ο��ϴ� ����
// 1) const
//  : �پ��� Ÿ�Կ� ���ؼ� ����� ������ �� ������,
//    ��Ÿ�� ����̱� ������, ��� ǥ���Ŀ����� ����� �Ұ����մϴ�.

// 2) enum
//  : ������ Ÿ�� ����̱� ������, ��� ǥ���Ŀ��� ����� �� �ֽ��ϴ�.
//    ���� ����� ����� �����մϴ�.

// 3) ��ũ��

// �Ѱ���: ���� ����� ���� �� �ֽ��ϴ�.
enum State {
    STATE_A = 100,
    STATE_B,
    STATE_C
}; // �ڵ����� 1�� ����

int main(void)
{
    printf("%d\n", STATE_A); // 100
    printf("%d\n", STATE_B); // 101
    printf("%d\n", STATE_C); // 102

    return 0;
}