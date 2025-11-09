#include <stdio.h>

void max(int getArr[], int *p){
    int max = getArr[0];
    int i =1;
    while(i<*p){
        if(getArr[i] > max){
            max = getArr[i];
        }
        i++;
    }
    printf("the max value : %d", max);
}

void min(int getArr[], int *p){
    int min = getArr[0];
    int i =1;
    while(i<*p){
        if(getArr[i] < min){
            min = getArr[i];
        }
        i++;
    }
    printf("\nthe min value : %d", min);
}

int main() {
    int N; 
    printf("write the size of tyhe array : ");
    scanf("%d", &N);
    
    int *p;
    p = &N;
    int A[*p];
    int i =0;
    
    while(i<*p){
        printf("write the %d value : ", i+1);
        scanf("%d", &A[i]);
        i++;
    }
    
    max(A, p);
    min(A, p);
    return 0;
}