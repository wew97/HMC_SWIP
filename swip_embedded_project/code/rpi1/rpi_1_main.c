// rpi_1_main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <net/if.h>

#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "wiringPi.h"
#include "rpi_1_can.h"
#include "rpi_1_stub.h"
#include "rpi_1_led.h"
#include "rpi_1_ultrasonic.h"
#include "rpi_1_dijkstra.h"

#define NUM_MAX 100000
#define SOURCE 3
#define DEST 6

int socketCANDescriptor;

int main(void)
{
    pthread_t threads[4];
    char path[NUM_MAX];
    char inputString[128];
    char quit_command[] = "quit\n";

    wiringPiSetupGpio();
    printf("RPi #1 is ready.\n\n");

    // LED 쓰레드
    pthread_create(&threads[0], NULL, led, NULL);

    // dijkstra_start
    char buffer[MAX_NODES];
    int len = 0;

    // buffer => path를 담고 있음 dest -> .. -> source 순서로
    findShortestPath(SOURCE, DEST, buffer, &len);

    printf("The shortest path is ");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", buffer[i]);

        if (i > 0)
        {
            printf(" -> ");
        }
        else
        {
            printf("\n\n");
        }
    }


    // 초음파 쓰레드
    pthread_create(&threads[1], NULL, ultrasonic, NULL);

    // moveMotor()
    // displayText()

    // 원격 LCD 출력
    socketCANDescriptor = setupCANSocket("can0");
    if (socketCANDescriptor < 0)
    {
        return -1;
    }

    // processCANFrames(socketCANDescriptor);

    while(1) {                
        printf("Enter your text to display on RPi #2's LCD: ");
        fgets(inputString, 128, stdin);

        displayText(0, (const char*)inputString);

        // if (strncmp(inputString, quit_command, frame.can_dlc) == 0 && frame.can_dlc == strlen(quit_command)){
        //     printf("\nTerminating RPi #1.\n");
        //     break;
        // }
    }

    closeCANSocket(socketCANDescriptor);

    return 0;
}