#include <stdio.h>

// Function definitions
float plus(float number1, float number2) {
    return number1 + number2;
}

float sub(float number1, float number2) {
    return number1 - number2;
}

float multiplication(float number1, float number2) {
    return number1 * number2;
}

float divide(float number1, float number2) {
    if (number2 == 0) {
        printf("Infinity\n");
        return 0;
    }
    return number1 / number2;
}

int main() {
    float number1, number2, result = 0;
    char opr;

    printf("Write the first number: ");
    scanf("%f", &number1);

    printf("\nChoose an operation (+, -, x, /): ");
    scanf(" %c", &opr); // Note the space before %c

    printf("\nWrite the second number: ");
    scanf("%f", &number2);

    if (opr == '+') {
        result = plus(number1, number2);
    } else if (opr == '-') {
        result = sub(number1, number2);
    } else if (opr == 'x' || opr == '*') {
        result = multiplication(number1, number2);
    } else if (opr == '/') {
        result = divide(number1, number2);
    } else {
        printf("Invalid operation!\n");
        return 1;
    }

    printf("Result: %.2f\n", result);
    return 0;
}
