#include <stdio.h>
#include "stub.h"

int main(void)
{
    char inputString[128];

    while(1)
    {
        printf("Enter your text to display on RPi #2's LCD: ");
        fgets(inputString, 128, stdin);

        displayText(0, (const char*)inputString);
    }

    return 0;
}