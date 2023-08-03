// 13_사용자정의타입2.c

#include <stdio.h>

#if 0
//     태그
//       |
struct Point {
	int x;
	int y;
};

typedef struct Point POINT; // POINT == struct Point

int main(void) {
	POINT pt;

	printf("%zu\n", sizeof(POINT));
	printf("%zu\n", sizeof(pt));

	return 0;
}
#endif

#if 0
struct Point {
	int x;
	int y;
} pt;

int main(void) {
	printf("%d %d\n", pt.x, pt.y);

	return 0;
}
#endif

#if 0
typedef struct Point {
	int x;
	int y;
} POINT;

int main(void) {
	POINT pt;

	return 0;
}
#endif

// 태그를 생략할 수 있습니다.
typedef struct {
	int x;
	int y;
} POINT;

int main(void) {
	POINT pt1;
	// 구조체 변수를 만들 때, typedef를 통해 제공되는
	// 타입만 사용할 수 있습니다.
	
	return 0;
}