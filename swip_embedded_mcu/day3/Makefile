CC = gcc
TARGET = server_receiver.out client_sender.out

all: $(TARGET)

server_receiver.out: server_receiver.c
	$(CC) -o server_receiver.out $^

client_sender.out: client_sender.c
	$(CC) -o client_sender.out $^

clean:
	rm -f *.out
	rm -f $(TARGET)