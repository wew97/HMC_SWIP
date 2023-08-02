// 10_포인터3.c

#include <stdio.h>

#if 0
int main(void) {
	int a = 10;
	int b = 20;

	int temp = a;
	a = b;
	b = temp;
	printf("%d %d\n", a, b);

	return 0;
}
#endif

#if 0 
void Swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int main(void) {
	int a = 10;
	int b = 20;

	Swap(a, b); // Call by Value => swap 안됨.
	printf("%d %d\n", a, b);

	return 0;
}
#endif

#if 0
void swap(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main(void) {
	int a = 10;
	int b = 20;

	swap(&a, &b); // Call by Reference
	printf("%d %d\n", a, b);

	return 0;
}
#endif