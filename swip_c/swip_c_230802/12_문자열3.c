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

#if 0
size_t xstrlen(const char* str) { // while�� ���
	// �Լ��� ���� �����غ�����!
	size_t i = 0;
	while (str[i++] != NULL) {}
	return --i;
}
#endif

#if 0
size_t xstrlen(const char* str) { // for�� ���
	size_t cnt = 0;
	for (cnt; str[cnt] != NULL; cnt++);
	
	return cnt;
}
#endif

#if 0
size_t xstrlen(const char* str) { // while�� + const ���
	const char* p = str;
	while (*p) {
		p++;
	}

	return p - str;
}

int main(void) {
	char str[32] = "hello";

	size_t len = xstrlen(str);
	printf("%zu\n", len);

	return 0;
}
#endif

#if 0
// ���ڿ� ����: strcpy
// - char *strcpy( char *dest, const char *src );
//  : src�� ���ڿ��� dest�� ����� �� �ִ� ����� �޸𸮰� Ȯ���Ǿ� �־�� �մϴ�.
//   => �߸��� ��� ������ ������ �߻��մϴ�.

// b = a;
int main(void) {
	char src[32] = "hello";
	char dst[6];

	// strcpy
	strcpy(dst, src);
	printf("%s\n", dst);

	return 0;
}
#endif

// ���ڿ� ����: strcat
// - char *strcat( char *dest, const char *src );
//  : dest�� ���� �޸� ������ src�� ������ �� ���� ������ �Ǿ�� �մϴ�.
//  => �߸��� ��� ������ ������ ���輺�� �ֽ��ϴ�.

#if 1
int main(void) {
	char src[32] = "hello";
	char dest[32];

	strcpy(dest, src);

	strcat(dest, "world");
	printf("dest: %s\n", dest);

	return 0;
}
#endif