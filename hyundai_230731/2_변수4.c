// 2_변수4.c

#include <stdio.h>
#include <math.h>

// 실수 타입 / 부동 소수점 타입
// => 연산에 오차가 발생.
// - float
// - double
// - long double

int main(void) {
	double a = 0.7;
	double b = 0.1 * 7;

	printf("%lf\n", a);
	printf("%lf\n", b);

	if (fabs(a - b) < 0.0000001) {
		printf("같은 값\n");
	}
	else {
		printf("다른 값\n");
	}

	if (a == b) {
		printf("같은 값\n");
	}
	else {
		printf("다른 값\n");
	}

	return 0;
}

// 현업에서 float, double에 대해서
// typedef를 통해 크기를 명시하는 형태로 사용하는 경우가 많음.
/*
typedef float float32_t;
typedef double float64_t;
*/