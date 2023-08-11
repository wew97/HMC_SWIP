#include <stdio.h>
#include "./printBinary.h"

void printBinary(int number, int nbitsToPrint) {
    for (int i = nbitsToPrint - 1; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
    printf("\n");
}