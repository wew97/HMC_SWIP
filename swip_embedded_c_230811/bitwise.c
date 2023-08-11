#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BIT_MAX 32

void decToBin(int number, int *arr);
void printBinary(int number, int nbitsToPrint);
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

    int decToBin[BIT_MAX] = {
        0,
    };

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

void decToBin(int number, int *arr)
{
    int i = 0;
    while (number > 0)
    {
        arr[i] = number % 2;
        number = number / 2;
        i++;
    }
}

int getNthBitFromLSB(int number, int nthBit)
{
    int arrBin[BIT_MAX] = {
        0,
    };
    decToBin(number, arrBin);

    return arrBin[nthBit];
}

void setNthBitFromLSB(int *number, int nthBit)
{
    int arrBin[BIT_MAX] = {
        0,
    };
    decToBin(*number, arrBin);

    arrBin[nthBit] = 1;

    int result = 0;

    for (int i = 0; i < BIT_MAX; i++)
    {
        if (arrBin[i] == 1)
        {
            result += pow(2, i);
        }
    }
    *number = result;
}

void clearNthBitFromLSB(int *number, int nthBit)
{
    int arrBin[BIT_MAX] = {
        0,
    };
    decToBin(*number, arrBin);

    arrBin[nthBit] = 0;

    int result = 0;

    for (int i = 0; i < BIT_MAX; i++)
    {
        if (arrBin[i] == 1)
        {
            result += pow(2, i);
        }
    }
    *number = result;
}

int countOne(int number)
{
    int arrBin[BIT_MAX] = {
        0,
    };
    decToBin(number, arrBin);

    int cnt = 0;
    for (int i = 0; i < BIT_MAX; i++)
    {
        if (arrBin[i] == 1)
        {
            cnt++;
        }
    }

    return cnt;
}

void printBinary(int number, int nbitsToPrint)
{
    int arrBin[BIT_MAX] = {
        0,
    };

    printf("%d (in decimal)  ", number);

    decToBin(number, arrBin);

    int cnt = 0;
    for (int j = BIT_MAX - 1; j >= 0; j--)
    {
        if ((cnt++) % 4 == 0)
        {
            printf(" ");
        }
        printf("%d", arrBin[j]);
    }
    printf(" (in binary)\n");
}