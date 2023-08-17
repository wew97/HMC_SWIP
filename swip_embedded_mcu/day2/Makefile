CC = gcc
CFLAGS = -lwiringPi
OBJS = lcd_moving.o
TARGET = lcd_moving

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)