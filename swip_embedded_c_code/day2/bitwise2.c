#include <stdio.h>

#define BIT_MAX 32

int getNthBitFromLSB(int number, int nthBit);
void setNthBitFromLSB(int *number, int nthBit);
void clearNthBitFromLSB(int *number, int nthBit);
int countOne(int number);
void printBinary(int number, int nbitsToPrint);

int main(int argc, char *argv[])
{
    int num = 0;
    int pos = 0;
    printf("Enter an int number: ");
    scanf("%d", &num);

    printBinary(num, BIT_MAX);

    printf("The number of '1's is %d\n\n", countOne(num));

    printf("Enter a bit position to experiment with (from LSB): ");
    scanf("%d", &pos);

    setNthBitFromLSB(&num, pos); /* 입력받은 위치의 bit를 '1'로 바꿈 */

    printf("After setting %dth bit: ", pos);
    printBinary(num, BIT_MAX);

    printf("The %dth bit is %d\n", pos, getNthBitFromLSB(num, pos));

    clearNthBitFromLSB(&num, pos); /* 입력받은 위치의 bit를 '0'으로 바꿈 */

    printf("After clearing %dth bit: ", pos);
    printBinary(num, BIT_MAX);

    printf("The %dth bit is %d\n", pos, getNthBitFromLSB(num, pos));

    return 0;
}

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
    printf("%d (in decimal)  ", number);

    int cnt = 0;
    for (int i = nbitsToPrint - 1; i >= 0; i--) {
        if((cnt++)%4 == 0){
            printf(" ");
        }
        int bit = getNthBitFromLSB(number, i);
        printf("%d", bit);
    }
    printf(" (in binary)\n");
}