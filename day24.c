#include <stdio.h>
#include <stdlib.h>

void fillArray(int *array, int n) {
    int i = 0;
    while (i < n) {
        printf("%d) => ", i + 1);
        scanf("%d", &array[i]);
        i++;
    }
}

void display(int *array, int n) {
    int i = 0;
    printf("\n=============\n");
    while (i < n) {
        printf("%d | ", array[i]);
        i++;
    }
    printf("\n");
}

int main() {
    int n;
    int *array;

    printf("give the array a size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("rewrite with a number > 0\n");
        return 1;
    }

    array = malloc(n * sizeof *array);
    if (!array) {
        return EXIT_FAILURE;
    }

    fillArray(array, n);
    display(array, n);

    free(array);
    return 0;
}
