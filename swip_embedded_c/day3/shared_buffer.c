#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
// #include <semaphore.h>

#define BUFFER_SIZE 10
#define TOTAL_COMM 10

typedef struct
{
    char name[16];
    long value;
} messageStruct;

messageStruct buffer[BUFFER_SIZE];
int bufferCount = 0;
pthread_mutex_t sharedBufferMutex;

void *producerThread(void *arg)
{
    int writeIndex = 0;
    int totalWrites = 0;
    char nameToSend[5][16] = {"Alice", "Bob", "Carol", "David", "Erwin"};
    long valueToSend[5] = {1.23, 4.56, 7.89, 0.12, 3.45};
    messageStruct nextProduced;

    while (totalWrites < TOTAL_COMM)
    {
        while (bufferCount == BUFFER_SIZE)
            ; /* do nothing */

        strcpy(nextProduced.name, nameToSend[writeIndex % 5]);
        
        nextProduced.value = valueToSend[writeIndex % 5];

        buffer[writeIndex] = nextProduced;
        printf("Wrote %s and %ld into slot %d.\n", nextProduced.name, nextProduced.value, writeIndex);
        writeIndex = (writeIndex + 1) % BUFFER_SIZE;

        pthread_mutex_lock(&sharedBufferMutex);
        bufferCount++;
        pthread_mutex_unlock(&sharedBufferMutex);

        totalWrites++;
    }

    pthread_exit(NULL);
}

void *consumerThread(void *arg)
{   
    int readIndex = 0;
    int totalReads = 0;
    messageStruct nextConsumed;

    while (totalReads < TOTAL_COMM)
    {
        while (bufferCount == BUFFER_SIZE)
        ;

        buffer[readIndex] = nextConsumed;
        printf("Read %s and %ld from slot %d.\n", nextConsumed.name, nextConsumed.value, readIndex);
        readIndex = (readIndex+1) % BUFFER_SIZE;

        pthread_mutex_lock(&sharedBufferMutex);
        bufferCount++;
        pthread_mutex_unlock(&sharedBufferMutex);

        totalReads++;
    }
}

int main(void)
{
    int i;
    pthread_t threads[2];
    char threadNameA[16] = "Sender";
    char threadNameB[16] = "Receiver";

    pthread_create(&threads[0], NULL, consumerThread, threadNameA);
    pthread_create(&threads[1], NULL, producerThread, threadNameB);

    for (i = 0; i < 2; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
