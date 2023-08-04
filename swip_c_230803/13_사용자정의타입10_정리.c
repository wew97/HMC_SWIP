// 13_���������Ÿ��10.c

#include <stdio.h>

#if 0
typedef struct User {
	char name[32];
	int age;
} USER; // USER == struct User

typedef struct Person {
	char name[32];
	int age;
} PERSON;
// ��������� Ÿ���� ����� �����ϴ���, �±װ� �ٸ��� �ٸ� Ÿ���Դϴ�.

int main(void) {
	USER user = { .name = "Tom", .age = 42 };
	PERSON person = { .name = 'Bob', .age = 100 };

	// user = person;
	// => �ٸ� Ÿ���̱� ������ ������ ������ �߻��մϴ�.

	return 0;
}
#endif

#if 0
typedef struct{
	char name[32];
	int age;
} USER; // USER == struct User

typedef struct{
	char name[32];
	int age;
} PERSON;

// �±װ� ���� ����� ���� Ÿ���� �ٸ� Ÿ���Դϴ�.

int main(void) {
	USER user = { .name = "Tom", .age = 42 };
	PERSON person = { .name = 'Bob', .age = 100 };

	// user = person;
	// => �ٸ� Ÿ���̱� ������ ������ ������ �߻��մϴ�.

	return 0;
}
#endif

// union Ÿ���� ũ��� ������ ���� ū ũ�⸦ ������ ����� ���ؼ� �����˴ϴ�.
typedef union Data {
	int n;
	double d;
} DATA;
// �������� ����� ����� ��ȿ�� �������Դϴ�.

int main(void) {
	printf("%zu\n", sizeof(DATA));
	// union Data data;
	DATA data;
	// union �ʱ�ȭ�� ���� ù��° ����� ���� �ʱ�ȭ�� �մϴ�.
	
	data.n = 100;

	printf("%d\n", data.n);

	printf("%lf\n", data.d);

	return 0;
}