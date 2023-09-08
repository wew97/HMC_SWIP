// 15_���������4.c

#include <stdio.h>

// offset
// => ���� ����ü�� ������ ����ϰų� ���� ���� ��ġ�� �����մϴ�.
// ������ �����¿� ���õ� �Լ�
// 1) long ftell(FILE* stream)
//  : ���� ������ �������� ��ȯ�մϴ�.

// 2) int fseek(FILE* stream, long offset, int whence)
//   : ������ �������� ������ �� �ֽ��ϴ�.
//  whence: ����
//   SEEK_SET: ����
//   SEEK_CUR: ���� ��ġ
//   SEEK_END: ������

#if 0
int main(void) {
	FILE* fp = fopen("a.txt", "w+");
	printf("offset: %ld\n", ftell(fp)); // 0

	char str[32] = "GoodBye";
	fprintf(fp, "%s", str);
	printf("offset: %ld\n", ftell(fp)); // 7

	// fseek(fp, 0, SEEK_SET); // �������κ��� 0B
	fseek(fp, -3, SEEK_CUR);

	char buf[32] = "";
	fscanf(fp, "%s", buf);

	printf("read: %s\n", buf);

	fclose(fp);

	return 0;
}
#endif

// ftell�� ������ ũ�⸦ ���ϴ� �������� ����� �� �ֽ��ϴ�.
// => 1) fseek(fp, 0, SEEK_END);
//   : ������ ������ ��ġ�� �̵��մϴ�.
//    2) ftell(fp);
//     ������ ���� ������ - ������ ����� �˴ϴ�.

// int main(void)

// ��ɾ� ���ڸ� ���� ���� �� �ִ� main �����Դϴ�.
// argc: ���޵� ������ ����
// argv: ���޵� ���ڿ��� �迭
// [ char* ][ char* ][ char* ]

// int main(int argc, char* argv[])

// int main(int argc, char** argv)

// $ a.out a.txt
//    argc: 2
// argv[0]: "a.out"
// argv[1]: "a.txt"

int main(void)
{
    FILE* fp = fopen("a.out", "r");

    fseek(fp, 0, SEEK_END);
    printf("Size: %ld\n", ftell(fp));

    fclose(fp);

    return 0;
}