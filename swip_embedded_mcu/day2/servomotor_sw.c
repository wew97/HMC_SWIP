#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define PIN 18
#define PWM_RANGE 200

void moveMotor(int degree)
{
    if (degree < 0) {
        degree = 0;
    } else if (degree > 180) {
        degree = 180;
    }

    float dutyCycle = 5.0 + (degree / 18.0); // Calculate duty cycle based on degree

    // Calculate pulse width based on duty cycle and PWM range
    int pulseWidth = (int)(dutyCycle * (PWM_RANGE / 100.0));

    softPwmWrite(PIN, pulseWidth); // Set the pulse width
}

int main()
{
    int inputValue;

    wiringPiSetupGpio();
    pinMode(PIN, OUTPUT);

    softPwmCreate(PIN, 0, PWM_RANGE);

    while (1)
    {
        printf("Enter the position of motor (in degree): ");
        scanf("%d", &inputValue);

        moveMotor(inputValue);

        delay(400);
    }

    return 0;
}
