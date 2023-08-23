#if 0
// rpi_2_stub.c

#include <stdio.h>
#include <rpc/rpc.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include "rpi_1_stub.h"

// Function ID, arg length, arg
// char func_arg[50];

// 8: Total packets
// 8: Function ID
// ~: Args

extern int socketCANDescriptor;

void displayTextMarshall(int lineNum, const char* inputString, char *buffer, size_t buffer_size) {
    // printf("띠용?\n");
    memset(buffer, 0, strlen(inputString));
    union{
        int integer;
        char byte[4];
    } _int;
    int total_packets = strlen(inputString);
    _int.integer = 1;
    buffer[0] = total_packets;
    buffer[8] = _int.byte[0];
    buffer[9] = _int.byte[1];
    buffer[10] = _int.byte[2];
    buffer[11] = _int.byte[3];
    
    int i;
    for(i = 0; i < total_packets; i++)    buffer[i+12] = inputString[i];
}

// 0
void displayText(int lineNum, const char* inputString)
{
    struct can_frame frame;
    char buffer[50];

    // Prepare the CAN frame
    frame.can_id = 0x123; // Arbitrary CAN ID
    frame.can_dlc = strlen(inputString);
    // strncpy((char *)frame.data, inputString, frame.can_dlc);

    displayTextMarshall(lineNum, inputString, buffer, sizeof(buffer));
    printf("buffer0: %d\n",*(int*)buffer);
    printf("buffer1: %d\n",*(int*)(&buffer[8]));
    printf("buffer2: %s\n",&buffer[12]);
    
    // frame.data = buffer;

    // Send the CAN frame
    if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        perror("Write failed");
    }

}

char* moveMotor(int width)
{

}

int terminateRPC(char* text)
{

}
# endif
// rpi_1_stub.c

#include <stdio.h>
#include <rpc/rpc.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include "rpi_1_stub.h"

// Function ID, arg length, arg
// char func_arg[50];

// 8: Total packets
// 8: Function ID
// ~: Args

extern int socketCANDescriptor;

void displayTextMarshall(int lineNum, const char* inputString, char *buffer, int* buffer_size) {

    int packetTotal = 1 + strlen(inputString) / 8;
    int lastPacketSize = strlen(inputString) % 8;
    if (lastPacketSize > 0) packetTotal++;

    int function_id = 1;

    memcpy(&buffer[0], &packetTotal, 4);
    memcpy(&buffer[4], &function_id, 4);
    strcpy(&buffer[8], inputString);

    *buffer_size = 8 + strlen(inputString);
}

// 0
void displayText(int lineNum, const char* inputString)
{
    struct can_frame frame;
    char buffer[50];
    int buffer_size;

    // Prepare the CAN frame
    frame.can_id = 0x123; // Arbitrary CAN ID
    frame.can_dlc = strlen(inputString);

    displayTextMarshall(lineNum, inputString, buffer, &buffer_size);
    // printf("%d",(int*)buffer);

    for (int i = 0; i < (int)buffer[0]; i++) {

        char sendMessage[8];

        if (i < (int)buffer[0] - 1) {
            frame.can_dlc = 8;
            strncpy(sendMessage, buffer + (i * 8), 8);
            memcpy(frame.data, (char *)sendMessage, 8);
        }
        else {
            int lastPacketSize = buffer_size % 8;
            frame.can_dlc = lastPacketSize;
            strncpy(sendMessage, buffer + (i * 8), lastPacketSize);
            memcpy(frame.data, (char *)sendMessage, lastPacketSize);
        }

        if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
            perror("Write failed");
            return -1;
        }   

        printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);
        printf("%d %d\n", sendMessage[0], sendMessage[1]);

        bzero(sendMessage, sizeof(sendMessage));
    }
    
    // Send the CAN frame
    if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        perror("Write failed");
    }

}

char* moveMotor(int width)
{

}

int terminateRPC(char* text)
{

}