#include <wiringPi.h> 
#include <stdio.h> 
#include <sys/time.h>

// #include "lcd.h"

#define Trig 23 
#define Echo 24

#define LED 17

struct timeval tv1;
struct timeval tv2;
long time1;
long time2;

float measureDistance(void)
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

    return distance;
}

int main(void)
{
    float distance;

    struct timeval tv1;
    struct timeval tv2;

    wiringPiSetupGpio();

    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
    pinMode(LED, OUTPUT);

    while (1)
    {
        distance = measureDistance();
        printf("%0.2f cm\n", distance);

        if (distance < 10.0)
            digitalWrite(LED, 1);
        else
            digitalWrite(LED, 0);

        delay(1000);
    }

    return 0;
}