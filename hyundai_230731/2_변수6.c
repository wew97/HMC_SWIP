// 2_����6.c

#include <stdio.h>

#if 0
int main(void) {
	int a = 10;
	int b = 20;

	int c = 10, d = 20;
	// ��ó�� ����ϴ� ���� �����ؾ� �Ѵ�.

	int* pa;
	int* pb;

	//int* pc, pd;
	// pc -> int*
	// pd -> int

	int* pc, * pd;
	// pc -> int*
	// pd -> int*

	printf("%d %d %d %d\n", a, b, c, d);

	return 0;
}
#endif

// 10 -> int
// l, L -> long (�ݵ�� �빮�ڷ� ���)
// ll, LL -> long long (�ݵ�� �빮�ڷ� ���)

// 3.14 -> double
// f, F -> float
// l, L -> long double

int main(void) {
	int n = 10; // ��� ���ͷ�
	long x = 100L;

	long long y = 10000LL;
	
	float f = 3.14f;

	long double ld = 3.14L;

	printf("%ld\n", x);

	return 0;
}