// 7_���2.c
#include <stdio.h>

#if 0
int main(void)
{
    int day;
    printf("day(1-7): ");

    scanf("%d", &day);

    // �Ʒ��� ���´� switch ���� ����ϸ�
    // ���մϴ�.
    if (day == 1) {
        printf("��\n");
    }
    else if (day == 2) {
        printf("ȭ\n");
    }
    else if (day == 3) {
        printf("��\n");
    }
    else if (day == 4) {
        printf("��\n");
    }
    else if (day == 5) {
        printf("��\n");
    }
    else if (day == 6) {
        printf("��\n");
    }
    else if (day == 7) {
        printf("��\n");
    }
    else {
        printf("�߸��� �Է��Դϴ�.\n");
    }

    return 0;
}
#endif

int main(void)
{
    int day;
    printf("day(1-7): ");

    scanf("%d", &day);

    // 1. break�� ����ؾ� �մϴ�.
    // 2. default
    //  => ���� ��ġ���� �ʴ� ��츦 ó���� �� �ֽ��ϴ�.
    //  => else�� ���Ұ� �����մϴ�.

    switch (day) {
    case 1:
        printf("��\n");
        break;
    case 2:
        printf("ȭ\n");
        break;
    case 3:
        printf("��\n");
        break;
    case 4:
        printf("��\n");
        break;
    case 5:
        printf("��\n");
        break;
    case 6:
        printf("��\n");
        break;
    case 7:
        printf("��\n");
        break;

    default:
        printf("�߸��� �Է��Դϴ�.\n");
        break; // �ϰ��� �ְ� break�� �ۼ��ϴ� ���� �����ϴ�.
    }

    return 0;
}