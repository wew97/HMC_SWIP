// 12_���ڿ�3.c

#include <stdio.h>
#include <string.h>

// ���ڿ� �񱳸� �����ϱ� ���ؼ���
// ���ڿ� �� �Լ��� ���ؼ� ���ؾ� �մϴ�.
// - int strcmp( const char *lhs, const char *rhs );

// compare / cmp
// => int�� ��ȯ�ϴ� ���
// ���� ���, 0
// lhs�� rhs���� ���� ��� (���������� �տ� ������ ���), ����
// lhs�� rhs���� ū ��� (���������� �ڿ� ������ ���), ���

#if 0
int main(void) {
	printf("%d\n", strcmp("abc", "abc")); // 0
	printf("%d\n", strcmp("abc", "bcd")); // -1
	printf("%d\n", strcmp("bcd", "abc")); // 1

	const char* s1 = "helllo";
	const char* s2 = "world";

	if (strcmp(s1, s2) < 0) {
		printf("s1�� s2���� �۽��ϴ�.\n");
	} else if (strcmp(s1, s2) > 0) {
		printf("s1�� s2���� Ů�ϴ�.\n");
	}

	return 0;
}
#endif

#if 0
int main(void) {
	char* s1 = "hello";
	// char* s2 = "hello";
	char s2[] = "hello";

	// ���ڿ��� �ּҸ� ���ϸ�, ����� ����� ������ �ʽ��ϴ�.
	//if (s1 == s2) {
	if(strcmp(s1, s2) == 0){
		printf("������ ���ڿ��Դϴ�.\n");
	}
	else {
		printf("������ ���ڿ��� �ƴմϴ�.\n");
	}

	return 0;
}
#endif

// ���ڿ��� ���̸� ���ϴ� �Լ�: strlen
// - size_t strlen( const char *str );

size_t xstrlen(const char* str) {
	// �Լ��� ���� �����غ�����!
	int cnt = 0;
	int i = 0;

	while (str[i++] != NULL) {
		cnt++;
	}

	return cnt;
}

int main(void) {
	char str[32] = "hello";

	size_t len = xstrlen(str);
	printf("%zu\n", len);

	return 0;
}