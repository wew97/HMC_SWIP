#include <stdio.h>

int getNthBitFromLSB(int number, int nthBit) {
    return (number >> nthBit) & 1;
}

void setNthBitFromLSB(int* number, int nthBit) {
    *number |= (1 << nthBit);
}

void clearNthBitFromLSB(int* number, int nthBit) {
    *number &= ~(1 << nthBit);
}

int countOne(int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

void printBinary(int number, int nbitsToPrint) {
    for (int i = nbitsToPrint - 1; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
    printf("\n");
}

int main() {
    int value, nthBit;

    printf("Enter an int number: ");
    scanf("%d", &value);

    printf("Binary representation: ");
    printBinary(value, sizeof(value) * 8);

    int onesCount = countOne(value);
    printf("Number of '1' in the value: %d\n", onesCount);

    printf("Enter the nth bit (0 to 31): ");
    scanf("%d", &nthBit);

    setNthBitFromLSB(&value, nthBit);
    printf("After setting %dth bit: %d\n", nthBit, value);
    printf("Binary representation: ");
    printBinary(value, sizeof(value) * 8);
    printf("The %dth bit is %d\n", nthBit, getNthBitFromLSB(value, nthBit));

    clearNthBitFromLSB(&value, nthBit);
    printf("After clearing %dth bit: %d\n", nthBit, value);
    printf("Binary representation: ");
    printBinary(value, sizeof(value) * 8);
    printf("The %dth bit is %d\n", nthBit, getNthBitFromLSB(value, nthBit));

    return 0;
}
