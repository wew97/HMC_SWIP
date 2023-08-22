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
// #include "rpi_1_ultrasonic.h"
// #include "rpi_1_dijkstra.h"

#define NUM_MAX 100000
#define LED_GPIO 17
#define map_file_name "map_data.txt"

int main(void) 
{
    pthread_t threads[4];
    int *led_status = 0;
    char path[NUM_MAX];

    printf("RPi #1 is ready.");
    
    // LED 쓰레드
    wiringPiSetupGpio();
    pinMode(LED_GPIO, OUTPUT);
    pthread_create(&threads[0], NULL, led, NULL);
    pthread_join(threads[0], NULL);
    printf("Started LED.");

    // 다익스트라
    // path = dijkstra(map_file_name);
    // printf("The shortest path is %s", path);
    
    // 초음파 쓰레드
    // pthread_create(&threads[1], NULL, ultrasonic, &quadrantNumer[i]);
    // pthread_join(threads[1], NULL);
    // printf("Started Ultrasonic sensor.");

    // 

    return 0;
}