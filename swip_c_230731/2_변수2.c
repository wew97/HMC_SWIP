// 2_변수2.c

#include <stdio.h>

// 1) C 표준에서는 정수 타입의 크기가 표준적으로 정의되어 있지 않음.
// => 컴파일러와 시스템에 따라 달라질 수 있음.
// long: 32bit / 64bit

// 2) C 표준에서 타입의 크기가 정의되어 있는 유일한 타입은
// char 타입
// => 1 바이트

// 3) char 타입은 3가지가 있음.
// - char (문자타입)
// - signed char (부호 있는 1바이트 정수 타입)
// - unsigned char (부호 없는 1바이트 정수 타입)

// C언어 타입 (64비트 플랫폼 기준)
// - 문자 타입 (1바이트)
// => ASCII
// 'A': 65, 'a': 97, '0': 46

// char

// - 정수 타입
// 1바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
// signed char / unsigned char

// 2바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
// short / unsigned short

// 4바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
// int / unsigned int

// 주의: long => MSVC: 4바이트, GCC/clang: 8바이트 

// 8바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
// long long / unsigned long long

// - 실수 타입

int main(void) {
	//printf("%zu\n", sizeof(long));

	char c = 150;
	// signed? unsigned?
	// 표준에서 미지정 사항입니다.
	// => char타입을 1바이트 정수 타입으로 사용하는 경우
	// 반드시 signed / unsigned 명시해야 함.

	int n = 100;

	return 0;
}