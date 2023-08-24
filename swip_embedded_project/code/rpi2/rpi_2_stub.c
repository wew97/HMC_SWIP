#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rpi_2_stub.h"
#include "rpi_2_can.h"

// 8: Total packets
// 8: Function ID
// ~: Args

typedef enum FUNC_ID
{
    DISPLAY_TEXT,
    MOVE_MOTOR,
    TERMINATE
}FUNC_ID;

void unmarshall(char *buffer)
{
    int burffersize = PACK_SIZE * 3;
    FUNC_ID funcID = buffer[7];

    switch (funcID)
    {
    case DISPLAY_TEXT:
        // displayText() 실행
        break;
    case MOVE_MOTOR:
        // moveMotor() 실행
        break;
    case TERMINATE:
        // terminateRPC() 실행
        break;
    }
}