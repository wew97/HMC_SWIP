CC = gcc
CFLAGS = -lwiringPi
OBJS = servomotor_sw.o
TARGET = servomotor_sw

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)