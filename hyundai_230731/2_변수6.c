// 2_변수6.c

#include <stdio.h>

#if 0
int main(void) {
	int a = 10;
	int b = 20;

	int c = 10, d = 20;
	// 위처럼 사용하는 것은 지양해야 한다.

	int* pa;
	int* pb;

	//int* pc, pd;
	// pc -> int*
	// pd -> int

	int* pc, * pd;
	// pc -> int*
	// pd -> int*

	printf("%d %d %d %d\n", a, b, c, d);

	return 0;
}
#endif

// 10 -> int
// l, L -> long (반드시 대문자로 사용)
// ll, LL -> long long (반드시 대문자로 사용)

// 3.14 -> double
// f, F -> float
// l, L -> long double

int main(void) {
	int n = 10; // 상수 리터럴
	long x = 100L;

	long long y = 10000LL;
	
	float f = 3.14f;

	long double ld = 3.14L;

	printf("%ld\n", x);

	return 0;
}