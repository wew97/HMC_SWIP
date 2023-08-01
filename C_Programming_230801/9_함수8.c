// 9_함수8.c

#include <stdio.h>

// 재귀 함수(Recursive Function)
//  - 정의: 함수가 자기 자신을 다시 호출하는 것을 재귀함수라고 합니다.

// 함수의 호출은 스택 메모리를 이용합니다.
// 함수의 호출의 원리를 이해해야 합니다.

#if 0
void PrintHello(void) {
	printf("Hello\n");
	PrintHello();
}

int main(void) {
	PrintHello();

	return 0;
}
#endif

#if 0
int add(int a, int b) {
	return a + b;
}

int main(void) {
	int result;

	result = add(10, 20);
	// CALL add
	// => 다음에 실행해야 하는 명령의 주소를 스택에 저장하고
	//    함수로 점프합니다.

	return 0;
}
#endif

// 재귀 함수는 반드시 "종료 조건"을 제공해야 합니다.
// => 재귀 함수의 호출이 무한정 수행될 수 없으므로(스택 메모리가 한정되어 있으므로)
//    무한정 수행되지 않도록 종료 조건을 제공해야 합니다.

#if 0
void PrintHello(int n) {
	if (n <= 0) {
		return; // 종료 조건(재귀 탈출)
	}

	printf("Hello\n");
	PrintHello(n - 1);
}

int main(void) {
	PrintHello(3);

	return 0;
}
#endif

// * 현업에서 재귀함수를 절대 사용하면 안됩니다.
//  1) 재귀함수는 무한정 호출될 수 없습니다.
//     무한정 호출될 경우, 스택의 메모리가 한정되어 있기 때문에
//     스택 오버플로우 문제가 발생하고, 미정의 동작이 발생합니다.
//  2) 재귀 함수와 비재귀 함수를 통해 동일한 알고리즘을 구현할 경우
//     재귀 함수보다 비재귀 함수가 훨씬 빠릅니다.

// 피보나치 수열
// F(0) => 1
// F(1) => 1
// F(N) => F(N-1) + F(N-2)

int Fib(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	
	return Fib(n - 1) + Fib(n - 2);
}

int main(void) {
	printf("%d\n", Fib(100));
}