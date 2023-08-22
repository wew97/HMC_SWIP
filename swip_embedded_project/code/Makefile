CC = gcc
CFLAGS = -lwiringPi 
<<<<<<< HEAD
OBJS = rpi_1_main.o rpi_1_led.o rpi_1_ultrasonic.o rpi_1_dijkstra.o 
TARGET = rpi_1_main
=======
# OBJS = rpi_1_main.o rpi_1_led.o rpi_1_ultrasonic.o
# TARGET = rpi_1_main
OBJS = rpi_2_main.o
TARGET = rpi_2_main
>>>>>>> 6d998d86115bca632dc785dc166504990e8391a4

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lpthread

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)