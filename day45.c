#include <stdio.h>

void draw(int nRows){

    for(int i = 0; i<nRows;i++){
        for(int j=0 ; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
    
}


int main(){
        int n;
    printf("Give it a Size : ");
    scanf("%d", &n);
    
    draw(n);
    
    return 0;
}