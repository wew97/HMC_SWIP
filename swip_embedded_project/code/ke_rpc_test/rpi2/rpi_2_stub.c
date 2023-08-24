#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rpi_2_stub.h"
#include "rpi_2_can.h"

// 8: Total packets
// 8: Function ID
// ~: Args

enum FUNC_ID { DISPLAY_TEXT, MOVE_MOTOR, TERMINATE };

int displayText(char* buffer)
{

}
int moveMotor(char* buffer)
{

}
int terminateRPC(char* buffer)
{

}