// 14_��ó����3.c

#include <stdio.h>

#if 0
// �ɺ��� ���
// 1) const
//   : ��� ǥ������ �ƴմϴ�.

// 2) enum
//   : ���� ���� ����� ǥ���� �� �ֽ��ϴ�.

// 3) #define
//   : ��� ǥ���� �Դϴ�.
//     ��ó�� ���Ŀ� �ɺ��� ������ ������ϴ�.
//     �����Ϸ��� �ɺ��� ������ �� �� �����ϴ�.

// ��� ǥ�������� ����� �� �ֽ��ϴ�.
#define PI 3.14
#define BUFSIZE 1024

int main(void) {
	int x[BUFSIZE];

	return 0;
}
#endif

// ��ó����
int Square(int x) {
	return x * x;
}

int main(void) {
	int x = 10;

	printf("%d\n", Square(10));

	printf("%d\n", x * x);

	return 0;
}