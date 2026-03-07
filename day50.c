#include <stdio.h>


int orderCoissant(int arr[], int size){
     if (size <= 1) {
        return 1; 
    }
    
if(arr[size-1] >= arr[size-2] && orderCoissant(arr, size-1)){
        return 1;
    } else{
        return 0;
    }

}


int main(){
    
    int size;
    printf("Donner une Size : ");
    scanf("%d",&size );
    
    if(size <=1){
        return 0;
    }
    
    int arr[size];
    
    for(int i = 0; i<size ; i++){
        printf("%d) ==> ", i+1);
        scanf("%d", &arr[i]);
    }

    if(orderCoissant(arr, size) != 0){
        printf("Verification correct !");
    } else{
        printf("Verification pas correct !");
    }
}