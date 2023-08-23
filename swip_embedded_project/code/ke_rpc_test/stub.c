#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "stub.h"

// Function ID, arg length, arg
// char func_arg[50];

// 8: Total packets
// 8: Function ID
// ~: Args

#define PACK_SIZE 8
enum FUNC_ID { DISPLAY_TEXT, MOVE_MOTOR, TERMINATE };

struct can_frame {
    int can_id;
    int can_dlc;
    char data[8];
};

int displayTextMarshall(int lineNum, const char* inputString, char *buffer) {

    int packetTotal = 3 + strlen(inputString) / PACK_SIZE;
    int lastPacketSize = strlen(inputString) % PACK_SIZE;
    if (lastPacketSize > 0) packetTotal++;

    int function_id = DISPLAY_TEXT;

    memcpy(&buffer[PACK_SIZE * 0], &packetTotal, sizeof(packetTotal));
    memcpy(&buffer[PACK_SIZE * 1], &function_id, sizeof(function_id));
    memcpy(&buffer[PACK_SIZE * 2], &lineNum, sizeof(lineNum));
    memcpy(&buffer[PACK_SIZE * 3], inputString, strlen(inputString));

    return packetTotal;
}

// Function ID: 0
void displayText(int lineNum, const char* inputString)
{
    struct can_frame frame;
    int bufferSize = strlen(inputString) + (PACK_SIZE * 3);
    char* buffer = malloc(bufferSize);

    // Prepare the CAN frame
    frame.can_id = 0x123; // Arbitrary CAN ID

    int packetTotal = displayTextMarshall(lineNum, inputString, buffer);
    // printf("%d",(int*)buffer);

    for (int i = 0; i < packetTotal; i++) {

        char sendMessage[PACK_SIZE];

        if (i < packetTotal - 1) {
            frame.can_dlc = PACK_SIZE;
            memcpy(sendMessage, buffer + (i * PACK_SIZE), PACK_SIZE);
            memcpy(frame.data, buffer + (i * PACK_SIZE), PACK_SIZE);
        }
        else {
            int lastPacketSize = (bufferSize) % PACK_SIZE;
            frame.can_dlc = lastPacketSize;
            memcpy(sendMessage, buffer + (i * PACK_SIZE), lastPacketSize);
            memcpy(frame.data, buffer + (i * PACK_SIZE), lastPacketSize);
        }

        // if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        //     perror("Write failed");
        //     return -1;
        // }   

        printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);
        printf("%d %d\n", sendMessage[0], sendMessage[1]);
        for(int j = 0; j < PACK_SIZE; j++) {
            printf("%c ", sendMessage[j]);
        }
        printf("\n");

        bzero(sendMessage, sizeof(sendMessage));
    }

    free(buffer);
}

// Function ID: 1
char* moveMotor(int width)
{

}

// Function ID: 2
int terminateRPC(char* text)
{

}