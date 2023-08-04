// 15_파일입출력.c

#include <stdio.h>

// Linux / Unix
// => 모든 것이 파일입니다.
//    파일의 연산을 통해 일반 파일, 디바이스 파일, 소켓 파일 ...
//    을 다룰 수 있습니다.

// printf ==> stdout 파일에 출력하고 있습니다.
// scanf  ==> stdin 파일로부터 입력하고 있습니다.

#if 0
int main(void) {
	fprintf(stdout, "Hello, World!\n");

	int n;
	fscanf(stdin, "%d", &n);

	fprintf(stdout, "n: %d\n", n);

	return 0;
}
#endif

// - FILE *fopen(const char* path, const char* mode);

int main(void) {


	return 0;
}