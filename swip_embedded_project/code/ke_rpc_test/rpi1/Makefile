CC = gcc
CFLAGS = -lpthread
OBJS = main.o rpi_1_stub.o rpi_1_can.o
TARGET = executable

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) 

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)