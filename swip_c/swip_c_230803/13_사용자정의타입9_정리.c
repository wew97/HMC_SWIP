// 13_���������Ÿ��9_����.c

#include <stdio.h>

// ����� ���� Ÿ��
// 1) struct(����ü)
// 2) union (����ü)
// 3) enum  (����ü)

#if 0
// Ÿ���� �����ؼ�, ���ο� Ÿ���� ���� �� �ֽ��ϴ�.
struct Complex {
	// ��� ������ ����
	int real;
	int image;
};

void PrintComplex(struct Complex complex) {
	printf("%d + %di\n", complex.real, complex.image);
}

int main(void) {
	struct Complex c1 = { .real = 0, .image = 0 };
	struct Complex c2 = { .real = 10, .image = 3 };

	PrintComplex(c1);
	PrintComplex(c2);

	return 0;
}
#endif

const struct Complex {
	// ��� ������ ����
	int real;
	int image;
};

void PrintComplex(const struct Complex complex) {
	printf("%d + %di\n", complex.real, complex.image);
}

int main(void) {
	struct Complex c1 = { .real = 0, .image = 0 };
	struct Complex c2 = { .real = 10, .image = 3 };

	PrintComplex(c1);
	PrintComplex(c2);

	return 0;
}