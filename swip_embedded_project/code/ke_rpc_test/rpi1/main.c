#include <stdio.h>
#include "rpi_1_stub.h"

int socketCANDescriptor;

int main(void)
{
    char inputString[128];

    while(1)
    {
        printf("Enter your text to display on RPi #2's LCD: ");
        fgets(inputString, 128, stdin);

        displayText(0, (const char*)inputString);
        displayText(1, (const char*)inputString);
        moveMotor(25);
        terminateRPC("quit");
    }

    return 0;
}