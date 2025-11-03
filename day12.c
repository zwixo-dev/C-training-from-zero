#include <stdio.h>

// Function to fill a 3D matrix
void pushing(int size, int getMtx[size][size][size]) {
    int i = 0, k = 0, z = 0;
    while (i < size) {
        k = 0;
        while (k < size) {
            z = 0;
            while (z < size) {
                printf("Write the element [%d][%d][%d]: ", i, k, z);
                scanf("%d", &getMtx[i][k][z]);
                z++;
            }
            k++;
        }
        i++;
    }
}

// Function to display a 3D matrix layer by layer
void displayMtrx(int size, int getMtx[size][size][size]) {
    int i = 0, k = 0, z = 0;
    while (i < size) {
        printf("\nLayer %d:\n", i);
        k = 0;
        while (k < size) {
            z = 0;
            while (z < size) {
                printf("%d ", getMtx[i][k][z]);
                z++;
            }
            printf("\n");
            k++;
        }
        i++;
    }
}

int main() {
    int size;

    printf("== In this program we are going to calculate the sum of two 3D matrices ==\n");
    printf("Write the number 3 to complete the process: ");
    scanf("%d", &size);

    if (size != 3) {
        printf("I said write 3 😅\n");
        return 0;
    }

    int A[size][size][size];

    printf("\n--- Fill Matrix A ---\n");
    pushing(size, A);

    printf("\n--- Displaying Matrix A ---\n");
    displayMtrx(size, A);

    return 0;
}
