CC = gcc
CFLAGS = -lwiringPi 
OBJS = rpi_1_main.o rpi_1_led.o
TARGET = rpi_1_main

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lpthread

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)