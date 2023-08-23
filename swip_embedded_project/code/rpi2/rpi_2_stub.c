// rpi_2_stub.c

#include <stdio.h>
#include <rpc/rpc.h>
#include "rpi_2_stub.h"

// Function ID, arg length, arg
char func_arg[50];

void marshall(const char *func, char *buffer, size_t buffer_size) {
    memcpy(buffer, func, sizeof(func));
}

void unmarshall(const char *buffer, char *func, size_t buffer_size) {
    memcpy(func, buffer, sizeof(func));
}

void stub(char *receiveStub){
    // receiveStub을 unmarshall로 해석
    // Case 1) displayText(int lineNum, char *text)
    // Case 2) moveMotor(int inputValue)

    return;
}