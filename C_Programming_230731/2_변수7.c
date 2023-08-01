// 2_����7.c

#include <stdio.h>

// 1) sizeof
//  : ������ ũ�� �Ǵ� Ÿ���� ũ�⸦ ���� �� ����ϴ� ������
//  => ������ ��� Ÿ���� size_t Ÿ��

// signed char => %hhd
// short	   => %hd
// int		   => %d
// long		   => %ld
// long long   => %lld

// unsigned			  => %u
// unsigned long	  => %lu
// unsigned long long => %llu

// size_t: %zu

// float => %f
// double => %lf
// long double => %Lf

#if 0
int main(void) {
	float f1 = 3.14f;
	double f2 = 3.14;
	long double f3 = 3.14L;

	printf("%f %lf %Lf\n", f1, f2, f3);

	int n = 10;

	printf("%zu\n", sizeof(n)); // sizeof(������)
	printf("%zu\n", sizeof n); // sizeof ������
	printf("%zu\n", sizeof(int)); // sizeof(Ÿ��)

	return 0;
}
#endif

// => 16������ �ϳ��� ������ 4��Ʈ�� ���� ǥ����.
// 0x 12 34 56 78
//	0001 0010 0011 0100 0101 0110 0111 1000

// => 8������ 0�� �տ� ���̴� ���·� ����� �� ����.
// : ����� ���� �ʴ� ���� �����ϴ�.

#if 0
int main(void) {
	int n1 = 0x12345678; // 16����
	int n2 = 0123; // 8���� => ������� �ʴ� ���� ����
	printf("%d\n", n2);

	// ������� ĳ���� ������
	// => Ÿ���� ��ȯ��.
	printf("%hhd\n", (signed char)n1); // 1����Ʈ ����
	printf("%hd\n", (short)n1); // 2����Ʈ ���� 
	printf("%d\n", n1); // 4����Ʈ ����

	return 0;
}
#endif

// * �����Ϸ����� �����Ǵ� ��� Ȯ���ϴ� ���
// godbolt.org(�����Ϸ� �ͽ��÷η�)

// * sizeof
// => ������ Ÿ�ӿ� ����

// * �����Ϸ��� ������ �ð��� ����� �̸� ������ �� ������
// �����Ѵ�!
// => ��� ǥ����

int main(void) {
	int n = sizeof(int);

	return 0;
}