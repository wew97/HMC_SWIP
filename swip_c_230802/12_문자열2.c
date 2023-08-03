// 12_���ڿ�2.c

#include <stdio.h>

#if 0
// C�� ���ڿ�
// : char �迭�ε� ������ ���ڰ� '\0'(null����, 0)�Դϴ�.

int main(void) {
	char str[] = "hello"; // char[6]
	printf("%zu\n", sizeof(str));

	char str2[32] = "hello"; // char[32]
	printf("%zu\n", sizeof(str2));

	return 0;
}
#endif

// const�� *�� �տ� ����Ǿ���.
// - const char* s = "hello";
// - char const* s = "hello";

// s ----------> "hello"
//               <const>
// > �����͸� ���ؼ� �����ϴ� ���ü�� �޸𸮸� �б⸸ �ϰ�,
//   ������ �� �����ϴ�.

// const�� *�� �ڿ� ����Ǿ���.
// char* const s = "hello";
// s ----------> "hello"
// <const>
// > �����͸� ���ؼ� �����ϴ� ���ü�� �аų� ������ �� ������,
//   ������ ������ �ٸ� �ּҷ� ������ �� �����ϴ�.

#if 0
int main(void) {
	char str[32] = "hello";
	char* s = "hello";

	str[0] = 'X';
	printf("%s\n", str);

	// s[0] = 'X'; /* ������ ���� */

	return 0;
}
#endif

