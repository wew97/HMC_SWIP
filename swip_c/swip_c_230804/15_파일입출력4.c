// 15_파일입출력4.c

#include <stdio.h>

// offset
// => 파일 구조체가 파일을 기록하거나 읽을 때의 위치를 관리합니다.
// 파일의 오프셋에 관련된 함수
// 1) long ftell(FILE* stream)
//  : 현재 파일의 오프셋을 반환합니다.

// 2) int fseek(FILE* stream, long offset, int whence)
//   : 파일의 오프셋을 변경할 수 있습니다.
//  whence: 기준
//   SEEK_SET: 시작
//   SEEK_CUR: 현재 위치
//   SEEK_END: 마지막

#if 0
int main(void) {
	FILE* fp = fopen("a.txt", "w+");
	printf("offset: %ld\n", ftell(fp)); // 0

	char str[32] = "GoodBye";
	fprintf(fp, "%s", str);
	printf("offset: %ld\n", ftell(fp)); // 7

	// fseek(fp, 0, SEEK_SET); // 시작으로부터 0B
	fseek(fp, -3, SEEK_CUR);

	char buf[32] = "";
	fscanf(fp, "%s", buf);

	printf("read: %s\n", buf);

	fclose(fp);

	return 0;
}
#endif

// ftell을 파일의 크기를 구하는 목적으로 사용할 수 있습니다.
// => 1) fseek(fp, 0, SEEK_END);
//   : 파일의 마지막 위치로 이동합니다.
//    2) ftell(fp);
//     파일의 현재 오프셋 - 파일의 사이즈가 됩니다.

// int main(void)

// 명령어 인자를 전달 받을 수 있는 main 형태입니다.
// argc: 전달된 인자의 개수
// argv: 전달된 문자열의 배열
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