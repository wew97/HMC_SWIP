// rpi_1_can.h

int setupCANSocket(const char *interfaceName);
void processCANFrames(int socketCANDescriptor);
void closeCANSocket(int socketCANDescriptor);