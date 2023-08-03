// 13_���������Ÿ��.c

#include <stdio.h>

// C��� Ÿ��
// - Built-in Type (���� Ÿ��)
// ����Ÿ��: char
// ����Ÿ��: signed char / unsigned char
//			short       / unsigned short
//			int         / unsigned int
//			long        / unsigned long
//			long long   / unsigned long long
// �Ǽ�Ÿ��: float / double / long double

// - User Defined Type (����� ���� Ÿ��)
// 1) struct
// 2) union
// 3) enum

#if 0
// * ���Ҽ��� ������ �����ϴ� ���α׷��� �����ô�.
//    1 + 2i
//   10 + 3i
// + --------
//   11 + 5i

void Add(int ar, int ai, int br, int bi) {
	int rr, ri;
	rr = ar + br;
	ri = ai + bi;
}

int main(void) {
	int ar = 1, ai = 2;  // 1 + 2i
	int br = 10, bi = 3; // 10 + 3i

	return 0;
}
#endif

#if 0
// �ٽ�: ���Ҽ� Ÿ���� ���� �����մϴ�.
struct Complex {
	// ��� ������ ����
	int real;  // �Ǽ���
	int image; // �����
};

struct Complex Add(struct Complex a, struct Complex b) {
	struct Complex result;
	result.real = a.real + b.real;
	result.image = a.image + b.image;

	return result;
}

int main(void) {
	struct Complex a; //  1 + 2i
	struct Complex b; // 10 + 3i 

	a.real = 1; // ��� ���� ������
	a.image = 2;

	b.real = 10;
	b.image = 3;

	struct Complex result = Add(a, b);
	printf("%d + %di\n", result.real, result.image);

	return 0;
}
#endif