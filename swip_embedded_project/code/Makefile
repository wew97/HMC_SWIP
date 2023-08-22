CC = gcc
OBJS = rpi_1_main.o
TARGET = rpi_1_main

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lpthread

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)