// Write a C program to read the data from file 'cities.txt' containing names of 10 cities and their STD codes.
// Acceptanameofthecityfromuseranduselinearsearchalgorithmtocheckwhetherthename is present in the file and output the STD code, otherwise output “city not in thelist”.

#include <stdio.h>
#include <string.h>

typedef struct {
    char city[20];
    int std_code;
} City;

void linearSearch(City arr[], int n, char search_city[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].city, search_city) == 0) {
            printf("City: %s, STD Code: %d\n", arr[i].city, arr[i].std_code);
            return;
        }
    }
    printf("City %s is not in the list.\n", search_city);
}

int main() {
    FILE *f = fopen("cities.txt", "r");
    if (!f) {
        printf("File not found!\n");
        return 1;
    }

    City cities[10];
    int n = 0;
    while (fscanf(f, "%s %d", cities[n].city, &cities[n].std_code) != EOF) {
        n++;
    }
    fclose(f);

    char search_city[20];
    printf("Enter city name to search: ");
    scanf("%s", search_city);

    linearSearch(cities, n, search_city);

    return 0;
}