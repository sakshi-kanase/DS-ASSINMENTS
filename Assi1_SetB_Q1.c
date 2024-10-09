// Write a C program to read the data from the file “employee.txt” which contains empno and empname and sort the data on names alphabetically (use strcmp) using Bubble Sort.

#include <stdio.h>
#include <string.h>

typedef struct {
    int empno;
    char empname[20];
} Employee;

void bubbleSort(Employee arr[], int n) {
    Employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].empname, arr[j + 1].empname) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printEmployees(Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].empno, arr[i].empname);
    }
}

int main() {
    FILE *f = fopen("employee.txt", "r");
    if (!f) {
        printf("Could not open file!\n");
        return 1;
    }
    
    Employee employees[100];
    int n = 0;

    while (fscanf(f, "%d %s", &employees[n].empno, employees[n].empname) != EOF) {
        n++;
    }
    fclose(f);

    bubbleSort(employees, n);
    printf("Sorted Employees: \n");
    printEmployees(employees, n);

    return 0;
}