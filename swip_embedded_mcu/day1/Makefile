CC = gcc
CFLAGS = -lwiringPi 
OBJS = switch_interrupts.o
TARGET = switch_interrupts

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)