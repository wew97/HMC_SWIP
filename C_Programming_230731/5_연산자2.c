// 5_������2.c

#include <stdio.h>

// ������ ����� ��(1)�� ����(0)�� �� ����.

// 1) ==, !=, >, <, >=, <=
//  "�� ǥ����"�� ����� ��(1) �Ǵ� ����(0)

// 2) 0�� �������� �򰡵�.
//   0�� �ƴ� ���� ������ �򰡵�.

#if 0
int main(void) {
	int a = 10;
	int b = 20;

	printf("%d\n", a == b); // ����, 0
	printf("%d\n", a != b); // ��, 1

	int condition = -1;
	if (condition) {
		printf("������ ���Դϴ�.\n");
	}
	else {
		printf("������ �����Դϴ�.\n");
	}

	return 0;
}
#endif

// C�� ��/������ ǥ���ϴ� Ÿ���� ���ԵǾ���.
// C99 ǥ�ؿ� ���Ե�.

#include <stdbool.h>
// typedef _Bool bool;

int main(void) {
	_Bool a = 43;
	bool b = true;
	bool c = false;

	printf("%d\n", a);

	return 0;
}