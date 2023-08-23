// rpi_2_stub.c

#include <stdio.h>
#include <rpc/rpc.h>
// #include "rpc_2_stub.h"

// Function ID, arg length, arg
// char func_arg[50];

void marshall(const char *func, char *buffer, size_t buffer_size) {
    memcpy(buffer, func, sizeof(func));
}

void unmarshall(const char *buffer, char *func, size_t buffer_size) {
    memcpy(func, buffer, sizeof(func));
}

void displayText(const char* inputString)
{


    // Prepare the CAN frame
    frame.can_id = 0x123; // Arbitrary CAN ID
    frame.can_dlc = strlen(inputString);
    // strncpy((char *)frame.data, inputString, frame.can_dlc);
    
    // frame.data = displayText(inputString);

    displayText(inputString);

    // Send the CAN frame
    if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        perror("Write failed");
    }
    if (strncmp(inputString, quit_command, frame.can_dlc) == 0 && frame.can_dlc == strlen(quit_command)){
        printf("\nTerminating RPi #1.\n");
        break;
    }
}

char* moveMotorStub(int width)
{

}