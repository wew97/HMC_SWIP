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
// #include "rpi_1_can.h"
// #include "rpi_1_stub.h"

#define Detected_DEVICE_ID_BY_I2C 0x27 // Device ID detected by I2C
                                       // Seems that it maps to the device's address
#define LCD_BACKLIGHT_ON 0x08          // On             "0000 1000"
#define LCD_BACKLIGHT_OFF 0x00         // Off            "0000 0000"
#define LCD_ENABLE 0x04                // Enable         "0000 0100"
#define LCD_DISABLE 0x00               // Disable        "0000 0000"
#define LCD_RW_READ 0x02               // Read           "0000 0010"
#define LCD_RW_WRITE 0x00              // Write          "0000 0000"
#define LCD_RS_DATA 0x01               // Data           "0000 0001"
#define LCD_RS_INST 0x00               // Instruction    "0000 0000"

#define NUM_MAX 100000

int main(void) 
{
    pthread_t threads[4];
    char path[NUM_MAX];
    char inputString[128];
    struct can_frame frame;
    int socketCANDescriptor;
    struct ifreq ifr;
    struct sockaddr_can addr;
    char quit_command[5] = "quit";
    char receiveMessage[8];
    int nbytesReceived;

    wiringPiSetupGpio();
    printf("RPi #2 is ready to accept RPC requests.\n");

    // 원격 LCD 출력
    // printf("SocketCAN Receiver\n");
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
        printf("%s\n", receiveMessage);

        // quit까지

        bzero(receiveMessage, 8);
    }
    if (close(socketCANDescriptor) < 0) {
        perror("Terminating RPi #2.");
        return -1;
    }
    return 0;
}