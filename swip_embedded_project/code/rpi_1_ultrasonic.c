// distance를 return 하는게 아니라 전역 변수 led_status를 바꿔야할듯
#include <wiringPi.h> 
#include <stdio.h> 
#include <sys/time.h>

#define Trig 23 
#define Echo 24

#define LED 17

// struct timeval tv1;
// struct timeval tv2;
// long time1;
// long time2;
extern int led_status;

// float measureDistance(void)
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

    // return distance;
    if (distance < 20.0)
        led_status = 1;
    else
        led_status = 0;
}

void *ultrasonic(void *argumentPointer)
{
    float distance;

    // struct timeval tv1;
    // struct timeval tv2;

    printf("Started Ultrasonic sensor.\n");

    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
    pinMode(LED, OUTPUT);

    while (1)
    {
        measureDistance();
        // distance = measureDistance();
        // printf("%0.2f cm\n", distance);

        delay(100);
    }

    return 0;
}