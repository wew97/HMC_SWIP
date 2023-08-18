CC = gcc
CFLAGS = -lwiringPi
OBJS = servomotor_hw.o
TARGET = servomotor_hw

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)