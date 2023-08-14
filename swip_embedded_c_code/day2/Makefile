CC = gcc
TARGET = monte_carlo
OBJS = monte_carlo.o gen_rand_between.o

$(TARGET): $(OBJS)
	$(CC) -o $(@) $(OBJS) -lpthread

clean:
	rm -f *.o
	rm -f $(TARGET)
