#include <stdio.h>

void deleteElement(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position! Please enter a position between 1 and %d.\n", *size);
        return;
    }
    
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[100], size, pos;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the position of the element to delete (1-based index): ");
    scanf("%d", &pos);
    
    deleteElement(arr, &size, pos - 1);
    
    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}