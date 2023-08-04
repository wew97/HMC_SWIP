// 14_전처리기3.c

#include <stdio.h>

#if 0
// 심볼릭 상수
// 1) const
//   : 상수 표현식이 아닙니다.

// 2) enum
//   : 오직 정수 상수만 표현할 수 있습니다.

// 3) #define
//   : 상수 표현식 입니다.
//     전처리 이후에 심볼의 정보가 사라집니다.
//     컴파일러가 심볼의 정보를 알 수 없습니다.

// 상수 표현식으로 사용할 수 있습니다.
#define PI 3.14
#define BUFSIZE 1024

int main(void) {
	int x[BUFSIZE];

	return 0;
}
#endif

// 전처리기
int Square(int x) {
	return x * x;
}

int main(void) {
	int x = 10;

	printf("%d\n", Square(10));

	printf("%d\n", x * x);

	return 0;
}