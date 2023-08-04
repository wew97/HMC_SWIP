// 13_사용자정의타입10.c

#include <stdio.h>

#if 0
typedef struct User {
	char name[32];
	int age;
} USER; // USER == struct User

typedef struct Person {
	char name[32];
	int age;
} PERSON;
// 사용자정의 타입은 멤버가 동일하더라도, 태그가 다르면 다른 타입입니다.

int main(void) {
	USER user = { .name = "Tom", .age = 42 };
	PERSON person = { .name = 'Bob', .age = 100 };

	// user = person;
	// => 다른 타입이기 때문에 컴파일 오류가 발생합니다.

	return 0;
}
#endif

#if 0
typedef struct{
	char name[32];
	int age;
} USER; // USER == struct User

typedef struct{
	char name[32];
	int age;
} PERSON;

// 태그가 없는 사용자 정의 타입은 다른 타입입니다.

int main(void) {
	USER user = { .name = "Tom", .age = 42 };
	PERSON person = { .name = 'Bob', .age = 100 };

	// user = person;
	// => 다른 타입이기 때문에 컴파일 오류가 발생합니다.

	return 0;
}
#endif

// union 타입의 크기는 내부의 가장 큰 크기를 가지는 멤버에 의해서 결정됩니다.
typedef union Data {
	int n;
	double d;
} DATA;
// 마지막에 사용한 멤버가 유효한 데이터입니다.

int main(void) {
	printf("%zu\n", sizeof(DATA));
	// union Data data;
	DATA data;
	// union 초기화는 가장 첫번째 멤버에 대한 초기화만 합니다.
	
	data.n = 100;

	printf("%d\n", data.n);

	printf("%lf\n", data.d);

	return 0;
}