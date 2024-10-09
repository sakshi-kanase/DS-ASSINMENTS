// Write a C program to sort a random array of n integers (value of n accepted from user) by using Bubble Sort algorithm in ascending order

#include <stdio.h>
#include <conio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    
    printf("Original Array: ");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
