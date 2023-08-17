CC = gcc
CFLAGS = -lwiringPi
OBJS = lcd.o
TARGET = lcd

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)