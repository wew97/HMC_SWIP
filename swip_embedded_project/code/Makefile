CC = gcc
CFLAGS = -lwiringPi 
<<<<<<< HEAD
OBJS = rpi_1_main.o rpi_1_led.o rpi_1_ultrasonic.o rpi_1_dijkstra.o 
TARGET = rpi_1_main
# OBJS = rpi_2_main.o
# TARGET = rpi_2_main
=======
## OBJS = rpi_1_main.o rpi_1_led.o rpi_1_ultrasonic.o rpi_1_dijkstra.o 
## TARGET = rpi_1_main
OBJS = rpi_2_main.o rpi_2_can.o
TARGET = rpi_2_main
>>>>>>> 9c84792c3ae1e4ada6c78af68676c5524121ead3

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lpthread

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)