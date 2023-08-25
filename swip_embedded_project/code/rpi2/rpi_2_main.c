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

#include <wiringPiI2C.h>
#include <wiringPi.h>

#include "rpi_2_can.h"
#include "rpi_2_lcd.h"
#include "rpi_2_motor.h"
#include "rpi_2_stub.h"

#define Detected_DEVICE_ID_BY_I2C 0x27 // Device ID detected by I2C
                                       // Seems that it maps to the device's address

int deviceHandle;
int socketCANDescriptor;

enum FUNC_ID { DISPLAY_TEXT, MOVE_MOTOR, TERMINATE };

int main(void)
{
    pthread_t threads[4];

    wiringPiSetupGpio();
    initializeLCD();
    printf("RPi #2 is ready to accept RPC requests.\n");

    deviceHandle = wiringPiI2CSetup(Detected_DEVICE_ID_BY_I2C);

    socketCANDescriptor = setupCANSocket("can0");
    if (socketCANDescriptor < 0)
    {
        return -1;
    }

    while (1)
    {
        struct can_frame frame;
        char buffer[128];
        bzero(buffer, 128);
        char receiveMessage[8];

        int nbytesReceived = read(socketCANDescriptor, &frame, sizeof(struct can_frame));
        if (nbytesReceived < 0)
        {
            perror("Read failed");
            return -1;
        }

        int bytesTotal;
        memcpy(&bytesTotal, frame.data, 4);
        receiveCANFrames(socketCANDescriptor, buffer, bytesTotal);
        int function_id;
        memcpy(&function_id, &buffer[PACK_SIZE], 4);
        switch (function_id)
        {
        case DISPLAY_TEXT:
        {
            int *lineNum = (int *)malloc(sizeof(int));
            char inputString[128];
            bzero(inputString, 128);

            displayTextUnmarshall(buffer, bytesTotal, lineNum, inputString);
            initializeLCD();
            displayText(*lineNum, inputString);
            displayTextResponse(inputString);
            printf("RPC request 'displayText(%d, %s)' received and processed.\n\n", *lineNum+1, inputString);
            break;
        }
        case MOVE_MOTOR:
        {
            int *inputVal = (int *)malloc(sizeof(int));

            moveMotorUnmarshall(buffer, inputVal);
            moveMotor(*inputVal);
            moveMotorResponse(*inputVal);
            printf("RPC request 'moveMotor(%d)' received and processed.\n\n", *inputVal);
            break;
        }
        case TERMINATE:
        {
            char *inputString;
            initializeLCD();
            terminateRPC(inputString);
            printf("RPC request 'QUIT' command received.\n\n");
            printf("Terminating RPi #2.\n");
            return 0;
        }
        }
    }