// 2_����4.c

#include <stdio.h>
#include <math.h>

// �Ǽ� Ÿ�� / �ε� �Ҽ��� Ÿ��
// => ���꿡 ������ �߻�.
// - float
// - double
// - long double

int main(void) {
	double a = 0.7;
	double b = 0.1 * 7;

	printf("%lf\n", a);
	printf("%lf\n", b);

	if (fabs(a - b) < 0.0000001) {
		printf("���� ��\n");
	}
	else {
		printf("�ٸ� ��\n");
	}

	if (a == b) {
		printf("���� ��\n");
	}
	else {
		printf("�ٸ� ��\n");
	}

	return 0;
}

// �������� float, double�� ���ؼ�
// typedef�� ���� ũ�⸦ ����ϴ� ���·� ����ϴ� ��찡 ����.
/*
typedef float float32_t;
typedef double float64_t;
*/