// rpi_1_can.h

#define PACK_SIZE 8

extern int socketCANDescriptor;

int setupCANSocket(const char *interfaceName);
int receiveCANFrames(int socketCANDescriptor, char *buffer, int bytesTotal);
int sendCANFrames(int socketCANDescriptor, char* buffer, int bufferSize);
void closeCANSocket(int socketCANDescriptor);