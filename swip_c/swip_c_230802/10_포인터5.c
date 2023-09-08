// 10_포인터5.c
#include <stdio.h>

// * 배열을 함수의 인자로 전달할 때, 배열의 첫번째 원소의 시작 주소가
// 전달되므로, 함수에서는 배열의 길이를 알 수 없습니다.
// * 함수에서 배열의 길이를 추가적인 인자로 전달받아야 합니다.
#if 0
void PrintArray(int* arr, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        // printf("%d\n", *(arr + i));
        printf("%d\n", arr[i]); // 직관적입니다.
    }
}

int main(void)
{
    int x1[3] = { 10, 20, 30 };
    PrintArray(x1, sizeof(x1) / sizeof(x1[0]));

    int x2[4] = { 10, 20, 30, 40 };
    PrintArray(x2, 4);

    return 0;
}
#endif

// * 식별자의 오른쪽에 위치하는 것이
//   우선순위가 높습니다.

// int x[2][3]
//  - x[2]
//   : x는 2개의 요소를 가지는 배열 타입입니다. 요소의 타입은?

//  - x[2][3]
//   : 요소의 타입은 3개의 요소를 가지는 배열 타입입니다. 요소의 타입은?

//  - int x[2][3]
//   : 요소의 타입은 int 입니다.
// x [ <int><int><int> ][ <int><int><int> ]

// int *x[2]
//  - x[2]
//   : x는 2개의 요소를 가지는 배열 타입입니다. 요소의 타입은?
//  - *x[2]
//   : 요소의 타입은 포인터 타입입니다. 포인터가 참조하는 타입은?
//  - int *x[2]
//   : 포인터가 참조하는 타입은 int 입니다.
// x [  *  ][  *  ]
//      |      |
//     int    int

// int (*x)[3];
// - (*x)
//  : x는 포인터 타입입니다. 포인터가 참조하는 타입은?
// - (*x)[3]
//  : 포인터가 참조하는 타입은 3개의 요소를 가지는 배열입니다. 요소의 타입은?
// - int (*x)[3];
//  : 요소의 타입은 int입니다.

// x
// * --------> [int][int][int]

// int (*foo(void))[3]
// - foo(void)
//  : foo는 인자 없는 함수입니다. 반환 타입은?

// - (*foo(void))
//  : 반환 타입은 포인터입니다. 포인터가 참조하는 타입은?

// - (*foo(void))[3]
//  : 포인터가 참조하는 타입은 3개의 요소를 가지는 배열입니다. 배열의 요소 타입은?

// - int (*foo(void))[3]
//  : 배열의 요소 타입은 int 입니다.

// * foo(void)
// |
// |
// [int][int][int]

#if 1
void foo(int(*x)[3], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d", x[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    // [ int ][ int ][ int ]
    int arr[3] = { 10, 20, 30 };
    // arr의 타입?
    //   : int[3]
    // arr[0]의 타입은?
    //   : int
    // &arr[0]의 타입은?
    //   : int*

    int x[2][3] = { { 10, 20, 30 }, { 100, 200, 300 } };
    // [ int[3] ][ int[3] ]

    // x의 타입은 무엇인가요?
    //  : int x[2][3]
    // x[0]의 타입은 무엇인가요?
    //  : int[3]
    // &x[0]의 타입은 무엇인가요?
    //  : int (*p)[3]; => 배열을 가르키는 포인터(배열 포인터)

    foo(x, sizeof(x) / sizeof(x[0])); // foo(&x[0])

    return 0;
}
#endif

// Decay 예외
// 1) sizeof
// 2) & 주소 연산

#if 0
int main(void)
{
    int x[3] = { 10, 20, 30 };

    int* p = x; // 배열의 식별자는 배열의 첫번째 원소의 시작 주소로 해석됩니다.
    printf("%zu\n", sizeof(p)); // 8
    printf("%zu\n", sizeof(x)); // 12

    int(*p2)[3] = &x;

    return 0;
}
#endif

#if 0
int main(void)
{
    int n = 10;
    int* p = &n;
    //  p: int*
    // *p: int
    *p = 10;

    int x[3] = { 10, 20, 30 };
    int(*px)[3] = &x;

    //  px: int(*)[3]
    // *px: int[3]
    (*px)[0] = 100;
    printf("%d\n", x[0]);

    return 0;
}
#endif