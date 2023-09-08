// 10_포인터2.c

#include <stdio.h>

#if 0
// 핵심: 다른 함수에서 다른 함수의 변수의 값을 변경하는 것이
//	     일반적으로 불가능합니다.

void Inc(int x) {
	++x;
}

int main(void) {
	int x = 10;
	Inc(x); // Call by Value
	// 1) 함수의 인자는 값으로 복사되어 전달됩니다.
	// 2) 함수의 전달 받은 인자는 지역 변수와 동일한 수명을 가집니다.

	printf("%d\n", x);

	return 0;
}
#endif

void Inc(int* px) {
	++(*px);
}

int main(void) {
	int x = 10;
	Inc(&x); // Call by Reference
	// 주소를 전달해서, 포인터 변수를 통해 변수의 값을 읽거나 변경할 수 있습니다.

	printf("%d\n", x);

	return 0;
}