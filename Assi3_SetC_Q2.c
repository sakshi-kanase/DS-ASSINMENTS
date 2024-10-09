// Write a C program to accept n elements from user store it in an array. 
// Accept a value from the user and use recursive binary search method to check whether the value is present in array ornot

#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        } else {
            return binarySearch(arr, mid + 1, right, x);
        }
    }
    return -1;
}

int main() {
    int n, i, x;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements in sorted order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the search element: ");
    scanf("%d", &x);
    
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element %d is present at index %d.\n", x, result);
    } else {
        printf("Element %d is not present in the array.\n", x);
    }
    
    return 0;
}