// Write a C program to sort a random array of n integers by using Quick Sort algorithm in ascending order

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;
    
    while (left <= right) {
        while (arr[left] <= pivot && left <= high) {
            left++;
        }
        while (arr[right] > pivot && right >= low) {
            right--;
        }
        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[low], &arr[right]);
    return right;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    
    printf("Original Array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n-1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}