// basic
// writing a function that can calculate the average of two numbers

#include <stdio.h>

// moyenne function :
float moyenne(float num1, float num2) {
    return ((num1 + num2) / 2);
}

int main() {
    float num1, num2;

    printf("Write the first number: ");
    scanf("%f", &num1);

    printf("Write the second number: ");
    scanf("%f", &num2);

    printf("Result = %f\n", moyenne(num1, num2));

    return 0;
}
