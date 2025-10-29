#include <stdio.h>
#include <unistd.h>
int pushing(int numbers[]){
    printf("=========== Push Your Number ===========\n");
    int i =0;
    while(i<10){
        printf("Number%d :", i+1);
        scanf("%d", &numbers[i]);
        i++;
    }
    return 0;
}

// Function to check numbers
int checking(int numbers[]) {
    printf("\nChecking Process ...\n");
    sleep(2); // sleep(2) = 2 seconds (not 2000!)

    int i = 0, pushPos = 0, pushNeg = 0, pushZeros = 0;
    int Positive[10], Negative[10], Zeros[10];

    while (i < 10) {
        if (numbers[i] > 0) {
            Positive[pushPos] = numbers[i];
            pushPos++;
        } else if (numbers[i] < 0) {
            Negative[pushNeg] = numbers[i];
            pushNeg++;
        } else {
            Zeros[pushZeros] = numbers[i];
            pushZeros++;
        }
        i++;
    }

    // Display results
    printf("\n==== Positive Numbers (%d): ", pushPos);
    for (i = 0; i < pushPos; i++) {
        printf("%d ", Positive[i]);
    }

    printf("\n==== Negative Numbers (%d): ", pushNeg);
    for (i = 0; i < pushNeg; i++) {
        printf("%d ", Negative[i]);
    }

    printf("\n==== Zeros (%d): ", pushZeros);
    for (i = 0; i < pushZeros; i++) {
        printf("%d ", Zeros[i]);
    }

    printf("\n");
    return 0;
}

int main() {
    int numbers[10];
    // pushh numbers
    pushing(numbers);
    // chicking Numbers
    checking(numbers);
    return 0;
}