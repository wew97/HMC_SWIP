// 8_¹è¿­3.c
#include <stdio.h>

int main(void)
{
    // int a[2][3] = { 1, 2, 3, 4, 5, 6 }; // OK!

    // [ int[3] ][ int[3] ]
    int a[2][3] = { { 1 }, { 4, 5, 6 } };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n", a[i][j]);
        }
    }

    return 0;
}