#include <stdio.h>

int main() {
    int num1, num2, z;
    int *Fvalue, *Svalue;

    printf("write the first value: ");
    scanf("%d", &num1);

    printf("write the second value: ");
    scanf("%d", &num2);

    Fvalue = &num1;
    Svalue = &num2;

    z = *Fvalue;
    *Fvalue = *Svalue;
    *Svalue = z;

    printf("the values after permutation ==> first value: %d / second value: %d", *Fvalue, *Svalue);

    return 0;
}
