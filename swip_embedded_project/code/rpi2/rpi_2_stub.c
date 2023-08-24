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

void displayTextUnmarshall(char *buffer, int bytesTotal, int *lineNum, char *inputString)
{
    memcpy(&lineNum, &buffer[PACK_SIZE * 2], 4);
    memcpy(inputString, &buffer[PACK_SIZE * 3], bytesTotal - 24);
}
void moveMotorUnmarshall(char *buffer, int *inputVal)
{
    memcpy(&inputVal, &buffer[PACK_SIZE*2], 4);
}
void terminateRPCUnmarshall(char *buffer, char *inputString)
{
}