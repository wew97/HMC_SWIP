#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define PIN 18
#define PWM_RANGE 200
#define MIN_DEGREE 0
#define MAX_DEGREE 180
#define MIN_DUTY_CYCLE 5
#define MAX_DUTY_CYCLE 10

void moveMotor(int degree)
{
    if (degree < MIN_DEGREE) degree = MIN_DEGREE;
    if (degree > MAX_DEGREE) degree = MAX_DEGREE;

    float dutyCycle = MIN_DUTY_CYCLE + (degree - MIN_DEGREE) * (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE) / (MAX_DEGREE - MIN_DEGREE);
    int pulseWidth = dutyCycle * (PWM_RANGE / 100);

    printf("dutyCycle = %.2f%%\n", dutyCycle);
    printf("pulseWidth = %d\n", pulseWidth);

    softPwmWrite(PIN, pulseWidth);
}

int main() 
{
    int inputValue;         // the unit is degree
    
    wiringPiSetupGpio();
    pinMode(PIN, OUTPUT);

    // Set PWM range (= the total number of clock ticks during a period)
    softPwmCreate(PIN, 0, PWM_RANGE);

    while(1) 
    {     
        printf("Enter the position of motor (in degree): ");
        scanf("%d", &inputValue);
        
        moveMotor(inputValue);
        
        delay(600);
    }

    return 0;
}
