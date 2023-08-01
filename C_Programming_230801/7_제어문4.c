// 7_���4.c

#include <stdio.h>

// �������� ����ϰ� �ͽ��ϴ�.
// 2�ܺ��� 9�ܱ���
// ���� 1~9���� ���ϴ� ����� ����ؾ� �Ѵ�.
// => �ݺ����� ��ø�ؼ� ������ �ذ��� �� �ֽ��ϴ�.
// 1) �ݺ� Ƚ���� �����ϴ� ������ 2�� �ʿ��մϴ�.
//		i, j, k
// 2) ���� �ݺ����� �ݺ� Ƚ���� �����ϴ� ������ �ܺ� �ݺ����� �ݺ��� ������
//    �ٽ� �ʱ�ȭ�Ǿ�� �մϴ�.


#if 0
int main(void) {
	int i;
	int j;

	i = 2;
	while (i <= 9) {
		j = 1;
		while (j <= 9) {
			printf("%d * %d = %d\n", i, j, i * j);

			j++;
		}

		printf("------------\n");
		i++;
	}

	return 0;
}
#endif

// �簢�� �׸���
// i = 7ȸ �ݺ�
// j = 5ȸ �ݺ�

// *****
// *****
// *****
// *****
// *****
// *****
// *****

#if 0
int main(void) {
	int i;
	int j;

	i = 0;
	while (i < 10) {
		j = 0;
		while (j < i + 1) {
			printf("*");
			j++;
		}
		i++;
		printf("\n");
	}

}
/*
*
**
***
****
*****
******
*******
********
*********
**********
*/
#endif

#if 0
int main(void) {
	int i;
	int j;

	i = 0;
	while (i < 11) {

		j = 0;
		if (i < 6) {
			while (j < i + 1) {
				printf("*");
				j++;
			}
		}
		else {
			while (j < 11 - i) {
				printf("*");
				j++;
			}
		}
		i++;
		printf("\n");
	}

}

/*
*
**
***
****
*****
******
*****
****
***
**
*
*/
#endif

#if 0
int main(void) {
	int i;
	int j;
	int flag = 0;

	i = 0;
	while (i < 5) {
		j = 0;
		while (j < 10) {
			if (i + j == 10) {
				printf("----------\n");
				flag = 1;
				break;
			}

			printf("%d + %d = %d\n", i, j, i + j);

			j++;
		}

		if (flag) {
			break; // !!!!
		}

		i++;
	}

	return 0;
}
#endif

// goto�� �Ϲ������� ������� �ʴ� ���� ����.
// �ڵ��� �帧�� �м��ϱ� ��ư� �����.
// ���������� ����� ���, �����ϰ� ����� �� �ִ�.

// 1) ��ø�� �ݺ����� Ż��
//    : �ݺ����� Ż�� �� ��, break�� ����ϴ� ���� ��Ģ
//		��ø�� �ݺ����� Ż���� ��, ���������� goto�� ����
//		������ �ذ��ϴ� ���� �����ϴ�.

// 2) ���� ó��

// MISRA
// => �Լ����� return�� �ݵ�� 1���� �ۼ��Ǿ�� �Ѵ�.

#if 0
int main(void) {
	int n;
	int x;

	// ���İ�Ƽ �ڵ�
	// => goto�� ������� ����!
	//    goto�� �ݵ�� ������ �ڵ�θ� ������ �����ؾ� �Ѵ�.

	again:

	scanf("%d", &n);

	if (n < 0) {
		goto error; /* Okay! */
	}

	while (n--) {
		printf("hello\n");
	}

	scanf("%d", &x);
	if (x == 0) {
		goto again; /* No! */
	}

	error:

	return 0;
}
#endif

int main(void) {
	int n;

	scanf("%d", &n);

	if (n < 0) {
		goto error;
	}

	while (n--) {
		printf("hello\n");
	}

error:

	return 0;
}