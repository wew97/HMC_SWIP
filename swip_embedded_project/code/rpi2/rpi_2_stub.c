#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rpi_2_stub.h"
#include "rpi_2_can.h"
#include "rpi_2_lcd.h"
#include "rpi_2_motor.h"

// 8: Total packets
// 8: Function ID
// ~: Args

enum FUNC_ID { DISPLAY_TEXT, MOVE_MOTOR, TERMINATE };

void displayTextUnmarshall(char *buffer, int bytesTotal, int *lineNum, char *inputString)
{
    memcpy(lineNum, &buffer[PACK_SIZE * 2], 4);
    memcpy(inputString, &buffer[PACK_SIZE * 3], bytesTotal - 24);
}
void displayTextResponse(const char* inputString)
{
    char buffer[8];

    int function_id = DISPLAY_TEXT;

    int strLen = strlen(inputString);

    memcpy(buffer, &function_id, sizeof(function_id));
    memcpy(&buffer[4], &strLen, sizeof(strLen));

    sendCANFrames(socketCANDescriptor, buffer, sizeof(buffer));
    bzero(buffer, sizeof(buffer));
}

void moveMotorUnmarshall(char *buffer, int *inputVal)
{
    memcpy(inputVal, &buffer[PACK_SIZE*2],4);
}
void moveMotorResponse(int inputValue)
{
    char buffer[8];

    int function_id = MOVE_MOTOR;

    memcpy(buffer, &function_id, sizeof(function_id));
    memcpy(&buffer[4], &inputValue, sizeof(inputValue));

    sendCANFrames(socketCANDescriptor, buffer, sizeof(buffer));
    bzero(buffer, sizeof(buffer));
}
void terminateRPC(char *text)
{
    closeCANSocket(socketCANDescriptor);
}