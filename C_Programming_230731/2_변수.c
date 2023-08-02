// 2_변수.c

#include <stdio.h>
#include <stdlib.h> //malloc

// 변수의 종류 (기억 부류, Storage Class)
// : 수명에서 차이가 있음.

// 1) 지역 변수
// - 함수가 시작할때 생성되고,
//   함수가 끝나면 사라짐.
 
// 2) 전역 변수
// - 프로그램이 시작할 때 초기화되고,
//    프로그램이 끝날 때까지 유지
 
// 3) 정적 지역 변수 (내부 정적 변수)
// - 함수가 최초에 실행되는 시점에 초기화되고,
//   프로그램이 끝날 때까지 유지
  
// 4) malloc => 힙 변수
// - 프로그래머가 원하는 시점에 할당되고,
//   프로그래머가 원하는 시점에 파괴할 수 있음.

int global = 100;

int main(void) {
	
	printf("global: %p\n", &global);

	int local = 42; // 지역 변수
	printf("local: %p\n", &local);

	static int slocal = 200; // 정적 지역 변수
	printf("slocal: %p\n", &local);

	int* p = malloc(sizeof(int)); // 힙 변수
	printf("malloc: %p\n", p);

	return 0;
}