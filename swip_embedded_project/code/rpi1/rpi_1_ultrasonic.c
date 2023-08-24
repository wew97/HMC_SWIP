// rpi_1_ultrasonic.c

#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>
#include "rpi_1_ultrasonic.h"

#define Trig 23
#define Echo 24

extern int led_status;

void measureDistance(void)
{
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);

    struct timeval startTime, stopTime;
    long startMicros, stopMicros;
    float distance;

    // echo가 high가 될 때까지 대기
    while (digitalRead(Echo) == LOW)
        ;

    gettimeofday(&startTime, NULL);
    startMicros = startTime.tv_sec * 1000000 + startTime.tv_usec;

    // echo가 low가 될 때까지 대기
    while (digitalRead(Echo) == HIGH)
        ;

    gettimeofday(&stopTime, NULL);
    stopMicros = stopTime.tv_sec * 1000000 + stopTime.tv_usec;

    long elapsedMicros = stopMicros - startMicros;
    // 음파의 속도는 초당 약 343m 이므로, 실제 거리는 음파 시간 / 2 * 음파 속도
    distance = (elapsedMicros * 0.0343) / 2;

    if (distance < 20.0)
        led_status = 1;
    else
        led_status = 0;
}

void *ultrasonic(void *argumentPointer)
{
    float distance;

    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);

    while (1)
    {
        measureDistance();
        delay(100);
    }

    return 0;
}