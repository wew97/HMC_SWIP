#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_NAME "input.txt"         // Input file containing matrix data
#define MAX_SIZE 1000                       // Mximum size of raw and column


int readInput(int inputData[][MAX_SIZE], int *rawSize, int *columnSize);
void swap(int* a, int* b);
void generateMatrixTranspose(int rawSize, int columnSize, int matrix[][MAX_SIZE]);
void printMatrix(int rawSize, int columnSize, int matrix[][MAX_SIZE]);

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];    
    int rawSize = 0;
    int columnSize = 0;

    if (readInput(matrix, &rawSize, &columnSize) == -1) {
        exit(1);
    }
    
    printMatrix(rawSize, columnSize, matrix);
    generateMatrixTranspose(rawSize, columnSize, matrix);
    printMatrix(columnSize, rawSize, matrix);
    

    return 0;
}

// Read input data from a file and write the data into 2-dimensional array buffer
int readInput(int inputData[][MAX_SIZE], int *rawSize, int *columnSize)
{
    FILE *fd;
    int i, j;
    int rSize = 0;
    int cSize = 0;
    char signCharacter; 

    fd = fopen(INPUT_FILE_NAME, "r");
	if (fd == NULL)
	{
		printf("Error: Failed to open '%s'.\n", INPUT_FILE_NAME);
		return -1;
	}

	/* read input file to get task parameters */
	fscanf(fd, "%d %c %d", &rSize, &signCharacter, &cSize);
    
    if ((rSize > MAX_SIZE) || (cSize > MAX_SIZE)) {
        printf("Error: Too big matrix in '%s'.\n", INPUT_FILE_NAME);
		return -1;
    }

	for (i = 0; i < rSize; i++) {
        for (j = 0; j < cSize; j++) {
		    fscanf(fd, "%d ", &inputData[i][j]);
        }
    }

    *rawSize = rSize;
    *columnSize = cSize;

    return 0;
}

// Swap two matrix elements
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Convert a matrix into its transpose
void generateMatrixTranspose(int rawSize, int columnSize, int matrix[][MAX_SIZE])
{
    int i, j;

    for (i = 0; i < rawSize; i++) {
        for (j = i + 1; j < columnSize; j++) {
            if (i != j) {
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
    }
}

// Display the give matrix on the screen
void printMatrix(int rawSize, int columnSize, int matrix[][MAX_SIZE])
{
    int i, j;

    printf("\n");
    for (i = 0; i < rawSize; i++) {
        for (j = 0; j < columnSize; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}