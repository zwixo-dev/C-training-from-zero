#include <stdio.h>

int main() {
    int i, j, rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop for the number of rows
    for (i = 1; i <= rows; ++i) {
        // Inner loop for printing asterisks in each row
        for (j = 1; j <= i; ++j) {
            printf("* ");
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}

// printing traingle wit how mabny rows u want
// Enter the number of rows: 10
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
// * * * * * * 
// * * * * * * * 
// * * * * * * * * 
// * * * * * * * * * 
// * * * * * * * * * * 