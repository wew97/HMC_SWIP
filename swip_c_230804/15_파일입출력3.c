// 15_���������3.c

#include <stdio.h>

// - fopen / fclose

int main(void) {
	FILE* fp = fopen("a.txt", "r");
	if (fp != NULL) {

		fclose(fp);
	}

	return 0;
}