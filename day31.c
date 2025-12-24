#include <stdio.h>
#include <stdlib.h>

void filling(int *matrix, int r, int c) {
    int i  =0, j = 0;
    
    while(i<r){
        j=0;
        while(j<c){
            printf("Write the value [%d][%d] : ", i, j);
            scanf("%d", &matrix[i * c + j]);
            j++;
        }
      
        printf("\n");
        i++;
    }
}

void desplay(int *matrix, int r, int c){
    int i = 0, j =0;
    while(i<r){
        j=0;
        while(j<c){
            printf("  %d ", matrix[i * c + j]);    
            j++;
        }
          printf("\n");
        i++;
    }
}


int main(){
 int r, c;

    printf("matrix rows: ");
    scanf("%d", &r);

    printf("matrix columns: ");
    scanf("%d", &c);

    if(r <= 0 || c <= 0) {
        printf("give valid rows and columns!\n");
        return 1;
    }

    int *matrix = malloc(r * c * sizeof(int));
    if(matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    filling(matrix, r, c);
    desplay(matrix, r, c);
    return 0;
}