CC = gcc
CFLAGS = -lwiringPi 
OBJS = rpi_1_main.o rpi_1_led.o rpi_1_ultrasonic.o rpi_1_dijkstra.o rpi_1_can.o rpi_1_stub.o
TARGET = rpi_1_main

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lpthread

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)