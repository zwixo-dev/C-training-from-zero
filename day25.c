#include <stdio.h>


void filArray(int arr[],int size){
    printf("felling .. \n");
    int i =0;
    while(i<size){
        printf("%d ) => ", i+1);
        scanf("%d", &arr[i]);
        i++;
    }
}

void display(int arr[],int size){
    printf("\n===== Display =====\n");
    int i =0;
    while(i<size){
        printf("%d | ", arr[i]);
        i++;
    }
}

void reverseArray(int arr[],int size){
    printf("\n reveersing ..\n");
    int i = 0;
    int temp;
    while(i< size/2){
    temp = arr[i];
    arr[i] = arr[size -1 - i];
    arr[size -1-i]  = temp;
    i++;
    }
}

int main(){
    
    int n;
    printf("give the Array a Size : ");
    scanf("%d", &n);
    
    if(n<=0) return 1;
    int arr[n];
    filArray(arr,n);
    display(arr,n);
    reverseArray(arr,n);
    display(arr,n);
    return 0;
}