#include <stdio.h>
#include "wiringPi.h"

#define GPIO_LED 17
#define GPIO_SWITCH 13

// #define HIGH 1       // defined in "wiringPi.h"
// #define LOW 0        // defined in "wiringPi.h"

int main(void)
{
    int switchState;
    int ledState = LOW;

    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);

    while (1)
    {
        switchState = digitalRead(GPIO_SWITCH);
        if (switchState == HIGH) 
        {
            if(ledState == LOW) 
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

        delay(100);
    }

    return 0;
}
