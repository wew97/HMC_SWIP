
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

    int nbytesReceived;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;
    
    char receiveMessage[8];
            
    printf("SocketCAN Receiver\n");
    
    if ((socketCANDescriptor = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
            perror("Socket creation failed");
            return -1;
    }
    
    strcpy(ifr.ifr_name, "can0" ); 
    ioctl(socketCANDescriptor, SIOCGIFINDEX, &ifr);
    memset(&addr, 0, sizeof(addr));
    
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    
    if (bind(socketCANDescriptor, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("Bind failed");
            return -1;
    }

    while(1) {
            nbytesReceived = read(socketCANDescriptor, &frame, sizeof(struct can_frame));
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