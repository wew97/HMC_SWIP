// 2_����.c

#include <stdio.h>
#include <stdlib.h> //malloc

// ������ ���� (��� �η�, Storage Class)
// : ������ ���̰� ����.

// 1) ���� ����
// - �Լ��� �����Ҷ� �����ǰ�,
//   �Լ��� ������ �����.
 
// 2) ���� ����
// - ���α׷��� ������ �� �ʱ�ȭ�ǰ�,
//    ���α׷��� ���� ������ ����
 
// 3) ���� ���� ���� (���� ���� ����)
// - �Լ��� ���ʿ� ����Ǵ� ������ �ʱ�ȭ�ǰ�,
//   ���α׷��� ���� ������ ����
  
// 4) malloc => �� ����
// - ���α׷��Ӱ� ���ϴ� ������ �Ҵ�ǰ�,
//   ���α׷��Ӱ� ���ϴ� ������ �ı��� �� ����.

int global = 100;

int main(void) {
	
	printf("global: %p\n", &global);

	int local = 42; // ���� ����
	printf("local: %p\n", &local);

	static int slocal = 200; // ���� ���� ����
	printf("slocal: %p\n", &local);

	int* p = malloc(sizeof(int)); // �� ����
	printf("malloc: %p\n", p);

	return 0;
}