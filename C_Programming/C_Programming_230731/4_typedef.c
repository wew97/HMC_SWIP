// 4_typedef.c

#include <stdio.h>

// 1. 기존 타입에 별칭을 부여한다.
// 2. 타입을 구하는 방법
//   int n;    => int
//   int *p;   => sint*
//   int x[3]; => int[3]

// 3. 변수를 선언의 앞에 typedef를 붙이면 된다.
//    식별자가 변수가 아닌 타입의 별칭이 됨.

#if 0
int main(void) {
	typedef int AGE_TYPE; // AGE_TYPE = int
	AGE_TYPE n;

	//int x[3];
	// x의 타입은 무엇인가요? => int[3]

	typedef int ARR3[3]; // ARR3 = int[3]

	ARR3 x; // int[3]

	printf("%zu\n", sizeof(int[3])); // 12B
	printf("%zu\n", sizeof(x));

	x[0] = 10;
	x[1] = 20;
	x[2] = 30;

	return 0;
}
#endif

// 4. typedef 사용하는 목적n => "가독성"
//  stdint.h

#if 0
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

int main(void) {
	size_t s;

	return 0;
}
#endif

// 5. 복잡한 타입의 표현식이 발생할 수 있습니다.
typedef int(*PARR3)[3];
// int (*foo(void))[3]

PARR3 foo(void)
{
	static int x[3];
	return &x; // int(*)[3]
}

typedef void (*func_t)(int);
func_t signal(int sig, func_t func) { }

// void (*signal(int sig, void (*func)(int)))(int);

int main(void)
{
	return 0;
}