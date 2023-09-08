// 10_������2.c

#include <stdio.h>

#if 0
// �ٽ�: �ٸ� �Լ����� �ٸ� �Լ��� ������ ���� �����ϴ� ����
//	     �Ϲ������� �Ұ����մϴ�.

void Inc(int x) {
	++x;
}

int main(void) {
	int x = 10;
	Inc(x); // Call by Value
	// 1) �Լ��� ���ڴ� ������ ����Ǿ� ���޵˴ϴ�.
	// 2) �Լ��� ���� ���� ���ڴ� ���� ������ ������ ������ �����ϴ�.

	printf("%d\n", x);

	return 0;
}
#endif

void Inc(int* px) {
	++(*px);
}

int main(void) {
	int x = 10;
	Inc(&x); // Call by Reference
	// �ּҸ� �����ؼ�, ������ ������ ���� ������ ���� �аų� ������ �� �ֽ��ϴ�.

	printf("%d\n", x);

	return 0;
}