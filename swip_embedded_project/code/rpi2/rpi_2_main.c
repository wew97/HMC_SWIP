// rpi_2_main.c

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
#include "rpi_2_can.h"
//#include "rpi_2_lcd.h"

#define NUM_MAX 100000

int main(void) {
    pthread_t threads[4];

    int socketCANDescriptor;
    

    wiringPiSetupGpio();
    printf("RPi #2 is ready to accept RPC requests.\n");

    socketCANDescriptor = setupCANSocket("can0");
    if (socketCANDescriptor < 0) {
        return -1;
    }

    processCANFrames(socketCANDescriptor);

    closeCANSocket(socketCANDescriptor);
    return 0;
}