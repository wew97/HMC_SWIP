// rpi_2_can.h

#define PACK_SIZE 8

int setupCANSocket(const char *interfaceName);
int receiveCANFrames(int socketCANDescriptor, char* buffer, int bytesTotal);
void closeCANSocket(int socketCANDescriptor);