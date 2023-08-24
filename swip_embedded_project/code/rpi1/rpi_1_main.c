// rpi_1_main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <net/if.h>

#include <sys/ioctl.h>
#include <sys/socket.h>

#include "wiringPi.h"
#include "rpi_1_can.h"
#include "rpi_1_stub.h"
#include "rpi_1_led.h"
#include "rpi_1_ultrasonic.h"
#include "rpi_1_dijkstra.h"

#define SOURCE 3
#define DEST 6

int socketCANDescriptor;

int main(void)
{
    pthread_t threads[4];
    char quit_command[] = "quit\n";

    // wiringPiSetupGpio();
    printf("RPi #1 is ready.\n\n");

    // LED 쓰레드
    // pthread_create(&threads[0], NULL, led, NULL);
    printf("Started LED.\n\n");

    // dijkstra_start
    char buffer[MAX_NODES];
    int len;

    // buffer => path를 담고 있음 dest -> .. -> source 순서로
    findShortestPath(SOURCE, DEST, buffer, &len);

    char pathStr[128];
    int pathStrLen = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (i > 0) {
            sprintf(&pathStr[pathStrLen], "%c -> ", buffer[i]);
            pathStrLen += sizeof(buffer[i]) + 4;
        } else {
            sprintf(&pathStr[pathStrLen], "%c.\n", buffer[i]);
        }
    }

    printf("The shortest path is %s\n", pathStr);

    // 초음파 쓰레드
    pthread_create(&threads[1], NULL, ultrasonic, NULL);
    printf("Started Ultrasonic sensor.\n\n");

    // Create CAN socket
    socketCANDescriptor = setupCANSocket("can0");
    if (socketCANDescriptor < 0)
    {
        return -1;
    }

    moveMotor(120);
    moveMotor(12);
    // displayText(0, (const char*)buffer);
    while(1)
    {
        char inputString[128];
        printf("Enter your text to display on RPi #2's LCD: ");
        fgets(inputString, 128, stdin);

        if ((strcmp(inputString, quit_command) == 0) && (strlen(inputString) == 5)){
            terminateRPC(quit_command);
            break;
        }else{
            displayText(0, (const char*)inputString);
            // displayText(1, (const char*)inputString);
            // terminateRPC("quit");
        }
    }

    closeCANSocket(socketCANDescriptor);

    return 0;
}