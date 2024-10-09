// Write a C program to accept a search element for muserandusing binary search method find whether given element is present or not in the following array.
// A[10] = {1,5,7,12,13,16,17,22,24}

#include<stdio.h>
#include<conio.h>
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
    int arr[] = {1, 5, 7, 12, 13, 16, 17, 22, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    
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
