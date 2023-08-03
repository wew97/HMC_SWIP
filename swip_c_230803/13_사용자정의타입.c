// 13_사용자정의타입.c

#include <stdio.h>

// C언어 타입
// - Built-in Type (내장 타입)
// 문자타입: char
// 정수타입: signed char / unsigned char
//			short       / unsigned short
//			int         / unsigned int
//			long        / unsigned long
//			long long   / unsigned long long
// 실수타입: float / double / long double

// - User Defined Type (사용자 정의 타입)
// 1) struct
// 2) union
// 3) enum

#if 0
// * 복소수의 연산을 수행하는 프로그램을 만들어봅시다.
//    1 + 2i
//   10 + 3i
// + --------
//   11 + 5i

void Add(int ar, int ai, int br, int bi) {
	int rr, ri;
	rr = ar + br;
	ri = ai + bi;
}

int main(void) {
	int ar = 1, ai = 2;  // 1 + 2i
	int br = 10, bi = 3; // 10 + 3i

	return 0;
}
#endif

#if 0
// 핵심: 복소수 타입을 먼저 설계합니다.
struct Complex {
	// 멤버 데이터 변수
	int real;  // 실수부
	int image; // 허수부
};

struct Complex Add(struct Complex a, struct Complex b) {
	struct Complex result;
	result.real = a.real + b.real;
	result.image = a.image + b.image;

	return result;
}

int main(void) {
	struct Complex a; //  1 + 2i
	struct Complex b; // 10 + 3i 

	a.real = 1; // 멤버 접근 연산자
	a.image = 2;

	b.real = 10;
	b.image = 3;

	struct Complex result = Add(a, b);
	printf("%d + %di\n", result.real, result.image);

	return 0;
}
#endif