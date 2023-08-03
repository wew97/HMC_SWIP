// 10_포인터_정리.c

#include <stdio.h>

// 1. 변수를 만드는 것은 메모리 할당이 이루어집니다.
// 2. 변수의 이름을 통해서 해당하는 메모리에 접근할 수 있습니다.
// 3. 포인터 변수
//   - 다른 변수의 주소를 저장하는 변수
//   - 포인터 변수가 가지는 주소에 접근해서, 메모리를 읽거나 변경할 수 있습니다.

#if 0
void foo(int x) { // Call by Value
	x = 100;
}

void goo(int* p) { // Call by Reference
	*p = 100;
}

int main(void) {
	int n = 42;

	foo(n);
	printf("foo: %d\n", n);

	goo(&n);
	printf("goo: %d\n", n);

	return 0;
}
#endif

// - 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
// - 배열의 함수의 인자로 전달될 때, 전체 메모리가 복사되어 전달되는 것이 아니라
//   배열의 첫번째 원소의 시작 주소가 전달됩니다.

/*
void foo(int x[3]) { // foo(int* x)
	x[0] = 100;
}
*/

// - 함수에서 배열이 전달될 때, 배열의 첫번째 원소의 시작 주소만 전달되기 때문에
//   함수에서는 배열의 길이를 알 수 없습니다.
//   함수에서 배열의 길이가 필요한 경우, 추가적인 인자를 통해서 전달해야 합니다.

//   문자열의 경우, 문자열의 마지막 문자가 null문자('\0')이기 때문에
//   길이를 전달하지 않아도, 문자열의 끝을 처리할 수 있습니다.

#if 0
void foo(int* x) {
	x[0] = 100;
	x[1] = 200;
}

int main(void) {
	int x[3] = { 10,20,30 };
	foo(x); // foo(&x[0]);

	printf("%d\n", x[0]);

	return 0;
}
#endif

#if 0
int main(void) {
	int* p1 = NULL;
	printf("%p\n", p1 + 2); // p1 + sizeof(*p1) * 2; // 8

	double* p2 = NULL;
	printf("%p\n", p2 + 2); // p2 + sizeof(*p2) * 2; // 10

	char* p3 = NULL;
	printf("%p\n", p3 + 2); // 2

	// 메모리 연산을 수행하는데, 포인터의 타입에 상관없이
	// 바이트 단위의 연산을 수행하고 싶다면,
	// 명시적으로 char* 타입으로 캐스팅 하면 됩니다.
	// https://cnst.livejournal.com/24040.html
	long long* p4 = NULL;
	printf("%p\n", (char*)p4 + 16); // 10

	return 0;
}
#endif

#if 0
int main(void)
{
    //           x   x+1 x+2 x+3 x+4
    //         &x[0]  |   |   |   |
    //           |    |   |   |   |
    int x[5] = { 10, 20, 30, 40, 50 };

    // Decay 되지 않은 x의 타입은?
    //  : int[5]

    // Decay 된 x의 타입은?
    //  : &x[0] -> int*

    printf("%p\n", x);
    printf("%p\n", x + 1);
    printf("%p\n", x + 2);
    printf("%p\n", x + 3);
    printf("%p\n", x + 4);

    // *(X + N) ==> X[N]
    // X => &X[0] ==> &*(X + 0) ==> (X + 0) ==> X
    //                --
    //               상쇄
    printf("%d\n", *x);
    printf("%d\n", *(x + 1));
    printf("%d\n", *(x + 2));
    printf("%d\n", *(x + 3));
    printf("%d\n", *(x + 4));

    printf("%d\n", x[0]);
    printf("%d\n", x[1]);
    printf("%d\n", x[2]);
    printf("%d\n", x[3]);
    printf("%d\n", x[4]);

    int* p = x;
    printf("%p\n", p);
    printf("%p\n", p + 1);
    printf("%p\n", p + 2);
    printf("%p\n", p + 3);
    printf("%p\n", p + 4);

    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));
    printf("%d\n", *(p + 3));
    printf("%d\n", *(p + 4));

    printf("%d\n", p[0]);
    printf("%d\n", p[1]);
    printf("%d\n", p[2]);
    printf("%d\n", p[3]);
    printf("%d\n", p[4]);

    return 0;
}
#endif

int main(void)
{
    // [ int[3] ][ int[3] ]

    int x[2][3] = {
        /*     x ---> */ { 10, 20, 30 },
        /* x + 1 ---> */ { 40, 50, 60 }
    };

    // Decay 되지 않은 x의 타입은?
    //  : int [2][3]
    // Decay 된 x의 타입은?
    //  : int (*)[3]
    //    * ----------> int[3]

    printf("%p\n", x);
    printf("%p\n", x + 1);

    return 0;
}