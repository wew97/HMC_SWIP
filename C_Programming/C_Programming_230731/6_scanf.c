// 6_scanf.c

#include <stdio.h>

// ǥ�� ��� �Լ�: printf
// ǥ�� �Է� �Լ�: scanf

#if 0
int main(void) {
	// �Է��� �����ϱ� ���ؼ���,
	// �Է��� ����� �����ϱ� ���� ������ �ʿ�.

	int age;
	scanf_s("%d", &age);
	// ���ǻ���: �Է��� ����� �����ϱ� ���� ������ �ּҸ�
	//			 �����ؾ� �Ѵ�.

	printf("age: %d\n", age);

	return 0;
}
#endif

int main(void) {
	int n1, n2;

	// scanf_s("%d", &n1);
	// scanf_s("%d", &n2);

	scanf_s("%d %d", &n1, &n2);

	printf("n1: %d, n2: %d, result: %d\n", n1, n2, n1 + n2);

	return 0;
}