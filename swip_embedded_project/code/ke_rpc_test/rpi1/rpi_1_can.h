// rpi_1_can.h

#define PACK_SIZE 8

int setupCANSocket(const char *interfaceName);
int sendCANFrames(int socketCANDescriptor, char* buffer, int bufferSize);
void closeCANSocket(int socketCANDescriptor);