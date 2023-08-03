// 13_���������Ÿ��3.c

#include <stdio.h>

#if 0
struct Point {
	int x;
	int y;
};

int main(void) {
	struct Point pt; // �������� �̹Ƿ� �����Ⱚ�� �����ϴ�.

	// struct Point pt = { 10, 20 };
	// ����� �ʱⰪ�� ���������� �̴ϼȶ������� ���� �����մϴ�.

	// struct Point pt = { 10, }; // x = 10, y = 0
	// ���������� �ʱ�ȭ�ǰ�, �������� ���� ��� 0���� �ʱ�ȭ�˴ϴ�.

	// struct Point pt = { 0, 10 };

	// C99 ǥ�ؿ��� ����ü�� �ʱ�ȭ�ϴ� ���ο� ����� ���ԵǾ����ϴ�.
	// => ��� ������ �ʱ�ȭ
	struct Point pt = { .x = 10, .y = 20 };

	printf("%d, %d\n", pt.x, pt.y);

	return 0;
}
#endif

#if 0
struct User {
	char name[32];
	int age;
};

void PrintUser(struct User user) {
	printf("%s (%d)\n", user.name, user.age);
	user.age = 100;
}

// �Լ����� ����ü(����� ���� Ÿ��)�� ���ڷ� �����ϸ�,
// ������ �����ؼ� �����մϴ�.
// => ����ü�� �Լ��� ������ ��, ������ �����ϴ� ����
//    ������ ����� �߻��մϴ�.

int main(void) {
	struct User user = { .name = "Tom", .age = 42 };
	
	PrintUser(user);

	PrintUser(user);

	return 0;
}
#endif

#if 1
struct User {
	char name[32];
	int age;
};

// .  (��� ���� ������)
// -> (������ ��� ���� ������)

void PrintUser(const struct User *user) { // �����Ͱ� ������� �ʰ� �ϱ� ���ؼ� const
	//printf("%s (%d)\n", (*user).name, (*user).age);
	printf("%s (%d)\n", user->name, user->age);
}

int main(void) {
	struct User user = { .name = "Tom", .age = 42 };

	PrintUser(&user);

	return 0;
}
#endif