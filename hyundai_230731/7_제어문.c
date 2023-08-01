// 7_제어문.c

#include <stdio.h>

// 1. C언어로 작성된 모든 프로그램은 main 함수의 첫 번째 문장부터
//    순차적으로 실행된다.

// 2. 실행 흐름을 변경하고 싶을 때, 사용하는 문장을
//    제어문(Control Statement)이라고 합니다.

// 3. 제어문 종류
//  - 조건문 (Conditional Statement)
//    : 조건이 만족할 때 실행되는 구문을 정의한다.
//    if / if - else / if - else if - else
//    switch

//  - 반복문(Iterative Statement)
//    : 조건이 만족하면, 반복해서 실행하는 구문을 정의한다.
//    while / for / do-while

// 조건문
// 1) if
/*
if (조건식) {
		statement1;
		statement2;
		...
}
*/

// 사용자로부터 나이를 입력 받아서, 18세 이상이면
// "성인입니다." 를 출력하는 프로그램을 작성해봅시다.

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	if (age >= 18) {
		printf("성인입니다.\n");
	}
	// 조건문이나 반복문에서 문장이 1개만 존재하는 경우,
	// 블록을 생략할 수 있음.
	// => 하지만 실수를 방지하기 위해서,
	//    반드시 블록을 사용해야 한다.

	return 0;
}
#endif

// 18세 이상인 경우 "성인입니다."를 출력하고,
// 18세 미만인 경우 "성인이 아닙니다."를 출력하는 프로그램을 작성해봅시다.

/*
if (조건식){
	// 조건식이 참일 경우 수행되는 문장을 정의
} else{
	// 조건식이 거짓일 경우 수행되는 문장을 정의
}
*/

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	if (age >= 18) {
		printf("성인입니다.\n");
	}
	else {
		printf("성인이 아닙니다.\n");
	}

	return 0;
}
#endif

// +) 18세 미만인 경우,
//    8세 미만이면 "미취학 아동입니다."
//    8세 이상이면 "학생입니다."

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	// 조건문 안에 조건문을 작성할 수 있습니다.
	if (age >= 18) {
		printf("성인입니다.\n");
	}
	else {
		// age가 18세 미만입니다.
		
		if (age < 8) {
			printf("미취학 아동입니다.\n");
		}
		else {
			printf("학생입니다.\n");
		}
	}
	

	return 0;
}
#endif

// 조건이 반복될 경우
// 중첩된 조건문보다 if - else if - else 구문을 사용하는 것이 좋다.

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	if (age >= 18) {
		printf("성인입니다.\n");
	}
	else if (age < 8) {
		printf("미취학 아동입니다.\n");
	}
	else {
		printf("학생입니다.\n");
	}

	return 0;
}
#endif
// MISRA C 2008
//-----------
//       C 2012 - C99 - *
//       C 2023 - C11

// MISRA
// => if, else-if 구문에서
//    반드시 else를 작성해야 합니다.
int main(void)
{
	int age;
	scanf("%d", &age);

	// 1번
	char grade;
	if (age >= 18) {
		grade = 'A';
	}
	else if (age < 8) {
		grade = 'B';
	}
	else {
		grade = 'C';
	}

	// 2번
	// => else-if를 사용할 때, else에서 아무것도 수행하지 않더라도
	//    반드시 else 구문을 작성해야 합니다.
	grade = 'C';
	if (age >= 18) {
		grade = 'A';
	}
	else if (age < 8) {
		grade = 'B';
	}
	else {
		/* Nothing */;
	}

	// char: 문자를 출력할 때는 %c를 사용하면 됩니다.
	printf("grade: %c\n", grade);

	return 0;
}