// 3_const.c

#include <stdio.h>

// 1. 변수의 정의 앞에 const를 붙이면,
//    변수는 수정이 불가능하다.
//    "수정 불가능한 변수" => 상수(constant variable)

#if 0
int main(void) {
	const int n = 10;
	// 초기화는 가능하지만, 초기화 이후에 값을 변경(대입)할 수 없음.

	// n = 42; // 컴파일 오류!
	printf("%d\n", n);

	return 0;
}
#endif

// 2. const 변수는 반드시 초기화해야함.
//    초기화하지 않으면, 이후에 값을 변경할 수 없고,
//    미정의 동작의 원인이 됨.

#if 0
int main(void) {
	const int c; // 쓰레기값

	// c = 100;

	printf("%d\n", c); // 미정의 동작

	return 0;
}
#endif

// 3. const는 사용 가능하면,
//    지향해야 한다.
//   1) 문제의 원인을 파악하는데 도움이 됨.
//      일반적인 변수는 값의 잘못된 변경을 확인하기 위해서,
//      모든 참조를 확인해야 하지만,
//      const 변수는 값의 잘못된 변경은 초기화만 확인하면 됨.
//   2) 병렬 프로그래밍에서 접근 제어를 해야 하지만,
//      const 변수는 필요가 없음.
//   => 불변성은 코드를 견고하고 안전하게 만드는데
//      도움이 된다!

int main(void) {
	const int n = 10;

	return 0;
}