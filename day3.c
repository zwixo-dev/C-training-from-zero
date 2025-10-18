#include <stdio.h>

// Function to calculate the sum of array elements
int sommeTab(int Tab[], int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += Tab[i];   
    }
    return sum;
}

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int Tab[N];
    int i = 0;

    printf("====================================\n");

    while (i < N) {
        printf("Element %d: ", i + 1);
        scanf("%d", &Tab[i]);
        i++;
    }

    printf("Result = %d\n", sommeTab(Tab, N));

    return 0;
}