
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
        char receiveMessage[8];

            int nbytesReceived = read(socketCANDescriptor, &frame, sizeof(struct can_frame));
            if (nbytesReceived < 0) {
                    perror("Read failed");
                    return -1;
            }

            printf("0x%03X [%d] ", frame.can_id, frame.can_dlc);                
            memcpy(receiveMessage, (unsigned char *)(frame.data), frame.can_dlc);
            receiveMessage[frame.can_dlc] = '\n';
            printf("%s", receiveMessage);

            if ((receiveMessage[0] == 'q') && (frame.can_dlc == 2)) {
                    printf("QUIT COMMAND!\n");
                    break;
            }

            bzero(receiveMessage, 8);
    }

    if (close(socketCANDescriptor) < 0) 
    {
            perror("Close");
            return -1;
    }

    return 0;
}