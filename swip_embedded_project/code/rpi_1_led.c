#include <stdio.h>
#include "wiringPi.h"
#include "rpi_1_led.h"
#define GPIO 17

int led_status = 0;
// status = 0: default
// status = 1: 20cm이내
void *led(void *argumentPointer){

    while(1){
        if (led_status == 0){
            digitalWrite(GPIO, HIGH);
            delay(1000);
            digitalWrite(GPIO, LOW);
            delay(1000); 
        }else{
            for (int i = 0; i < 10; i++){
                digitalWrite(GPIO, HIGH);
                delay(100);
                digitalWrite(GPIO, LOW); 
            }
        }
    }

}