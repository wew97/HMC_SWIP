#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>

#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int main(void) 
{
        int socketCANDescriptor;
        struct sockaddr_can addr;
        struct ifreq ifr;
        struct can_frame frame;

        char inputString[128];
        char sendMessage[8];        
        
        int packetTotal;                 // Number of packets to send
        int lastPacketSize;              // Size of last packet

        int i;
        
        
        printf("SocketCAN Sender\n");

        if ((socketCANDescriptor = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
                perror("Socket creation failed.");
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
                printf("Enter your text: ");
                fgets(inputString, 128, stdin);
                printf("Your text: %s", inputString);                
                printf("Input Length = %d\n", (int)strlen(inputString));

                // Prepare the CAN frame
                frame.can_id = 0x123; // Arbitrary CAN ID
                frame.can_dlc = strlen(inputString);
                strncpy((char *)frame.data, inputString, frame.can_dlc);

                // Send the CAN frame
                if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
                    perror("Write failed");
                    return -1;
                }
        
        }
        
        if (close(socketCANDescriptor) < 0) {
                perror("Close failed");
                return -1;
        }

        return 0;
}