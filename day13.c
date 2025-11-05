#include <stdio.h>

int main() {
    int num1, num2, sum=0;
    int *val1, *val2;
    printf("write the first value: ");
    scanf("%d", &num1);
    printf("write the second value: ");
    scanf("%d", &num2);
    
    val1 = &num1; 
    val2 = &num2;
    sum = *val1 + *val2;
    printf("sum : %d", sum);
    
    return 0;
}