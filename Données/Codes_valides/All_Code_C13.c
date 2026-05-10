#include <stdio.h>

// Function to find the missing number
int findMissingNumber(int arr[], int n) {
    int totalSum = (n * (n + 1)) / 2;  // Sum of first n natural numbers
    int actualSum = 0;

    // Calculate sum of elements in the array
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    // The missing number is the difference between total sum and actual sum
    return totalSum - actualSum;
}

int main() {
    int n;

    // Input: Number of elements in the full sequence (1 to n)
    printf("Enter the total number of elements (including missing one): ");
    scanf("%d", &n);

    int arr[n - 1];

    // Input: Array elements
    printf("Enter %d elements (excluding one missing number):\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and display the missing number
    int missing = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missing);

    return 0;
}
