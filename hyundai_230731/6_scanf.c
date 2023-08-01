// 6_scanf.c

#include <stdio.h>

// 표준 출력 함수: printf
// 표준 입력 함수: scanf

#if 0
int main(void) {
	// 입력을 수행하기 위해서는,
	// 입력의 결과를 저장하기 위한 변수가 필요.

	int age;
	scanf_s("%d", &age);
	// 주의사항: 입력의 결과를 저장하기 위한 변수의 주소를
	//			 전달해야 한다.

	printf("age: %d\n", age);

	return 0;
}
#endif

int main(void) {
	int n1, n2;

	// scanf_s("%d", &n1);
	// scanf_s("%d", &n2);

	scanf_s("%d %d", &n1, &n2);

	printf("n1: %d, n2: %d, result: %d\n", n1, n2, n1 + n2);

	return 0;
}