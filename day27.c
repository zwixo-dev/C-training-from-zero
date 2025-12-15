#include <stdio.h>
#include <stdlib.h>


void fillArray(int *arr, int size){
    printf("Feeling arr...\n");
    int i =0;
    while(i<size){
        printf("%d) => ", i+1);
        scanf("%d",  &arr[i]);
        i++;
    }
}

void even(int *arr, int size){
    printf("Even .. \n");
    int i =0;
    while(i<size){
        if(arr[i]%2==0){
            printf("%d | ", arr[i]);
        }
        i++;
    }
    printf("\n");
}

void odd(int *arr, int size){
        printf("Odd .. \n");
    int i =0;
    while(i<size){
        if(arr[i]%2!=0){
            printf("%d | ", arr[i]);
        }
        i++;
    }
        printf("\n");
}


int main(){
    int size;
    printf("give it a size : ");
    scanf("%d", &size);
    
    if(size<=0){
        printf("give it anther size ! ");
        return 1;
    }
    
    int *arr = malloc(size * sizeof * arr);
    
    if(!arr){
        printf("Err");
        return EXIT_FAILURE;
    }

    fillArray(arr, size);
    odd(arr, size);
    even(arr, size);
    
    
    free(arr);
    
    return 0;
}