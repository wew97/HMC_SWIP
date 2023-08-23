CC = gcc
CFLAGS = -lwiringPi 
# OBJS = rpi_1_main.o rpi_1_led.o rpi_1_ultrasonic.o rpi_1_dijkstra.o rpi_1_can.o
# TARGET = rpi_1_main
OBJS = rpi_2_main.o rpi_2_can.o
TARGET = rpi_2_main

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lpthread

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)