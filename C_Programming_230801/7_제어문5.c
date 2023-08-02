// 7_���5.c

#include <stdio.h>

// 1) while
// 2) do-while
/*
do{

} while (���ǽ�)

������ �ѹ� ���� �����ϰ�, ���ǽ��� �����Ѵ�.
- �ѹ��� ������ ����Ǿ�� �� ��, �����ϴ�.

*/

#if 0
//����ڷκ��� 10���� ���� ������ �Է¹ް� �ͽ��ϴ�.
// ����ڰ� �߸� �Է��� ���, �ٽ� �Է��� �����ؾ� �մϴ�.
int main(void) {
	int n;
	scanf("%d", &n);

	while (n >= 10) {
		scanf("%d", &n);
	}

	printf("n: %d\n", n);

	return 0;
}
#endif

#if 0
int main(void) {
	int n;
	
	do {
		scanf("%d", &n);
	} while (n >= 10);

	printf("n: %d\n", n);

	return 0;
}
#endif

// 3) for
/*
for (�ʱ�ȭ; ���ǽ�; ����2){
	����1;
}

*/

#if 0
int main(void) {
	int i;
	int n;
	scanf("%d", &n);

#if 0
	i = 0;
	while (i < n) {
		printf("%d\n", i + 1);
		i++;
	}
#endif

	for (i = 0; i < n; i++) {
		printf("%d\n", i + 1);
	}

	return 0;
}
#endif

#if 0
// 1-100 ���� �� Ȧ���� ���� ���ϴ� ���α׷��� �ۼ��غ��ô�.
int main(void) {
	int sum = 0;

	for (int i = 0; i <= 100; i++) {
		if (i % 2 == 1) {
			sum += i;
		}
	}

	printf("sum: %d\n", sum);

	return 0;
}
#endif

// * continue
// => �ݺ������� �ݺ����� ������ �ڵ带 �������� �ʰ�,
//    ���� �ݺ����� �����Ѵ�.
//     for => i++ ������ ���������,
//     while ������ continue�� ����� ��, �ݺ������� ����
//     ����� ����Ǵ��� Ȯ���� �ʿ��մϴ�.

#if 0
int main(void) {
	int sum = 0;

	for (int i = 0; i <= 100; i++) {
		if (i % 2 == 0) {
			continue;
		}
		sum += i;
	}

	printf("sum: %d\n", sum);

	return 0;
}
#endif

int main(void) {
	/*
		for (; 1;) {} // ���� �ݺ���
	for (;;) {} // ���� �ݺ���

	while (1) {} // ���� �ݺ���
	*/

	return 0;
}