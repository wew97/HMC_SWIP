#include <stdio.h>
#include <stdlib.h>

#define INPUT_MAX 1024              // Mximum number of elements
#define INPUT_FILE_NAME "input.txt" // Input file containing input data to sort (+ the number of elements)

// Read input data from a file and write the data into buffer
int readInput(int *buffer)
{
    FILE *fd;
    int dataTotal;
    int i;

    fd = fopen(INPUT_FILE_NAME, "r");
    if (fd == NULL)
    {
        printf("Error: Failed to open '%s'.\n", INPUT_FILE_NAME);
        return -1;
    }

    /* read input file to get task parameters */
    fscanf(fd, "%d \n", &dataTotal);
    if (dataTotal > INPUT_MAX)
    {
        printf("The number of elements exceeds the limit %d.\n", INPUT_MAX);
        return -1;
    }

    for (i = 0; i < dataTotal; i++)
    {
        fscanf(fd, "%d ", &buffer[i]);
    }

    return dataTotal;
}

void swapVariable(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int dataTotal, int *dataArray)
{
    for (int i = 0; i < dataTotal - 1; i++)
    {
        for (int j = 0; j < dataTotal - i - 1; j++)
        {
            if (dataArray[j] > dataArray[j + 1])
            {
                swapVariable(dataArray + j, dataArray + (j + 1));
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int tmp[32] = {
        0,
    };
    int num = 0;

    num = readInput(tmp);

    int *arr = malloc(sizeof(int) * num);
    if (arr != NULL)
    {

        for (int i = 0; i < num; i++)
        {
            arr[i] = tmp[i];
        }

        bubbleSort(num, arr);

        for (int i = 0; i < num; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);
    }

    return 0;
}