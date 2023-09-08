#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./gen_rand_between.h"

void generateRandBetween(float a, float b, int number, float result[])
{
    srand(time(NULL));
    float x = 0;
    for (int i = 0; i < number; i++)
    {   
       x = (float)rand()/RAND_MAX;
       result[i] = x*(b-a) + a;
    }
}