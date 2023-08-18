#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

#define PIN 18
#define PWM_CLOCK_DIVISOR 384   // This will generate 50,000 Hz from 19.2 MHz clock source
#define PWM_RANGE 1024          // The total number of clock ticks during a period
                                // This is equivalent to a period of 20 ms

void moveMotor(int degree)
{
    float dutyCycle;        // the unit is %
    int pulseWidth;         

    if (degree < 0) {
        degree = 0;
    } else if (degree > 180) {
        degree = 180;
    }

    // Calculate duty cycle and pulse width
    dutyCycle = ((float)degree / 18.0) + 5.0;
    pulseWidth = (int)(((float)PWM_RANGE * dutyCycle) / 100.0);

    pwmWrite(PIN, pulseWidth);
}

int main(void) 
{
    int inputValue;

    wiringPiSetupGpio();

    // Initialize PWM
    pinMode(PIN, PWM_OUTPUT);  // Set the pin as PWM output
    pwmSetMode(PWM_MODE_MS);   // Use mark-space mode
    pwmSetClock(PWM_CLOCK_DIVISOR);
    pwmSetRange(PWM_RANGE);
    while(1) 
    {
        printf("Enter value (0-180): ");
        scanf("%d", &inputValue);
        
        moveMotor(inputValue);
        
        delay(80);
    }    
    
    return 0;
}
