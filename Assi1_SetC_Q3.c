// Write a C program to sort the elements by initializing the array (e.g int A[5] = {10, 20, 35, 23, 12}) usingbubble sort.

#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initialize the array with elements
    int A[5] = {10, 20, 35, 23, 12};
    int n = sizeof(A) / sizeof(A[0]);

    // Print the original array
    printf("Original Array: ");
    printArray(A, n);

    // Perform Bubble Sort
    bubbleSort(A, n);

    // Print the sorted array
    printf("Sorted Array: ");
    printArray(A, n);

    return 0;
}