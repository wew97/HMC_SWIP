// 11_�����޸��Ҵ�.c

#include <stdio.h>
#include <stdlib.h> // malloc

// 1. �迭�� ũ��� ������ Ÿ�ӿ� �����Ǿ�� �մϴ�.
// 2. ���� �ð��� �Ҵ��ϴ� �޸� ũ�⸦ �����ϰ� �ͽ��ϴ�.
//  => ���� �޸� �Ҵ�
//     void *malloc( size_t size );	

// 3. �޸� �Ҵ��� �����ϰ�, �� �̻� �������� ���� ���
//    �ݳ��ؾ� �մϴ�.
//  => void free( void *ptr );

// 4. ���� �޸� �Ҵ� ������
//  1) �޸� ������ ���輺
//     : free�� ������� �ʴ� ���, �޸𸮰� �����ǰ�, ����Ǵ� �޸𸮰� ����
//       ��� ���α׷��� ������ ������ ������ �� �ֽ��ϴ�.
//  2) �Ҵ�� ������ �������尡 �ֽ��ϴ�.
//  3) malloc�� ���� ������ �Լ��Դϴ�.
//     �޸� �Ҵ翡 �����Ͽ��� ���, NULL�� ��ȯ�մϴ�.

// => ���� �޸� �Ҵ��� ���ؼ� �����ڰ� ���ϴ� ������ �޸𸮸� �Ҵ��ϰ�
//    �����ڰ� ���ϴ� ������ �޸𸮸� ������ �� �ֽ��ϴ�.

#if 0
int main(void) {
	int* p = malloc(sizeof(int));
	if (p != NULL) {
		*p = 42;
		printf("%d\n", *p);

		free(p);
	}

	return 0;
}
#endif

#if 0
int main(void) {
	int* p = malloc(sizeof(int)); // 4B
	if (p != NULL) {
		// ...

		free(p);
	}

	int n;
	scanf("%d", &n);

	int* arr = malloc(sizeof(int) * n); // 1���� �迭
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			arr[i] = i * n;
		}
		for (int i = 0; i < n; i++) {
			printf("%d\n", arr[i]);
		}

		free(arr);
	}

	return 0;
}
#endif

#if 0
int main(void) {
	int x[2][3] = { {10,20,30}, {40,50,60} };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\n", x[i][j]);
		}
	}

	int n;
	scanf("%d", &n);

	int(*arr)[3] = malloc(sizeof(int[3]) * n);
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = (i + 1) * j;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}

		free(arr);
	}

	return 0;
}
#endif

// C���� �޸� �Ҵ��� �ϴ� 4���� ���
// 1) ���� ����
// - �ʱ�ȭ X: �����Ⱚ
// - �Լ��� ���۵� �� �����ǰ�, �Լ��� ������ ������ϴ�.

// 2) ���� ����
// - �ʱ�ȭ X: 0
// - ���α׷��� ������ �� �����ǰ�, ���α׷��� ����� �� ������ϴ�.

// 3) ���� ���� ����
// - �ʱ�ȭ X: 0
// - �Լ��� ���ʿ� ����Ǵ� ������ �ʱ�ȭ�ǰ�, ���α׷��� ����� �� ������ϴ�.

// 4) ���� �޸� �Ҵ�
// - �ʱ�ȭ X: �����Ⱚ
// - �����ڰ� ���ϴ� ������ �����ϰ�, �����ڰ� ���ϴ� ������ �ı��� �� �ֽ��ϴ�.

#if 0
int main(void) {
	int* p = malloc(sizeof(int));
	// malloc���� �Ҵ�� �޸��� �ʱⰪ�� ������ �����Դϴ�.
	// => �����Ⱚ

	printf("%d\n", *p);

	return 0;
}
#endif

// ����ڷκ��� n�� �Է� �޾Ƽ�, n��
// �� ������� 3������ �Է� �ް�, �Է� ���� �� ����� ������ �հ�� �����
// ����ϴ� ���α׷��� �ۼ��غ�����.

int main(void) {
	int n;
	scanf("%d", &n);

	int(*score)[3] = malloc(sizeof(int[3]) * n);
	if (score != NULL) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &score[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += score[i][j];
			}
			printf("\n[User %d]\n", i);
			printf("Sum: %d\n", sum);
			printf("Average: %0.2f\n", (float)sum / 3);
			printf("-------------\n");
		}

		free(score);
	}

	return 0;
}