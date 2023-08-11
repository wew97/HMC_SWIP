#include <stdio.h>

int callCount = 0;                          // Number of calls for Fibonacci function
long int fibonacci(int number);             // Fibonacci algorithm using recursion
long int fibonacciByLoop(int number);       // Fibonacci algorithm using loop

int main(void)
{
    int i;
    int nthTerm;                            // The nth index of Fibonacci series
    long nthTermValue;                      // The nth value of Fibonacci series

    printf("Enter a number up to which Fibonacci series are computed: ");
    scanf("%d", &nthTerm);

    printf("\nFibonacci series computed by recursion.\n");
    printf(" Fib\t\tValue\t\t# of Calls\n");
    for(i = 0; i < nthTerm + 1; i++) {
        callCount = 0;                      // Initialize it to zero to count # of calls for each Fib(i)
        nthTermValue = fibonacci(i);
        printf("Fib(%d)\t\t   %ld\t\t   %d\n", i, nthTermValue, callCount);
    }

    printf("\nFibonacci series computed by loop.\n");
    printf(" Fib\t\tValue\t\t# of Calls\n");
    for(i = 0; i < nthTerm + 1; i++) {
        callCount = 0;                      // Initialize it to zero to count # of calls for each Fib(i)
        nthTermValue = fibonacciByLoop(i);
        printf("Fib(%d)\t\t   %ld\t\t   %d\n", i, nthTermValue, callCount);
    }
}

long int fibonacci(int number)
{
    callCount++;
    
    if (number == 0) {
        return 0;
    }

    if (number == 1 || number == 2) {
        return 1;
    }

    return fibonacci(number-1) + fibonacci(number-2);
}

long int fibonacciByLoop(int number)
{
    int i, firstTerm = 0, secondTerm = 1, thirdTerm;

    callCount++;
    
    if (number == 0) {
        return 0;
    }

    if (number == 1 || number == 2) {
        return 1;
    }

    for(i = 0; i < number - 1; i++) {
        thirdTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = thirdTerm;
    }

    return thirdTerm;
}