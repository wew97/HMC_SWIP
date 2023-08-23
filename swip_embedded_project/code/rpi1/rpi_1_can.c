// rpi_1_can.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include "rpi_1_can.h"

#define NUM_MAX 100000

int setupCANSocket(const char *interfaceName)
{
    int socketCANDescriptor;
    struct ifreq ifr;
    struct sockaddr_can addr;

    if ((socketCANDescriptor = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
    {
        perror("Socket creation failed.");
        return -1;
    }

    strcpy(ifr.ifr_name, "can0");
    ioctl(socketCANDescriptor, SIOCGIFINDEX, &ifr);
    memset(&addr, 0, sizeof(addr));

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(socketCANDescriptor, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Bind failed");
        return -1;
    }

    return socketCANDescriptor;
}

void processCANFrames(int socketCANDescriptor)
{
    struct can_frame frame;
    char quit_command[] = "quit\n";
    char inputString[128];

    while (1)
    {
        printf("Enter your text to display on RPi #2's LCD: ");
        fgets(inputString, 128, stdin);

        // Prepare the CAN frame
        frame.can_id = 0x123; // Arbitrary CAN ID
        frame.can_dlc = strlen(inputString);
        strncpy((char *)frame.data, inputString, frame.can_dlc);

        // Send the CAN frame
        if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame))
        {
            perror("Write failed");
        }
        if (strncmp(inputString, quit_command, frame.can_dlc) == 0 && frame.can_dlc == strlen(quit_command))
        {
            printf("\nTerminating RPi #1.\n");
            break;
        }
    }
}

void closeCANSocket(int socketCANDescriptor)
{
    if (close(socketCANDescriptor) < 0)
    {
        perror("Close failed.");
    }
}