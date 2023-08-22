// rpi_1_main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <net/if.h>

#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "wiringPi.h"
// #include "rpi_1_can.h"
// #include "rpi_1_stub.h"
#include "rpi_1_led.h"
#include "rpi_1_ultrasonic.h"
#include "rpi_1_dijkstra.h"

#define NUM_MAX 100000

#define map_file_name "map_data.txt"

int main(void)
{
    pthread_t threads[4];
    char path[NUM_MAX];

    wiringPiSetupGpio();
    printf("RPi #1 is ready.\n\n");

    // LED 쓰레드
    pthread_create(&threads[0], NULL, led, NULL);

    // dijkstra_start
    readGraph(map_file_name);

    int source = 3;
    int destination = 6;

    char buffer[MAX_NODES * 6];
    int len = 0;

    findShortestPath(source, destination, buffer, &len);

    printf("The shortest path is %c -> %c -> %c\n\n", buffer[2],buffer[1],buffer[0]);
    //buffer => path를 담고 있음 2 -> 1 -> 0 순서로

    // dijkstra_end

    // 초음파 쓰레드
    pthread_create(&threads[1], NULL, ultrasonic, NULL);

    pthread_join(threads[0], NULL);
    // pthread_join(threads[1], NULL);
    return 0;
}