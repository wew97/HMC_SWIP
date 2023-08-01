// 5_연산자2.c

#include <stdio.h>

// 연산의 결과가 참(1)과 거짓(0)일 수 있음.

// 1) ==, !=, >, <, >=, <=
//  "논리 표현식"의 결과는 참(1) 또는 거짓(0)

// 2) 0은 거짓으로 평가됨.
//   0이 아닌 값은 참으로 평가됨.

#if 0
int main(void) {
	int a = 10;
	int b = 20;

	printf("%d\n", a == b); // 거짓, 0
	printf("%d\n", a != b); // 참, 1

	int condition = -1;
	if (condition) {
		printf("조건이 참입니다.\n");
	}
	else {
		printf("조건이 거짓입니다.\n");
	}

	return 0;
}
#endif

// C언어에 참/거짓을 표현하는 타입이 도입되었음.
// C99 표준에 도입됨.

#include <stdbool.h>
// typedef _Bool bool;

int main(void) {
	_Bool a = 43;
	bool b = true;
	bool c = false;

	printf("%d\n", a);

	return 0;
}