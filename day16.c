#include <stdio.h>

int main() {
    int N, M;
    printf("write the size of the first table: ");
    scanf("%d", &N);
    printf("write the size of the second table: ");
    scanf("%d", &M);
    
    int *PA, *PB, i=0, k=0;
    PA = &N; PB= &M;
    int A[*PA]; int B[*PB];
    
    printf("\n==>Write the values of the first table\n");
    while(i<*PA){
        printf("write the %d value : ", i+1);
        scanf("%d", &A[i]);
        i++;
    }
    
    printf("\n==>Write the values of the second table\n");

    while(k<*PB){
        printf("write the %d value : ", k+1);
        scanf("%d", &B[k]);
        k++;
    }
    
    printf("\n==> adding the second table to end the first table : ");
    // int add[*PA+*PB];
    // printf("%d", *PA+*PB);
    i = 0; k = 0;
    while(i<*PB){
        A[*PA+i] = B[i];
        i++;
    }
    
    //     while(k<*PB){
    //     add[*PA + k] = B[k];
    //     k++;
    // }
    
    // result
    for(int i = 0; i<*PA+*PB; i++){
        printf("%d |", A[i]);
    }
    
    
    return 0;
}