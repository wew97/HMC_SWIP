#include <stdio.h>
#include <stdlib.h>
#include "bitwise_manipulation.h"


void breakdownFloatIntoIEEE754(float number)
{
    int k;

    typedef union {
        float f;
        unsigned u;
        struct {
            unsigned mantissa : 23;
            unsigned exponent : 8;
            unsigned sign: 1;
        } raw;
    } ufloat;

    ufloat value;
    value.f = number;
   
    printf("Breakdown of %f:\t", number);
    printf("%d\t", value.raw.sign);
    printBinary(value.raw.exponent, 8);
    printf("\t");
    printBinary(value.raw.mantissa, 23);
    printf("\n");
    printf("\nSign: %d\n", value.raw.sign);
    printf("Exponent: ");
    printBinary(value.raw.exponent, 8);
    printf("\nMantissa: ");
    printBinary(value.raw.mantissa, 23);
    printf("\n\n");
}

int main()
{
    float floatNumber;

    // We are going to process a float number
    printf("Enter a float number: ");    
    scanf("%f", &floatNumber);
    
    breakdownFloatIntoIEEE754(floatNumber);

    return 0;
}
