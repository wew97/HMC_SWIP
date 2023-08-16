#include <stdio.h>
#include "wiringPi.h"

#define GPIO_LED 17
#define GPIO_SWITCH 13

// #define HIGH 1       // defined in "wiringPi.h"
// #define LOW 0        // defined in "wiringPi.h"

int ledState = LOW;

void toggle(void)
{
    if (ledState == LOW)
    {
        digitalWrite(GPIO_LED, HIGH);
        ledState = HIGH;
        printf("LED On\n");
    }
    else
    {
        digitalWrite(GPIO_LED, LOW);
        ledState = LOW;
        printf("LED Off\n");
    }
}

int main(void)
{
    wiringPiSetupGpio();
    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);
    wiringPiISR(GPIO_SWITCH, INT_EDGE_RISING, toggle);
    while (1)
        ;

    return 0;
}
