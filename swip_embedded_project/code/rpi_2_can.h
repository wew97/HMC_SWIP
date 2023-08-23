// rpi_2_can.h

int setupCANSocket(const char *interfaceName);
int processCANFrames(int socketCANDescriptor);
void closeCANSocket(int socketCANDescriptor);