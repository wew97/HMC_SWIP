// 10_포인터8.c

#include <stdio.h>

// void*
// : 대상체의 타입 정보가 존재하지 않는 포인터 변수 타입입니다.
// 1) 타입에 상관없이 모든 타입의 메모리 주소를 보관하는 목적으로 사용할 수 있습니다.
// 2) 타입에 상관없이 동작하는 코드를 작성할 때도 사용됩니다.
// => 포인터 연산을 수행할 수 없습니다.

# if 0
int main(void) {
	void* p;

	int n = 42;
	double d = 3.14;

	p = &n;

	// printf("%d\n, *p); /* 오류! */

	// void* 는 연산을 수행할 수 없기 때문에,
	// 구체적인 포인터 타입으로 담아서 연산을 수행하거나,
	// 캐스팅을 수행해야 합니다.

	int* pn = p;
	printf("%d\n", *pn);

	printf("%d\n", *(int*)pn);

	p = &d;

	return 0;
}
#endif

#if 0
int main(void) {
	int* p;
	printf("%p\n", p);

	*p = 30; /* 미정의 동작 */
	printf("%d\n", *p); /* 미정의 동작 */

	return 0;
}
#endif

// 1) 포인터가 유효한지 유효하지 않은지 구분하기 어렵습니다.
// 2) 포인터가 유효하지 않은 경우,
//    0으로 초기화해야 합니다.
// 3) 정수 0을 사용하기보다는 NULL을 사용하는 것이 좋습니다.

int main(void) {
	//int* p = 0;
	// 정수 0은 포인터 타입으로의 암묵적인 변환을 허용합니다.

	int* p = NULL;

	printf("%p\n", p);

	if (p != NULL) {
		*p = 30;
		printf("%d\n", *p); 
	}
	
	return 0;
}