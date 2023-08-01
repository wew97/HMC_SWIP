// 1_start2.c

// 1. Compile 과정
// - 전처리기
// #define
// #include
// #if
// ...
// => 텍스트 처리

// - 컴파일
// a.c -> a.o / a.obj
// b.c -> b.o / b.obj

// - 링크
// a.obj + b.obj => a.exe / a.out

// 2. 컴파일러(소스 코드를 CPU의 기계어로 번역하는 역할을 수행하는 프로그램)
//  => 이식성
// - Microsoft Visual C/C++ Compiler => MSVC
// - GNU C/C++ Compiler => GCC
// - LLVM Compiler => clang

// 3. C 표준
// C89/C90 표준
// C99, C11, C17, C23...

// 참고 C++ 표준
// C++98/03 => 1.0
// C++11/14 => Modern C++
// C++17/20
// C++23

// 4. 참고 문서 - https://devdocs.io

// 5. 미정의 동작(Undefined Behaviour)
// => 표준에 의해 정의되어 있지 않은 동작입니다.
//    컴파일러와 실행 환경에 따라 다른 형태로 동작하고, 문제가 발생합니다.

// 미지정 동작 (Unspecified Behaviour)
// => 동작을 수행하는 데 있어서, 선택 경로가 여러개 존재할 수 있는 경우
//    컴파일러마다 경로가 달라질 수 있습니다.

#include <stdio.h>
//표준 입출력 해더 파일
// - printf, scanf...

void foo(void) {} // Okay!

// 컴파일러가 인자가 잘못 전달되었을 경우에,
// 컴파일 오류가 발생하지 않습니다.
void goo() {} // No!

// 프로그램이 시작되었을 때, 가장 먼저 수행되는 함수
// => Entry Point
int main(void) {

	// foo(10,20);
	//goo(10, 20); /* 미정의 동작 */
	
	return 0; // 0 - 성공!
}
