// Write a C program to sort the elements by initializing the array (e.g. int A[5] = {11, 12,15, 16, 17}) using Quick Sort

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element is chosen as the last element
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;            // Increment index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the elements of the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initialize the array with elements
    int A[5] = {11, 12, 15, 16, 17};
    int n = sizeof(A) / sizeof(A[0]);

    // Print the original array
    printf("Original Array: ");
    printArray(A, n);

    // Perform Quick Sort
    quickSort(A, 0, n - 1);

    // Print the sorted array
    printf("Sorted Array using Quick Sort: ");
    printArray(A, n);

    return 0;
}