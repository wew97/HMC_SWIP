// 5_������3.c

#include <stdio.h>

// && => �� AND ������
// || => �� OR ������
//    : ���� ȸ�� ����

// (cond1) && (cond2)
// : cond1�� cond2�� ��� ���̾�� ����� ��
// (cond1) || (cond2)
// : cond1 �Ǵ� cond2 �� �� �ϳ��� ���̾ ����� ��

#if 0
int main(void) {
	int a = 0;
	int b = 0;
	int result = 0;

	result = a++ && ++b;
	printf("%d %d %d\n", a, b, result);
	// 1 0 0 => a++�� ++�� �Ǳ����� ������ �Ǵ� -> ���� -> �� �ڷδ� ���� ����

	a = b = result = 0;
	result = --a || ++b;
	printf("%d %d %d\n", a, b, result);
	// -1 0 1

	return 0;
}
#endif

// �� ������ &&
// �� ������ ||
//  ���� �����ڸ� �Բ� ����ϴ� ���,
//  �켱������ �ٸ� ������ ����.
// => ��������� ��ȣ�� �ݵ�� ����ؾ� ��.

int main(void) {
	int a;
	int b;
	int c;
	int result;

	a = b = c = result = 0;


	result = ++a || b++ && ++c;
	printf("%d %d %d %d\n", a, b, c, result);

	a = b = c = result = 0;
	result = ++a && ++b || c++;
	printf("%d %d %d %d\n", a, b, c, result);

	int d = 0;
	a = b = c = result = 0;
	result = ++a || b++ && c++ || ++d;

	// result = (++a || (b++ && c++)) || ++d;

	return 0;
}