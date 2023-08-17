# SW Intensive Program ('23/07/31 - '23/10/20)
<br>

## C Programming ('23/07/31 - '23/08/04)
- [시작/변수/const/typedef/연산자/scanf/제어문 (Day 1)](https://github.com/wew97/HMC_SWIP/tree/main/swip_c_230731)

- [제어문/배열/함수 (Day 2)](https://github.com/wew97/HMC_SWIP/tree/main/swip_c_230801)

- [포인터/동적메모리할당/문자열 (Day 3)](https://github.com/wew97/HMC_SWIP/tree/main/swip_c_230802)

- [사용자정의타입 (Day 4)](https://github.com/wew97/HMC_SWIP/tree/main/swip_c_230803)

- [전처리기/파일입출력 (Day 5)](https://github.com/wew97/HMC_SWIP/tree/main/swip_c_230804)

## Embedded System C Programming ('23/08/10 ~ '23/08/14)
- [실습 링크(Google Drive)](https://drive.google.com/drive/folders/1hSKt0XnoClkn1umUGRXyY4-6QL13OZPz?usp=sharing)
- [Code](https://github.com/wew97/HMC_SWIP/tree/main/swip_embedded_c)

## Embedded System MCU Programming ('23/08/16 ~ '23/08/21)
- [실습 링크(Google Drive)](https://drive.google.com/drive/folders/1hSKt0XnoClkn1umUGRXyY4-6QL13OZPz?usp=sharing)


- [Code](https://github.com/wew97/HMC_SWIP/tree/main/swip_embedded_mcu)

## skribbl 주소 (08/17 10:12 updated)
https://skribbl.io/?DLC7Aput

## 주식 공부
https://modu-stock.tistory.com/33

'''C
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
    while (digitalRead(Echo) == LOW);

    gettimeofday(&startTime, NULL);
    startMicros = startTime.tv_sec * 1000000 + startTime.tv_usec;

    // echo가 low가 될 때까지 대기
    while (digitalRead(Echo) == HIGH);

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
'''
