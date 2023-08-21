CC = gcc
TARGET = receiver.out sender.out

all: $(TARGET)

receiver.out: receiver.c
	$(CC) -o receiver.out $^

sender.out: sender.c
	$(CC) -o sender.out $^

clean:
	rm -f *.out
	rm -f $(TARGET)