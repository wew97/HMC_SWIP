#include <stdio.h>
#include "printBinary.h"
#include <stdint.h>

typedef union {
    float f;
    unsigned u;
    struct {
        unsigned mantissa : 23;
        unsigned exponent : 8;
        unsigned sign : 1;
    } raw;
} ufloat;

int main() {
    ufloat num;

    printf("Enter a floating-point number: ");
    scanf("%f", &num.f);

    printf("Sign: %d\n", num.raw.sign);
    printf("Exponent: ");
    printBinary(num.raw.exponent, 8);
    printf("Mantissa: ");
    printBinary(num.raw.mantissa, 23);

    return 0;
}
