// 7_���3.c

#include <stdio.h>

// �ݺ���(Iterative Statement)
// 1) while
/*
while (���ǽ�) {
	statement; // ���ǽ��� ���̸� ��� ����
}
*/

#if 0
int main(void) {
	int n;
	scanf("%d", &n);

	int i = 0;
	while (i < n) {
		printf("Hello\n");
		++i;
	}

	return 0;
}
#endif

// ����ڰ� -1�� �Է��� ������ �Էµ� ��� ������ ���� ���ϴ� ���α׷���
// �ۼ��� ���ô�.

#if 0
int main(void) {
	int n = 0;
	int sum = 0;

	while (n != -1) {
		scanf("%d", &n);
		sum = sum + n;
	}

	printf("sum: %d\n", sum+1);

	return 0;
}
#endif

#if 0
// break => �ݺ����� Ż���� �� ���
int main(void) {
	int n;
	int sum = 0;

	while (1) { // ���� ����
		scanf("%d", &n);

		if (n == -1)
		{
			break; // �ݺ��� Ż��
		}

		sum += n;
	}

	printf("sum: %d\n", sum);

	return 0;
}
#endif

#if 0
// ����ڷκ��� �Էµ� �������� Ȧ���� ���� ���ϴ� ���α׷��� �ۼ��غ��ô�.
int main(void) {
	int n;
	int sum = 0;

	scanf("%d", &n);

	int i = 0;
	while (i < n) {
		if ((i + 1) % 2 == 1) {
			sum += (i + 1);
		}
		i++;
	}

	printf("sum: %d\n", sum);

	return 0;
}
#endif

int main(void) {
	int n;
	int sum = 0;

	scanf("%d", &n);

	int i = 1;
	while (i <= n) {
		if (i % 2 == 1) {
			sum += i;
		}
		i++;
	}

	printf("sum: %d\n", sum);

	return 0;
}

// �ݺ����� ������ �ۼ��� ��
// i = 0 ~ N-1
// i = 1 ~ N
// -> ���� ���ǿ� ���� �ڵ尡 �޶��� �� ����.