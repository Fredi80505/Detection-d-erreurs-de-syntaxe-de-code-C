#include <stdio.h>

int main() {
    int arr[100], size, num, pos, choice;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Choose insertion option:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at a middle position\n");
    printf("3. Insert at the end\n");
    scanf("%d", &choice);
    
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    
    if (choice == 1) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = num;
        size++;
    } else if (choice == 2) {
        printf("Enter position (0 to %d): ", size);
        scanf("%d", &pos);
        if (pos < 0 || pos > size) {
            printf("Invalid position!\n");
            return 1;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = num;
        size++;
    } else if (choice == 3) {
        arr[size] = num;
        size++;
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
