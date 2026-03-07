#include <stdio.h>


int inverse(int arr[], int debut, int getSize){
    
    if(debut >= getSize){
        return 0;
    }
    int temp = arr[debut];
    arr[debut] = arr[getSize];
    arr[getSize] = temp;
    
    return inverse(arr , debut+1, getSize-1);
}


int main(){
    int size;
    
    printf("Donner une Size :");
    scanf("%d",&size);
    
    int arr[size];
        
    for(int i =0; i<size; i++){
        printf("%d)===>", i+1);
        scanf("%d", &arr[i]);
    }    
    inverse(arr , 0, size-1);
    
    // affichage 
    printf("{");
    
    for(int i =0; i<size; i++){
        printf("%d , ", arr[i]);
    }
     printf("}");  
    return 0;
}