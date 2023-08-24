
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>

#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "rpi_2_can.h"
#include "rpi_2_stub.h"

int socketCANDescriptor; 

int main(void) 
{
    socketCANDescriptor = setupCANSocket("can0");
    if (socketCANDescriptor < 0)
    {
        return -1;
    }

    while(1) {
        struct can_frame frame;
        char* buffer;
        char receiveMessage[8];

        int nbytesReceived = read(socketCANDescriptor, &frame, sizeof(struct can_frame));
        if (nbytesReceived < 0) {
                perror("Read failed");
                return -1;
        }

        int bytesTotal;
        memcpy(&bytesTotal, frame.data, 4);
        receiveCANFrames(socketCANDescriptor, buffer, bytesTotal);

        int function_id;
        memcpy(&function_id, &buffer[PACK_SIZE], 4);

        switch(function_id) {
        case DISPLAY_TEXT:
                int lineNum;
                char* inputString;
                displayTextUnmarshall(buffer, &lineNum, inputString);
                displayText(lineNum, inputString);
                break;
        case MOVE_MOTOR:
                int inputVal;
                moveMotorUnmarshall(buffer, &inputVal);
                moveMotor(inputVal);
                break;
        case TERMINATE:
                char* inputString;
                terminateRPCUnmarshall(buffer, inputString);
                printf("~~~\n");
                goto terminate;
                break;
        }
    }

terminate:

    if (close(socketCANDescriptor) < 0) 
    {
            perror("Close");
            return -1;
    }

    return 0;
}