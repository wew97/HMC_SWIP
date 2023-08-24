// rpi_2_stub.h

void displayTextUnmarshall(char *buffer, int bytesTotal, int *lineNum, char *inputString);
void displayTextResponse(const char* inputString);
void moveMotorUnmarshall(char* buffer, int* inputVal);
void moveMotorResponse(int inputValue);
void terminateRPCUnmarshall(char* buffer, char* inputString);