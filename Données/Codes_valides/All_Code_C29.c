#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

// Stack structure
struct Stack {
    int items[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1; // Return an invalid value
    }
}

// Function to reverse an array using a stack
void reverseArray(int arr[], int size) {
    struct Stack s;
    initStack(&s);
    
    // Push all elements of the array onto the stack
    for (int i = 0; i < size; i++) {
        push(&s, arr[i]);
    }

    // Pop the elements from the stack into a new array
    int reversed[size];
    for (int i = 0; i < size; i++) {
        reversed[i] = pop(&s);
    }

    // Display the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", reversed[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, size);
    return 0;
}
