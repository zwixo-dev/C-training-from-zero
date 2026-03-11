#include <stdio.h>


int compte(int getArr[], int getSize, int val){
    if(getSize <=0){
        return 0;
    }
    
    if(getArr[getSize -1] == val ){
        return 1 + compte(getArr , getSize-1, val);
    }
    
    return (0 + compte(getArr, getSize-1 , val));
}

int main(){
    int size, val;
    printf("Donner une Size : ");
    scanf("%d", &size);
    
    if(size <=0){
        return 0;    
    }
    
    int arr[size];
    
    for(int i = 0; i<size ; i++){
        printf("%d)==> ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Entre val : ");
    scanf("%d",&val);
    
    
    printf("result = %d",compte(arr, size, val));
    return 0;
}