// Write a C program to accept n elements from user store it in an array. Accept a value from the user and use Non- recursive binary search method to check whether the value is present in array or not.
// Display proper message in output.

#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
    
    int result = binarySearch(arr, n, x);
    if (result != -1) {
        printf("Element %d is present at index %d.\n", x, result);
    } else {
        printf("Element %d is not present in the array.\n", x);
    }
    
    return 0;
}