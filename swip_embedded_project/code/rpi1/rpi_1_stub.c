#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rpi_1_stub.h"
#include "rpi_1_can.h"

// 8: Total bytes (buffer size)
// 8: Function ID
// ~: Args

enum FUNC_ID { DISPLAY_TEXT, MOVE_MOTOR, TERMINATE };

// Function ID: 0
int displayText(int lineNum, const char* inputString)
{
    int result;

    int bufferSize = PACK_SIZE*3 + strlen(inputString);
    char* buffer = malloc(bufferSize);
    int function_id = DISPLAY_TEXT;

    // Marshall
    memcpy(&buffer[PACK_SIZE * 1], &function_id, sizeof(function_id));
    memcpy(&buffer[PACK_SIZE * 2], &lineNum, sizeof(lineNum));
    memcpy(&buffer[PACK_SIZE * 3], inputString, strlen(inputString));

    sendCANFrames(socketCANDescriptor, buffer, bufferSize);

    free(buffer);

    // Receive displayText response
    char res_buffer[PACK_SIZE];
    receiveCANFrames(socketCANDescriptor, res_buffer, PACK_SIZE);
    result = ((int*)res_buffer)[1];
    printf("Requested RPC displayText(%d, %s) and received return value %d\n", lineNum, inputString, result);

    return result;
}

// Function ID: 1
int moveMotor(int inputVal) 
{
    int result;

    int bufferSize = PACK_SIZE*2 + sizeof(inputVal);
    char* buffer = malloc(bufferSize);
    int function_id = MOVE_MOTOR;

    // Marshall
    memcpy(&buffer[PACK_SIZE * 1], &function_id, sizeof(function_id));
    memcpy(&buffer[PACK_SIZE * 2], &inputVal, sizeof(inputVal));

    result = sendCANFrames(socketCANDescriptor, buffer, bufferSize);

    free(buffer);

    // Receive moveMotor response
    char res_buffer[PACK_SIZE];
    receiveCANFrames(socketCANDescriptor, res_buffer, PACK_SIZE);
    result = ((int*)res_buffer)[1];

    printf("Requested RPC moveMotor(%d) and received return value %d\n", inputVal, result);

    return result;
}

// Function ID: 2
int terminateRPC(const char* text)
{
    printf("Requested RPC terminateRPC(%s)\n", text);
    int result;

    int bufferSize = PACK_SIZE*2 + strlen(text);
    char* buffer = malloc(bufferSize);
    int function_id = TERMINATE;

    // Marshall
    memcpy(&buffer[PACK_SIZE * 1], &function_id, sizeof(function_id));
    memcpy(&buffer[PACK_SIZE * 2], text, strlen(text));

    result = sendCANFrames(socketCANDescriptor, buffer, bufferSize);

    free(buffer);

    return result;
}