// Factorial program
#include <stdio.h>

int fact(int n) {
    int i = 1, result = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int main() {
    int num;
    printf("Write a number to calculate the factorial: ");
    scanf("%d", &num);

    printf("Factorial %d! = %d\n",num, fact(num));

    return 0;
}