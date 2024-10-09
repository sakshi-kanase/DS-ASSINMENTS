// WriteaCprogramtocreateanarrayofintegers.Acceptavaluefromuseranduselinearsearchmethod to check whether the given number is present in array or not. Display proper message in output.

#include <stdio.h>

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
    int n, i, x;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the search element: ");
    scanf("%d", &x);
    
    linearSearch(arr, n, x);
    
    return 0;
}