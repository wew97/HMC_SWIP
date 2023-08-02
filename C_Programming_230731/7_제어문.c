// 7_���.c

#include <stdio.h>

// 1. C���� �ۼ��� ��� ���α׷��� main �Լ��� ù ��° �������
//    ���������� ����ȴ�.

// 2. ���� �帧�� �����ϰ� ���� ��, ����ϴ� ������
//    ���(Control Statement)�̶�� �մϴ�.

// 3. ��� ����
//  - ���ǹ� (Conditional Statement)
//    : ������ ������ �� ����Ǵ� ������ �����Ѵ�.
//    if / if - else / if - else if - else
//    switch

//  - �ݺ���(Iterative Statement)
//    : ������ �����ϸ�, �ݺ��ؼ� �����ϴ� ������ �����Ѵ�.
//    while / for / do-while

// ���ǹ�
// 1) if
/*
if (���ǽ�) {
		statement1;
		statement2;
		...
}
*/

// ����ڷκ��� ���̸� �Է� �޾Ƽ�, 18�� �̻��̸�
// "�����Դϴ�." �� ����ϴ� ���α׷��� �ۼ��غ��ô�.

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	if (age >= 18) {
		printf("�����Դϴ�.\n");
	}
	// ���ǹ��̳� �ݺ������� ������ 1���� �����ϴ� ���,
	// ����� ������ �� ����.
	// => ������ �Ǽ��� �����ϱ� ���ؼ�,
	//    �ݵ�� ����� ����ؾ� �Ѵ�.

	return 0;
}
#endif

// 18�� �̻��� ��� "�����Դϴ�."�� ����ϰ�,
// 18�� �̸��� ��� "������ �ƴմϴ�."�� ����ϴ� ���α׷��� �ۼ��غ��ô�.

/*
if (���ǽ�){
	// ���ǽ��� ���� ��� ����Ǵ� ������ ����
} else{
	// ���ǽ��� ������ ��� ����Ǵ� ������ ����
}
*/

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	if (age >= 18) {
		printf("�����Դϴ�.\n");
	}
	else {
		printf("������ �ƴմϴ�.\n");
	}

	return 0;
}
#endif

// +) 18�� �̸��� ���,
//    8�� �̸��̸� "������ �Ƶ��Դϴ�."
//    8�� �̻��̸� "�л��Դϴ�."

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	// ���ǹ� �ȿ� ���ǹ��� �ۼ��� �� �ֽ��ϴ�.
	if (age >= 18) {
		printf("�����Դϴ�.\n");
	}
	else {
		// age�� 18�� �̸��Դϴ�.
		
		if (age < 8) {
			printf("������ �Ƶ��Դϴ�.\n");
		}
		else {
			printf("�л��Դϴ�.\n");
		}
	}
	

	return 0;
}
#endif

// ������ �ݺ��� ���
// ��ø�� ���ǹ����� if - else if - else ������ ����ϴ� ���� ����.

#if 0
int main(void) {
	int age;
	scanf_s("%d", &age);

	if (age >= 18) {
		printf("�����Դϴ�.\n");
	}
	else if (age < 8) {
		printf("������ �Ƶ��Դϴ�.\n");
	}
	else {
		printf("�л��Դϴ�.\n");
	}

	return 0;
}
#endif
// MISRA C 2008
//-----------
//       C 2012 - C99 - *
//       C 2023 - C11

// MISRA
// => if, else-if ��������
//    �ݵ�� else�� �ۼ��ؾ� �մϴ�.
int main(void)
{
	int age;
	scanf("%d", &age);

	// 1��
	char grade;
	if (age >= 18) {
		grade = 'A';
	}
	else if (age < 8) {
		grade = 'B';
	}
	else {
		grade = 'C';
	}

	// 2��
	// => else-if�� ����� ��, else���� �ƹ��͵� �������� �ʴ���
	//    �ݵ�� else ������ �ۼ��ؾ� �մϴ�.
	grade = 'C';
	if (age >= 18) {
		grade = 'A';
	}
	else if (age < 8) {
		grade = 'B';
	}
	else {
		/* Nothing */;
	}

	// char: ���ڸ� ����� ���� %c�� ����ϸ� �˴ϴ�.
	printf("grade: %c\n", grade);

	return 0;
}