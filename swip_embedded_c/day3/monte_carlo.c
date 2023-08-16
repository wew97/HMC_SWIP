#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include "gen_rand_between.h"

#define NUM_MAX 1000000

int count[4] = {0, 0, 0, 0};

void *simulateMonteCarlo(void *quadrant)
{
    float *result_x = (float *)malloc(sizeof(float) * NUM_MAX);
    float *result_y = (float *)malloc(sizeof(float) * NUM_MAX);

    int quadrantNumer = *(int*)quadrant;

    if (result_x != NULL && result_y != NULL)
    {
        switch(quadrantNumer){
            case 1:
                generateRandBetween(0.0, 1.0, NUM_MAX, result_x);
                generateRandBetween(0.0, 1.0, NUM_MAX, result_y);
                break;
            case 2:
                generateRandBetween(-1.0, 0.0, NUM_MAX, result_x);
                generateRandBetween(0.0, 1.0, NUM_MAX, result_y);
                break;
            case 3:
                generateRandBetween(-1.0, 0.0, NUM_MAX, result_x);
                generateRandBetween(1.0, 0.0, NUM_MAX, result_y);
                break;
            case 4:
                generateRandBetween(0.0, 1.0, NUM_MAX, result_x);
                generateRandBetween(-1.0, 0.0, NUM_MAX, result_y);
                break;    
        }

        for(int i =0;i<NUM_MAX;i++){
            if((result_x[i]*result_x[i] + result_y[i]*result_y[i])<1.0){
                count[quadrantNumer-1]++;
            }
        }

        free(result_x);
        free(result_y);
    }
}

int main(void)
{
    int i;
    pthread_t threads[4];
    int quadrantNumer[4] = {1, 2, 3, 4};
    int sum = 0;
    double pi;
    int threadReturn;

    for (i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, simulateMonteCarlo, &quadrantNumer[i]);
    }

    for (i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sum = count[0] + count[1] + count[2] + count[3];
    pi = (double)sum / (NUM_MAX);

    printf("Counts: %d %d %d %d\n", count[0], count[1], count[2], count[3]);
    printf("Sum of counts: %d\n", sum);
    printf("The value of PI is %f\n", pi);

    return 0;
}