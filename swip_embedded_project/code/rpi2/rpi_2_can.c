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
#include <wiringPi.h>

#include "rpi_2_can.h"
#include "rpi_2_lcd.h"

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

int receiveCANFrames(int socketCANDescriptor, char* buffer, int bufferSize) {

    int packetTotal = bufferSize / PACK_SIZE;
    int lastPacketSize = bufferSize % PACK_SIZE;
    if (lastPacketSize > 0) packetTotal++;

    // Fill buffer[0] with bufferSize
    memcpy(&buffer[0], &bufferSize, sizeof(bufferSize));
    
    // Receive CAN frame one by one
    for (int i = 1; i < packetTotal; i++) {

        // Prepare the CAN frame
        struct can_frame frame; 
        int nbytesReceived = read(socketCANDescriptor, &frame, sizeof(struct can_frame));
        if (nbytesReceived < 0) {
            perror("Read failed");
            return -1;
        }
        
        // For print
        char receivedMessage[PACK_SIZE];

        if (i < packetTotal - 1) { // If this is not last packet
            frame.can_dlc = PACK_SIZE;
            memcpy(buffer + (i * PACK_SIZE), frame.data, PACK_SIZE);

            // For print
            memcpy(receivedMessage, frame.data, PACK_SIZE);
        }
        else { // If this is last packet
            frame.can_dlc = lastPacketSize;
            memcpy(buffer + (i * PACK_SIZE), frame.data, lastPacketSize);

            // For print
            memcpy(receivedMessage, frame.data, PACK_SIZE);
        }

        // Print packet
        printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);
        printf("%d %d\n", receivedMessage[0], receivedMessage[1]);
        for(int j = 0; j < frame.can_dlc; j++) {
            printf("%c ", receivedMessage[j]);
        }
        printf("\n");
    }

    return 0;
}

int sendCANFrames(int socketCANDescriptor, char* buffer, int bufferSize) {

    int packetTotal = bufferSize / PACK_SIZE;
    int lastPacketSize = bufferSize % PACK_SIZE;
    if (lastPacketSize > 0) packetTotal++;

    // Fill buffer[0] with bufferSize
    memcpy(&buffer[0], &bufferSize, sizeof(bufferSize));
    
    // Send CAN frame one by one
    for (int i = 0; i < packetTotal; i++) {

        // Prepare the CAN frame
        struct can_frame frame;
        frame.can_id = 0x123; // Arbitrary CAN ID
        
        // For print
        char sendMessage[PACK_SIZE];

        if (i < packetTotal - 1) { // If this is not last packet
            frame.can_dlc = PACK_SIZE;
            memcpy(frame.data, buffer + (i * PACK_SIZE), PACK_SIZE);

            // For print
            memcpy(sendMessage, buffer + (i * PACK_SIZE), PACK_SIZE);
        }
        else { // If this is last packet
            frame.can_dlc = lastPacketSize;
            memcpy(frame.data, buffer + (i * PACK_SIZE), lastPacketSize);

            // For print
            memcpy(sendMessage, buffer + (i * PACK_SIZE), lastPacketSize);
        }

        if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
            perror("Write failed");
            return -1;
        }   

        // // Print packet
        // printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);
        // printf("%d %d\n", sendMessage[0], sendMessage[1]);
        // for(int j = 0; j < frame.can_dlc; j++) {
        //     printf("%c ", sendMessage[j]);
        // }
        // printf("\n");
    }

    return 0;
}

void closeCANSocket(int socketCANDescriptor) {
    if (close(socketCANDescriptor) < 0) {
        perror("Close failed");
    }
}