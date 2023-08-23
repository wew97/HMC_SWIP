CC = gcc
CFLAGS = -lpthread
OBJS = main.o rpi_2_stub.o rpi_2_can.o
TARGET = executable

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) 

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)