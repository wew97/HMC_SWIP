// 10_������_����.c

#include <stdio.h>

// 1. ������ ����� ���� �޸� �Ҵ��� �̷�����ϴ�.
// 2. ������ �̸��� ���ؼ� �ش��ϴ� �޸𸮿� ������ �� �ֽ��ϴ�.
// 3. ������ ����
//   - �ٸ� ������ �ּҸ� �����ϴ� ����
//   - ������ ������ ������ �ּҿ� �����ؼ�, �޸𸮸� �аų� ������ �� �ֽ��ϴ�.

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

// - �迭�� �̸��� �迭�� ù��° ������ ���� �ּҷ� �ؼ��˴ϴ�.
// - �迭�� �Լ��� ���ڷ� ���޵� ��, ��ü �޸𸮰� ����Ǿ� ���޵Ǵ� ���� �ƴ϶�
//   �迭�� ù��° ������ ���� �ּҰ� ���޵˴ϴ�.

/*
void foo(int x[3]) { // foo(int* x)
	x[0] = 100;
}
*/

// - �Լ����� �迭�� ���޵� ��, �迭�� ù��° ������ ���� �ּҸ� ���޵Ǳ� ������
//   �Լ������� �迭�� ���̸� �� �� �����ϴ�.
//   �Լ����� �迭�� ���̰� �ʿ��� ���, �߰����� ���ڸ� ���ؼ� �����ؾ� �մϴ�.

//   ���ڿ��� ���, ���ڿ��� ������ ���ڰ� null����('\0')�̱� ������
//   ���̸� �������� �ʾƵ�, ���ڿ��� ���� ó���� �� �ֽ��ϴ�.

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

	// �޸� ������ �����ϴµ�, �������� Ÿ�Կ� �������
	// ����Ʈ ������ ������ �����ϰ� �ʹٸ�,
	// ��������� char* Ÿ������ ĳ���� �ϸ� �˴ϴ�.
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

    // Decay ���� ���� x�� Ÿ����?
    //  : int[5]

    // Decay �� x�� Ÿ����?
    //  : &x[0] -> int*

    printf("%p\n", x);
    printf("%p\n", x + 1);
    printf("%p\n", x + 2);
    printf("%p\n", x + 3);
    printf("%p\n", x + 4);

    // *(X + N) ==> X[N]
    // X => &X[0] ==> &*(X + 0) ==> (X + 0) ==> X
    //                --
    //               ���
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

    // Decay ���� ���� x�� Ÿ����?
    //  : int [2][3]
    // Decay �� x�� Ÿ����?
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
// �Ʒ� �Լ��� �迭�� ����Ÿ���� int�� ��� 1���� �迭�� ����� �� �ִ�
// �Լ��Դϴ�.
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
// �迭�� ���� Ÿ���� int[3]�� ��� 2���� �迭�� ����� �� �ִ� 
// �Լ��Դϴ�.
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
    // �޸𸮸� ���ϴ� ���·� �ؼ��� �� �ֽ��ϴ�.
    // �ٸ� ������ ���� �Ϲ����� ��ȭ�� �����Ϸ��� �����ϴٰ� �Ǵ��մϴ�.
    // C => ���, C++ => ����
    //  : ������� ��ȯ�� ���� �ǵ��ߴٴ� ����� �˷��� �մϴ�.
    // ���� - ������� ��ȯ �Ǵ� �Ϲ����� ��ȯ���� ���� �߸��� �޸� ������
    //        ������ ������ �߻����� �ʵ��� �����ؾ� �մϴ�.

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
//PrintArray �Լ��� ���� �����غ�����.
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
    // ���� 1���� 1�迭�� PrintArray�� ���ؼ� ����ϴ� �ڵ带 �ۼ��غ�����.
    // => ������� ĳ����

    return 0;
}
#endif

// void*
// => �������ε� ���ü�� Ÿ�� ������ ���� ������ Ÿ���Դϴ�.
// 1) ��� �ּҸ� ������ �� �ֽ��ϴ�.
// 2) �ٸ� ������ Ÿ�������� �Ϲ����� ��ȯ�� ���˴ϴ�.

// * ���ü�� Ÿ�� ������ ���� ������,
//   ��ü���� ������ Ÿ������ ��ȯ�ϰų�, �ٸ� ������ Ÿ������ �����ؼ�
//   ����ؾ� �մϴ�.

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
    // ���� �ڵ�� ǥ���� �ƴմϴ�.
    // GNU / clang �����Ϸ������� ����մϴ�.

    printf("%p\n", (char*)p + 1);
    printf("%p\n", (int*)p + 1);

    return 0;
}
#endif

// �����͸� ���޹޴� �Լ�����,
// ���ü�� ���� �������� �ʰ� �б⸸ �ϴ� ���
// �ݵ�� cosnt�� ����ؾ� �մϴ�.
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