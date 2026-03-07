#include <stdio.h>


int grandValeur(int arr[], int getSize){
    if(getSize == 0){
        return 0;
    }

    if(arr[getSize-1] > grandValeur(arr, getSize-1)){
        return arr[getSize - 1];
    }
    return grandValeur(arr, getSize-1);
}


int main(){
    int size;
    
    printf("Donner une Size :");
    scanf("%d", &size);
    
    if(size == 0){
        return 0;
    }
    
    int arr[size];
    
    for(int i=0;i<size ;i++){
        printf("%d==>", i+1);
        scanf("%d", &arr[i]);
    }    
    
    printf("le plus grand element = %d", grandValeur(arr, size));
    
    return 0;
}