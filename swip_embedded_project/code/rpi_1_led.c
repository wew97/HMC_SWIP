#include <stdio.h>
#include "wiringPi.h"
#define LED_GPIO 17

int led_status = 0;
// status = 0: default
// status = 1: 20cm이내
void *led(void *argumentPointer){
    printf("Started LED.\n");
    pinMode(LED_GPIO, OUTPUT);
    while(1){
        if (led_status == 0){
            digitalWrite(LED_GPIO, HIGH);
            delay(1000);
            digitalWrite(LED_GPIO, LOW);
            delay(1000); 
        }else{
            digitalWrite(LED_GPIO, HIGH);
            delay(100);
            digitalWrite(LED_GPIO, LOW);
            delay(100);
        }
    }

}