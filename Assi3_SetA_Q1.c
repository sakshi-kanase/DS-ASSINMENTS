// Write a C program to accept the following array and find ‘x=26’ is whether present in array or not. A[7] = {11, 5, 45, 26, 12,34,19}

#include<stdio.h>
#include<conio.h>
void linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element %d is present at index %d.\n", x, i);
            return;
        }
    }
    printf("Element %d is not present in the array.\n", x);
}

int main() {
    int arr[] = {11, 5, 45, 26, 12, 34, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 26;
    
    linearSearch(arr, n, x);
    
    return 0;
}
