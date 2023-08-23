// rpi_2_can.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include <wiringPiI2C.h>

#include "wiringPi.h"
#include "rpi_2_can.h"
#include "rpi_2_lcd.h"

#define Detected_DEVICE_ID_BY_I2C 0x27 // Device ID detected by I2C
                                       // Seems that it maps to the device's address

#define NUM_MAX 100000

extern int deviceHandle;

int setupCANSocket(const char *interfaceName) {
    int socketCANDescriptor;
    struct ifreq ifr;
    struct sockaddr_can addr;

    if ((socketCANDescriptor = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    strcpy(ifr.ifr_name, interfaceName);
    ioctl(socketCANDescriptor, SIOCGIFINDEX, &ifr);
    memset(&addr, 0, sizeof(addr));

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(socketCANDescriptor, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    return socketCANDescriptor;
}

void processCANFrames(int socketCANDescriptor) {
    struct can_frame frame;
    char quit_command[] = "quit\n";
    char receiveMessage[8];
    int nbytesReceived;
    
    while (1) {
        nbytesReceived = read(socketCANDescriptor, &frame, sizeof(struct can_frame));
        if (nbytesReceived < 0) {
            perror("Read failed");
            break;
        }

        printf("0x%03X [%d] ", frame.can_id, frame.can_dlc);
        memcpy(receiveMessage, (unsigned char *)(frame.data), frame.can_dlc);
        receiveMessage[frame.can_dlc] = '\n';
        printf("%s\n", receiveMessage);

        if (strncmp(receiveMessage, quit_command, frame.can_dlc) == 0 && (frame.can_dlc == strlen(quit_command))) {
            printf("RPC request 'QUIT' command received\n\n");
            printf("Terminating RPi #2.\n");
            lcd("Bye Bye!");
            delay(2000);
            initializeLCD();
            break;
        }

        lcd(receiveMessage);

        bzero(receiveMessage, 8);
    }
}

void closeCANSocket(int socketCANDescriptor) {
    if (close(socketCANDescriptor) < 0) {
        perror("Close failed");
    }
}