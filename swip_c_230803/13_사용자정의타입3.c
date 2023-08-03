// 13_사용자정의타입3.c

#include <stdio.h>

#if 0
struct Point {
	int x;
	int y;
};

int main(void) {
	struct Point pt; // 지역변수 이므로 쓰레기값을 가집니다.

	// struct Point pt = { 10, 20 };
	// 멤버의 초기값을 순차적으로 이니셜라이저를 통해 나열합니다.

	// struct Point pt = { 10, }; // x = 10, y = 0
	// 순차적으로 초기화되고, 지정되지 않은 경우 0으로 초기화됩니다.

	// struct Point pt = { 0, 10 };

	// C99 표준에서 구조체를 초기화하는 새로운 방법이 도입되었습니다.
	// => 멤버 와이즈 초기화
	struct Point pt = { .x = 10, .y = 20 };

	printf("%d, %d\n", pt.x, pt.y);

	return 0;
}
#endif

#if 0
struct User {
	char name[32];
	int age;
};

void PrintUser(struct User user) {
	printf("%s (%d)\n", user.name, user.age);
	user.age = 100;
}

// 함수에서 구조체(사용자 정의 타입)을 인자로 전달하면,
// 값으로 복사해서 전달합니다.
// => 구조체를 함수로 전달할 때, 값으로 전달하는 것은
//    복사의 비용이 발생합니다.

int main(void) {
	struct User user = { .name = "Tom", .age = 42 };
	
	PrintUser(user);

	PrintUser(user);

	return 0;
}
#endif

#if 1
struct User {
	char name[32];
	int age;
};

// .  (멤버 접근 연산자)
// -> (포인터 멤버 접근 연산자)

void PrintUser(const struct User *user) { // 데이터가 변경되지 않게 하기 위해서 const
	//printf("%s (%d)\n", (*user).name, (*user).age);
	printf("%s (%d)\n", user->name, user->age);
}

int main(void) {
	struct User user = { .name = "Tom", .age = 42 };

	PrintUser(&user);

	return 0;
}
#endif