#include <stdio.h>

int calculArr(int arr[], int getSize){
    
    if(getSize==0){
        return 0;
    }
    
     return arr[getSize - 1] + calculArr(arr, getSize - 1);
}



int main(){
    int size;
    
    printf("Donner une size : ");
    scanf("%d", &size);
    
    int arr[size];

    
    for(int i =0; i<size; i++){
        printf("%d)==>", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Resultat = %d\n", calculArr(arr, size));
    
    
    
    return 0;
}