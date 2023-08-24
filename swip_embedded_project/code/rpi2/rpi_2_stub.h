// rpi_2_stub.h

void displayTextUnmarshall(char *buffer, int bytesTotal, int *lineNum, char *inputString);
void moveMotorUnmarshall(char* buffer, int* inputVal);
void terminateRPCUnmarshall(char* buffer, char* inputString);