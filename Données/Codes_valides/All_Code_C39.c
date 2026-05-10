#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int* items;
    int top;
    int maxSize;
};

// Function to create a stack and initialize its top
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = size;
    stack->top = -1;
    stack->items = (int*)malloc(stack->maxSize * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->maxSize - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an element to the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->items[stack->top--];
}

// Function to view the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->items[stack->top];
}

// Function to display the stack elements
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Stack* stack = createStack(100); // Create a stack of size 100

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);

    printf("%d popped from stack\n", pop(stack));
    printf("Top element is %d\n", peek(stack));
    display(stack);

    // Free allocated memory
    free(stack->items);
    free(stack);

    return 0;
}
