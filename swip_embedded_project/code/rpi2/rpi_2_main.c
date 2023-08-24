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

#define NUM_MAX 100000
#define Detected_DEVICE_ID_BY_I2C 0x27 // Device ID detected by I2C
                                       // Seems that it maps to the device's address

int deviceHandle;

int main(void)
{
    pthread_t threads[4];

    int socketCANDescriptor;

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

            displayTextUnmarshall(buffer, bytesTotal, lineNum, inputString);
            initializeLCD();
            displayText(*lineNum, inputString);
            break;
        }
        case MOVE_MOTOR:
        {
            int *inputVal = (int *)malloc(sizeof(int));

            moveMotorUnmarshall(buffer, inputVal);
            moveMotor(*inputVal);
            break;
        }
        case TERMINATE:
        {
            char *inputString;
            // terminateRPCUnmarshall(buffer, inputString);
            printf("~~~\n");
            goto terminate_rpc;
            break;
        }
        }
        // /*
        // 이거 나중에 terminateRPC(char *text)로 뺄거임
        // */
        // if (strncmp(receiveMessage, quit_command, frame.can_dlc) == 0 && (frame.can_dlc == strlen(quit_command)))
        // {
        //     printf("RPC request 'QUIT' command received\n\n");
        //     printf("Terminating RPi #2.\n");
        //     displayText(0, "Bye Bye!");
        //     delay(2000);
        //     initializeLCD();
        //     break;
        // }
        // // 여기까지
    }

terminate_rpc:
    closeCANSocket(socketCANDescriptor);
    return 0;
}