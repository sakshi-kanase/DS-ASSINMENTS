// Write a program in C to accept 5 numbers from the user and sort the numbers in ascending order by using Quicksort.

#include <stdio.h>

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
    int arr[5], i;
    
    printf("Enter 5 numbers: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, 4);
    
    printf("Sorted array: ");
    printArray(arr, 5);
    
    return 0;
}