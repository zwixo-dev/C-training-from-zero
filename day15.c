#include <stdio.h>

void pushing(int getArr[], int *p){
    int i = 0;
    while(i < *p){
        printf("write the %d value in the array: ", i+1);
        scanf("%d", &getArr[i]);
        i++;
    }
}

void desplay(int getArr[], int *p){
    printf("============Display your array============\n");
    int i = 0;
    while(i<*p){
        printf("%d | ",getArr[i]);
        i++;
    }
}

void sum(int getArr[], int *p){
    printf("\n=======Calculate the sum=======\n");
    int i =0, sum =0;
    while(i<*p){
        sum += getArr[i];
        i++;
    }
    printf("The sum : %d", sum);
}

void even(int getArr[], int *p){
    int i =0, even =0;
    while(i<*p){
        if(getArr[i]%2==0){
            even +=1;
        }
        i++;
    }
    printf("\nEven numbers in this array: %d\n", even);
}

int inverseArr(int getArr[], int *p){
    printf("Inverse the array\n");
    int i =*p-1;
    while(i>=0){
        printf("%d |", getArr[i]);
        i--;
    }
}

int main(){
    int N;
    printf("write a number to complete the execution: ");
    scanf("%d", &N);
    if(N<=0){
        printf("Go ahead and re-run with number > 0\n");
    }
    int *p;
    p=&N;
    int Arr[*p];
    pushing(Arr, p);
    desplay(Arr, p);
    sum(Arr, p);
    even(Arr, p);
    inverseArr(Arr, p);


    return 0;
    
}