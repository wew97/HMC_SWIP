// 12_문자열2.c

#include <stdio.h>

#if 0
// C의 문자열
// : char 배열인데 마지막 문자가 '\0'(null문자, 0)입니다.

int main(void) {
	char str[] = "hello"; // char[6]
	printf("%zu\n", sizeof(str));

	char str2[32] = "hello"; // char[32]
	printf("%zu\n", sizeof(str2));

	return 0;
}
#endif

// const가 *의 앞에 선언되었다.
// - const char* s = "hello";
// - char const* s = "hello";

// s ----------> "hello"
//               <const>
// > 포인터를 통해서 참조하는 대상체의 메모리를 읽기만 하고,
//   수정할 수 없습니다.

// const가 *의 뒤에 선언되었다.
// char* const s = "hello";
// s ----------> "hello"
// <const>
// > 포인터를 통해서 참조하는 대상체를 읽거나 수정할 수 있지만,
//   포인터 변수를 다른 주소로 변경할 수 없습니다.

#if 0
int main(void) {
	char str[32] = "hello";
	char* s = "hello";

	str[0] = 'X';
	printf("%s\n", str);

	// s[0] = 'X'; /* 미정의 동작 */

	return 0;
}
#endif

