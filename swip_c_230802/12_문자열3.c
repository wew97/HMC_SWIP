// 12_문자열3.c

#include <stdio.h>
#include <string.h>

// 문자열 비교를 수행하기 위해서는
// 문자열 비교 함수를 통해서 비교해야 합니다.
// - int strcmp( const char *lhs, const char *rhs );

// compare / cmp
// => int를 반환하는 경우
// 같을 경우, 0
// lhs가 rhs보다 작을 경우 (사전적으로 앞에 존재할 경우), 음수
// lhs가 rhs보다 큰 경우 (사전적으로 뒤에 존재할 경우), 양수

#if 0
int main(void) {
	printf("%d\n", strcmp("abc", "abc")); // 0
	printf("%d\n", strcmp("abc", "bcd")); // -1
	printf("%d\n", strcmp("bcd", "abc")); // 1

	const char* s1 = "helllo";
	const char* s2 = "world";

	if (strcmp(s1, s2) < 0) {
		printf("s1이 s2보다 작습니다.\n");
	} else if (strcmp(s1, s2) > 0) {
		printf("s1이 s2보다 큽니다.\n");
	}

	return 0;
}
#endif

#if 0
int main(void) {
	char* s1 = "hello";
	// char* s2 = "hello";
	char s2[] = "hello";

	// 문자열의 주소를 비교하면, 결과가 제대로 나오지 않습니다.
	//if (s1 == s2) {
	if(strcmp(s1, s2) == 0){
		printf("동일한 문자열입니다.\n");
	}
	else {
		printf("동일한 문자열이 아닙니다.\n");
	}

	return 0;
}
#endif

// 문자열의 길이를 구하는 함수: strlen
// - size_t strlen( const char *str );

#if 0
size_t xstrlen(const char* str) { // while문 사용
	// 함수를 직접 구현해보세요!
	size_t i = 0;
	while (str[i++] != NULL) {}
	return --i;
}
#endif

#if 1
size_t xstrlen(const char* str) { // for문 사용
	size_t cnt = 0;
	for (cnt; str[cnt] != NULL; cnt++);
	
	return cnt;
}
#endif

#if 0
size_t xstrlen(const char* str) { // while문 + const 사용
	const char* p = str;
	while (*p) {
		p++;
	}

	return p - str;
}
#endif

int main(void) {
	char str[32] = "hello";

	size_t len = xstrlen(str);
	printf("%zu\n", len);

	return 0;
}