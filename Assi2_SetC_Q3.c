// Add the code in SETA(Q1) and SETB(Q1) to Print Time complexity for Quick sort and Merge sort.

//SetA_QuickSort_Modified_with Time comp.
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    // Time calculation start
    clock_t start, end;
    start = clock();

    quickSort(arr, 0, n - 1);

    // Time calculation end
    end = clock();

    printf("Sorted Array using Quick Sort: ");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time Complexity (Execution Time) of Quick Sort: %f seconds\n", time_taken);

    return 0;
}
*/




















//SetB_MergeSort_Modified_with Time comp.
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    // Time calculation start
    clock_t start, end;
    start = clock();

    mergeSort(arr, 0, n - 1);

    // Time calculation end
    end = clock();

    printf("Sorted Array using Merge Sort: ");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time Complexity (Execution Time) of Merge Sort: %f seconds\n", time_taken);

    return 0;
}
*/