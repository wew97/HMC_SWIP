// rpi_2_motor.c

#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

#include "rpi_2_motor.h"

#define MOTOR_GPIO 18
#define PWM_CLOCK_DIVISOR 384 // This will generate 50,000 Hz from 19.2 MHz clock source
#define PWM_RANGE 1024        // The total number of clock ticks during a period
                              // This is equivalent to a period of 20 ms

void moveMotor(int inputValue)
{
    pinMode(MOTOR_GPIO, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(PWM_CLOCK_DIVISOR);
    pwmSetRange(PWM_RANGE);

    float dutyCycle; // the unit is %
    int pulseWidth;

    dutyCycle = 2 + (inputValue / 180.0) * 10;
    pulseWidth = PWM_RANGE * (dutyCycle / 100.0);

    pwmWrite(MOTOR_GPIO, pulseWidth);

    return;
}