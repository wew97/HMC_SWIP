CC = gcc
CFLAGS = -lwiringPi 
OBJS = rpi_2_main.o rpi_2_can.o rpi_2_lcd.o rpi_2_motor.o rpi_2_stub.o
TARGET = rpi_2_main

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lpthread

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)