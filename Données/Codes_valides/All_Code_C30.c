#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX], top = -1;
    int n, i, num, reversed[MAX];

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Push elements onto the stack
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &num);
        if(top == MAX - 1) {
            printf("Stack Overflow!\n");
            return 1;
        }
        stack[++top] = num;
    }

    // Pop elements from the stack into the reversed array
    for(i = 0; i < n; i++) {
        if(top == -1) {
            printf("Stack Underflow!\n");
            return 1;
        }
        reversed[i] = stack[top--];
    }

    // Display the reversed array
    printf("Reversed list:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", reversed[i]);
    }
    printf("\n");

    return 0;
}