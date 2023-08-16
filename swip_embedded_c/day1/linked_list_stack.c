#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;           // Pointer to the top of stack

// Insert item into the stack
void push(int item) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

// Get the top element from the stack
int pop() {
    int dataTop;

    if (top == NULL) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    
    dataTop = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);

    return dataTop;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    push(40);
    push(50);

    while (top != NULL) {
        printf("Popped element: %d\n", pop());
    }

    return 0;
}