// 5_연산자3.c

#include <stdio.h>

// && => 논리 AND 연산자
// || => 논리 OR 연산자
//    : 단일 회로 성질

// (cond1) && (cond2)
// : cond1과 cond2가 모두 참이어야 결과가 참
// (cond1) || (cond2)
// : cond1 또는 cond2 둘 중 하나만 참이어도 결과가 참

#if 0
int main(void) {
	int a = 0;
	int b = 0;
	int result = 0;

	result = a++ && ++b;
	printf("%d %d %d\n", a, b, result);
	// 1 0 0 => a++는 ++이 되기전에 참거짓 판단 -> 거짓 -> 그 뒤로는 실행 안함

	a = b = result = 0;
	result = --a || ++b;
	printf("%d %d %d\n", a, b, result);
	// -1 0 1

	return 0;
}
#endif

// 논리 연산자 &&
// 논리 연산자 ||
//  위의 연산자를 함께 사용하는 경우,
//  우선순위가 다른 문제가 있음.
// => 명시적으로 괄호를 반드시 사용해야 함.

int main(void) {
	int a;
	int b;
	int c;
	int result;

	a = b = c = result = 0;


	result = ++a || b++ && ++c;
	printf("%d %d %d %d\n", a, b, c, result);

	a = b = c = result = 0;
	result = ++a && ++b || c++;
	printf("%d %d %d %d\n", a, b, c, result);

	int d = 0;
	a = b = c = result = 0;
	result = ++a || b++ && c++ || ++d;

	// result = (++a || (b++ && c++)) || ++d;

	return 0;
}