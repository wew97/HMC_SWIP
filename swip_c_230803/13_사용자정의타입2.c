// 13_���������Ÿ��2.c

#include <stdio.h>

#if 0
//     �±�
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

// �±׸� ������ �� �ֽ��ϴ�.
typedef struct {
	int x;
	int y;
} POINT;

int main(void) {
	POINT pt1;
	// ����ü ������ ���� ��, typedef�� ���� �����Ǵ�
	// Ÿ�Ը� ����� �� �ֽ��ϴ�.
	
	return 0;
}