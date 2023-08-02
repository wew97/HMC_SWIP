// 7_제어문4.c

#include <stdio.h>

// 구구단을 출력하고 싶습니다.
// 2단부터 9단까지
// 각각 1~9까지 곱하는 결과를 출력해야 한다.
// => 반복문을 중첩해서 문제를 해결할 수 있습니다.
// 1) 반복 횟수를 관리하는 변수가 2개 필요합니다.
//		i, j, k
// 2) 내부 반복문의 반복 횟수를 관리하는 변수는 외부 반복문이 반복될 때마다
//    다시 초기화되어야 합니다.


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

// 사각형 그리기
// i = 7회 반복
// j = 5회 반복

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

// goto는 일반적으로 사용하지 않는 것이 좋다.
// 코드의 흐름을 분석하기 어렵게 만든다.
// 제한적으로 사용할 경우, 유용하게 사용할 수 있다.

// 1) 중첩된 반복문의 탈출
//    : 반복문을 탈출 할 때, break를 사용하는 것이 원칙
//		중첩된 반복문을 탈출할 때, 제한적으로 goto를 통해
//		문제를 해결하는 것이 가능하다.

// 2) 오류 처리

// MISRA
// => 함수에서 return은 반드시 1개만 작성되어야 한다.

#if 0
int main(void) {
	int n;
	int x;

	// 스파게티 코드
	// => goto를 사용하지 말자!
	//    goto는 반드시 이후의 코드로만 점프를 수행해야 한다.

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