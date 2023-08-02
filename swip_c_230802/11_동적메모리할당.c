// 11_동적메모리할당.c

#include <stdio.h>
#include <stdlib.h> // malloc

// 1. 배열의 크기는 컴파일 타임에 결정되어야 합니다.
// 2. 실행 시간에 할당하는 메모리 크기를 결정하고 싶습니다.
//  => 동적 메모리 할당
//     void *malloc( size_t size );	

// 3. 메모리 할당을 수행하고, 더 이상 수행하지 않을 경우
//    반납해야 합니다.
//  => void free( void *ptr );

// 4. 동적 메모리 할당 문제점
//  1) 메모리 누수의 위험성
//     : free를 사용하지 않는 경우, 메모리가 누수되고, 가용되는 메모리가 없을
//       경우 프로그램은 미정의 동작을 수행할 수 있습니다.
//  2) 할당과 해지의 오베히드가 있습니다.
//  3) malloc은 실패 가능한 함수입니다.
//     메모리 할당에 실패하였을 경우, NULL을 반환합니다.

// => 동적 메모리 할당을 통해서 개발자가 원하는 시점에 메모리를 할당하고
//    개발자가 원하는 시점에 메모리를 해지할 수 있습니다.

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

	int* arr = malloc(sizeof(int) * n); // 1차원 배열
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

// C언어에서 메모리 할당을 하는 4가지 방법
// 1) 지역 변수
// - 초기화 X: 쓰레기값
// - 함수가 시작될 때 생성되고, 함수가 끝나면 사라집니다.

// 2) 전역 변수
// - 초기화 X: 0
// - 프로그램이 시작할 때 생성되고, 프로그램이 종료될 때 사라집니다.

// 3) 정적 지역 변수
// - 초기화 X: 0
// - 함수가 최초에 수행되는 시점에 초기화되고, 프로그램이 종료될 때 사라집니다.

// 4) 동적 메모리 할당
// - 초기화 X: 쓰레기값
// - 개발자가 원하는 시점에 생성하고, 개발자가 원하는 시점에 파괴할 수 있습니다.

#if 0
int main(void) {
	int* p = malloc(sizeof(int));
	// malloc으로 할당된 메모리의 초기값은 미지정 사항입니다.
	// => 쓰레기값

	printf("%d\n", *p);

	return 0;
}
#endif

// 사용자로부터 n을 입력 받아서, n명
// 각 사람마다 3과목을 입력 받고, 입력 받은 각 사람의 점수의 합계와 평균을
// 출력하는 프로그램을 작성해보세요.

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