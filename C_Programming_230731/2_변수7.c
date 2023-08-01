// 2_변수7.c

#include <stdio.h>

// 1) sizeof
//  : 변수의 크기 또는 타입의 크기를 구할 때 사용하는 연산자
//  => 연산의 결과 타입은 size_t 타입

// signed char => %hhd
// short	   => %hd
// int		   => %d
// long		   => %ld
// long long   => %lld

// unsigned			  => %u
// unsigned long	  => %lu
// unsigned long long => %llu

// size_t: %zu

// float => %f
// double => %lf
// long double => %Lf

#if 0
int main(void) {
	float f1 = 3.14f;
	double f2 = 3.14;
	long double f3 = 3.14L;

	printf("%f %lf %Lf\n", f1, f2, f3);

	int n = 10;

	printf("%zu\n", sizeof(n)); // sizeof(변수명)
	printf("%zu\n", sizeof n); // sizeof 변수명
	printf("%zu\n", sizeof(int)); // sizeof(타입)

	return 0;
}
#endif

// => 16진수는 하나의 수마다 4비트를 통해 표현됨.
// 0x 12 34 56 78
//	0001 0010 0011 0100 0101 0110 0111 1000

// => 8진수는 0을 앞에 붙이는 형태로 사용할 수 있음.
// : 사용을 하지 않는 것이 좋습니다.

#if 0
int main(void) {
	int n1 = 0x12345678; // 16진수
	int n2 = 0123; // 8진수 => 사용하지 않는 것이 좋음
	printf("%d\n", n2);

	// 명시적인 캐스팅 연산자
	// => 타입을 변환함.
	printf("%hhd\n", (signed char)n1); // 1바이트 정수
	printf("%hd\n", (short)n1); // 2바이트 정수 
	printf("%d\n", n1); // 4바이트 정수

	return 0;
}
#endif

// * 컴파일러마다 번역되는 기계어를 확인하는 방법
// godbolt.org(컴파일러 익스플로러)

// * sizeof
// => 컴파일 타임에 수행

// * 컴파일러는 컴파일 시간에 계산을 미리 수행할 수 있으면
// 수행한다!
// => 상수 표현식

int main(void) {
	int n = sizeof(int);

	return 0;
}