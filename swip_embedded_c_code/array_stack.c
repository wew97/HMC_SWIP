#include <stdio.h>

#define ARRAY_MAX 1024          // Mximum size of array

int stack[ARRAY_MAX];           // Stack implemented as an array
int top = -1;                   // Index to the top of stack


// Insert item into the stack
void push(int item) {
    if (top < ARRAY_MAX) {
        stack[++top] = item;
    }
    else {
        printf("Stack is full.\n");
    }    
}

// Get the top element from the stack
int pop() {
    if (top > -1) {
        return stack[top--];
    }
    else {
        printf("Stack is empty\n");
        return -1;
    }    
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    push(40);
    push(50);

    while (top != -1) {
        printf("Popped element: %d\n", pop());
    }

    return 0;
}