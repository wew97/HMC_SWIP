CC = gcc
CFLAGS = -Wall

all: main

main: main.c printBinary.c
	$(CC) $(CFLAGS) -o main main.c printBinary.c -lm

clean:
	rm -f main