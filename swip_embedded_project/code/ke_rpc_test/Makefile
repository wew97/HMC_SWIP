CC = gcc
CFLAGS = -lpthread
OBJS = main.o stub.o
TARGET = executable

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) 

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)