// rpi_1_main.c

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
#include "rpi_1_led.h"
#include "rpi_1_ultrasonic.h"
#include "rpi_1_dijkstra.h"

#define NUM_MAX 100000

#define map_file_name "map_data.txt"

int main(void)
{
    pthread_t threads[4];
    char path[NUM_MAX];
    char inputString[128];
    struct can_frame frame;
    int socketCANDescriptor;
    struct ifreq ifr;
    struct sockaddr_can addr;
    char quit_command[] = "quit";

    wiringPiSetupGpio();
    printf("RPi #1 is ready.\n\n");

    // LED 쓰레드
    pthread_create(&threads[0], NULL, led, NULL);

    // dijkstra_start
    readGraph(map_file_name);

    int source = 3;
    int destination = 6;

    char buffer[MAX_NODES * 6];
    int len = 0;

    findShortestPath(source, destination, buffer, &len);

    printf("The shortest path is %c -> %c -> %c\n\n", buffer[2],buffer[1],buffer[0]);
    //buffer => path를 담고 있음 2 -> 1 -> 0 순서로

    // dijkstra_end

    // 초음파 쓰레드
    pthread_create(&threads[1], NULL, ultrasonic, NULL);

    // 원격 LCD 출력
    // printf("SocketCAN Sender\n");
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
        printf("Enter your text to display on RPi #2's LCD: ");
        fgets(inputString, 128, stdin);

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
        perror("Terminating RPi #1.");
        return -1;
    }

    pthread_join(threads[0], NULL);
    // pthread_join(threads[1], NULL);
    return 0;
}