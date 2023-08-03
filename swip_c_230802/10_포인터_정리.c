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

#if 0
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
#endif

#if 0
int main(void) {
    
    int x[5] = { 10,20,30,40,50 };

    printf("%p\n", x);  // Decay -> &*x[0] -> int*
    printf("%p\n", &x); // x: int[5], &x: int(*)[5]

    printf("%p\n", x + 1);  // x + sizeof(int) * 1
    printf("%p\n", &x + 1); // x + sizeof(int[5]) * 1

    return 0;
}
#endif

#if 0
// 아래 함수는 배열의 원소타입이 int인 모든 1차원 배열이 사용할 수 있는
// 함수입니다.
// void PrintArray(int x[5]) 
void PrintArray(int *x, int n){
    for (int i = 0; i < n; i++) {
        printf("%3d ", x[i]);
    }
    printf("\n");
}

int main(void) {
    int x[15] = { 10,20,30,40,50 };

    PrintArray(x, 5);

    int a[3] = { 100,200,300 };
    PrintArray(a, 3);

    return 0;
}
#endif

#if 0
// 배열의 원소 타입이 int[3]인 모든 2차원 배열이 사용할 수 있는 
// 함수입니다.
void PrintArray(int(*x)[3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d ", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int arr[6] = { 1,2,3,4,5,6 };
    // 메모리를 원하는 형태로 해석할 수 있습니다.
    // 다른 포인터 간의 암묵적인 변화는 컴파일러가 위험하다고 판단합니다.
    // C => 경고, C++ => 에러
    //  : 명시적인 변환을 통해 의도했다는 사실을 알려야 합니다.
    // 주의 - 명시적인 변환 또는 암묵적인 변환으로 인한 잘못된 메모리 접근은
    //        미정의 동작이 발생하지 않도록 주의해야 합니다.

    PrintArray((int(*)[3])arr, 2);

    int y[1][3] = { {100,200,300} };
    PrintArray(y, 1);

    // [ int[3] ][ [int[3] ]
    int x[2][3] = { 10,20,30,40,50,60 };

    // PrintArray(x, 2);
    PrintArray(x, sizeof(x) / sizeof(x[0]));

    return 0;
}
#endif

#if 0
//PrintArray 함수를 직접 구현해보세요.
void PrintArray(int (*x)[2], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%3d ", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int x1[3][2] = { 1,2,3,4,5,6 };
    PrintArray(x1, 3);

    int x2[1][2] = { 1,2 };
    PrintArray(x2, 1);

    int arr[6] = { 10,20,30,40,50,60 };
    PrintArray((int (*)[2])arr, 3);
    // 위의 1차원 1배열을 PrintArray를 통해서 출력하는 코드를 작성해보세요.
    // => 명시적인 캐스팅

    return 0;
}
#endif

// void*
// => 포인터인데 대상체의 타입 정보가 없는 포인터 타입입니다.
// 1) 모든 주소를 보관할 수 있습니다.
// 2) 다른 포인터 타입으로의 암묵적인 변환이 허용됩니다.

// * 대상체의 타입 정보가 없기 때문에,
//   구체적인 포인터 타입으로 변환하거나, 다른 포인터 타입으로 전달해서
//   사용해야 합니다.

#if 0
int main(void) {
    int n = 42;
    double d = 3.14;

    void* p;
    p = &n;

    int* pn = p;
    printf("%d\n", *pn);
    printf("%d\n", *(int*)p);

    p = &d;

    p = NULL;
    // printf("%p\n", p + 1); // p + sizeof(*p) * 1;
    // 위의 코드는 표준이 아닙니다.
    // GNU / clang 컴파일러에서는 허용합니다.

    printf("%p\n", (char*)p + 1);
    printf("%p\n", (int*)p + 1);

    return 0;
}
#endif

// 포인터를 전달받는 함수에서,
// 대상체의 값을 변경하지 않고 읽기만 하는 경우
// 반드시 cosnt를 사용해야 합니다.
void PrintArray(const int* x, int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", x[i]);
    }

    // x[0] = 1000;

    printf("\n");
}

int main(void) {
    int x[3] = { 10,20,30 };
    PrintArray(x, 3);

    printf("%d\n", x[0]);

    return 0;
}