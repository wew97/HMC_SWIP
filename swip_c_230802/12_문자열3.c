// 12_문자열3.c

#include <stdio.h>

int main(void) {
	char* s1 = "hello";
	char* s2 = "hello";

	if (s1 == s2) {
		printf("동일한 문자열입니다.\n");
	}
	else {
		printf("동일한 문자열이 아닙니다.\n");
	}

	return 0;
}