#include <stdio.h>
#include "wiringPi.h"

# define GPIO 17

int main(void){
    wiringPiSetupGpio();
    pinMode(GPIO, OUTPUT);

    while(1){
        digitalWrite(GPIO, 1);
        delay(1000);
        digitalWrite(GPIO, 0);
        delay(1000);
    }

    return 0;
}