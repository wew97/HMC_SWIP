// rpi_2_stub.c

#include <stdio.h>
#include <rpc/rpc.h>
// #include "rpc_2_stub.h"

// Function ID, arg length, arg
// char func_arg[50];

extern int socketCANDescriptor;

void displayTextMarshall(int lineNum, const char* inputString, char *buffer, size_t buffer_size) {
    ;
}

void displayText(int lineNum, const char* inputString)
{
    struct can_frame frame;
    char buffer[50];

    // Prepare the CAN frame
    frame.can_id = 0x123; // Arbitrary CAN ID
    frame.can_dlc = strlen(inputString);
    // strncpy((char *)frame.data, inputString, frame.can_dlc);

    displayTextMarshall(lineNum, inputString, buffer, sizeof(buffer))
    
    frame.data = buffer;

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