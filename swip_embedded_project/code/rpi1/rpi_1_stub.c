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
    int total_packets = strlen(inputString);
    int function_id = 1;
    buffer[0] = total_packets;
    buffer[8] = function_id;
    buffer[12] = inputString; 
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
    printf("%d",(int*)buffer);
    
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