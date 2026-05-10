#include<stdio.h>
#include<time.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Prints the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1: Small array
    int arr1[] = {12, 11, 13, 5, 6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Original array 1: ");
    printArray(arr1, n1);
    
    clock_t start1 = clock();
    insertionSort(arr1, n1);
    clock_t end1 = clock();
    
    printf("Sorted array 1: ");
    printArray(arr1, n1);
    printf("Time taken: %f seconds\n\n", (double)(end1 - start1)/CLOCKS_PER_SEC);

    // Test case 2: Already sorted array
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Original array 2: ");
    printArray(arr2, n2);
    
    clock_t start2 = clock();
    insertionSort(arr2, n2);
    clock_t end2 = clock();
    
    printf("Sorted array 2: ");
    printArray(arr2, n2);
    printf("Time taken: %f seconds\n\n", (double)(end2 - start2)/CLOCKS_PER_SEC);

    // Test case 3: Reverse sorted array
    int arr3[] = {9, 7, 5, 3, 1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("Original array 3: ");
    printArray(arr3, n3);
    
    clock_t start3 = clock();
    insertionSort(arr3, n3);
    clock_t end3 = clock();
    
    printf("Sorted array 3: ");
    printArray(arr3, n3);
    printf("Time taken: %f seconds\n\n", (double)(end3 - start3)/CLOCKS_PER_SEC);

    return 0;
}
