#include <stdio.h>
#include <stdlib.h>

void fillArray(int *arr, int size) {
    int i = 0;
    printf("filling...\n");
    while (i < size) {
        printf("%d) => ", i + 1);
        scanf("%d", &arr[i]);
        i++;
    }
}

void display(int *arr, int size) {
    int i = 0;
    printf("\nDisplay:\n");
    while (i < size) {
        printf("%d | ", arr[i]);
        i++;
    }
    printf("\n");
}

int* reSize(int *arr, int *size) {
    int choice;
    printf("\nDo you want to resize the array? (1 = yes, 0 = no): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int newSize;
        printf("Give the new size: ");
        scanf("%d", &newSize);

        if (newSize <= *size) {
            printf("New size must be greater than the old size!\n");
            return arr;
        }

        int *temp = realloc(arr, newSize * sizeof *arr);
        if (!temp) {
            printf("Realloc failed!\n");
            return arr;
        }

        arr = temp;

        printf("Filling new elements...\n");
        for (int i = *size; i < newSize; i++) {
            printf("%d) => ", i + 1);
            scanf("%d", &arr[i]);
        }

        *size = newSize;
    }

    return arr;
}

int main() {
    int n;
    int *arr;

    printf("Give the array size: ");
    scanf("%d", &n);

    if (n <= 0) return 1;

    arr = malloc(n * sizeof *arr);
    if (!arr) return EXIT_FAILURE;

    fillArray(arr, n);
    display(arr, n);

    arr = reSize(arr, &n);
    display(arr, n);

    free(arr);
    return 0;
}
