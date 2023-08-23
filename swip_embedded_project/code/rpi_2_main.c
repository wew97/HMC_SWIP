// rpi_2_main.c
// main.c

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
#include "rpi_2_can.h" // Include the header for can.c functions

#define NUM_MAX 100000

int main(void) {
    pthread_t threads[4];
    char path[NUM_MAX];
    char inputString[128];
    struct can_frame frame;
    int socketCANDescriptor;
    char quit_command[] = "quit\n";
    char receiveMessage[8];
    int nbytesReceived;

    wiringPiSetupGpio();
    printf("RPi #2 is ready to accept RPC requests.\n");

    socketCANDescriptor = setupCANSocket("can0");
    if (socketCANDescriptor < 0) {
        return -1;
    }

    while (processCANFrames(socketCANDescriptor)) {
        // Additional processing or cleanup can be added here
    }

    closeCANSocket(socketCANDescriptor);
    return 0;
}