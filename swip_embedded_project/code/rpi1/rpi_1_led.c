// rpi_1_led.c

#include <stdio.h>
#include "wiringPi.h"
#include "rpi_1_led.h"

#define LED_GPIO 17

int led_status = 0;

// status = 0: default
// status = 1: 20cm이내
void *led(void *argumentPointer)
{
    pinMode(LED_GPIO, OUTPUT);

    int delay_ms = 1000; // default
    while (1)
    {
        delay_ms = led_status == 0 ? 1000 : 100;

        digitalWrite(LED_GPIO, HIGH);
        delay(delay_ms);
        digitalWrite(LED_GPIO, LOW);
        delay(delay_ms);
    }
}