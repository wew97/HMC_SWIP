#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(int argc, char *argv[])
{
    float num1 = 0;
    float num2 = 0;
    int total = 0;
    float sum = 0;

    printf("Enter a start value of range: ");
    scanf("%f", &num1);
    printf("Enter a finish value of range: ");
    scanf("%f", &num2);
    printf("Enter the total number of random values to generate: ");
    scanf("%d", &total);

    float *result = (float *)malloc(sizeof(float) * total);

    if (result != NULL)
    {

        generateRandBetween(num1, num2, total, result);

        printf("Random values in [%f,%f]\n", num1, num2);
    
        for(int i = 0; i<total; i++){
            sum += result[i];
            printf("%.6f ", result[i]);
        }
        printf("\n");

        printf("The average of random values is %.6f\n", sum/total);

        free(result);
    }

    return 0;
}