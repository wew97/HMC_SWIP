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