// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void felling(int *mrtx, int rws, int cls){
    int i = 0, j = 0;
    while(i<rws){
     j = 0;
     while(j<cls){
         printf("the vaLue [%d][%d] : ", i, j);
         scanf("%d", &mrtx[i*cls+j]);
         j++;
     }
     printf("\n");
     i++;
    }
}

void display(int *mrtx, int rws, int cls){
    int i = 0, j = 0;
    while(i<rws){
     j = 0;
     while(j<cls){
         printf(" %d  ", mrtx[i*cls+j]);
         j++;
     }
     printf("\n");
     i++;
    }
}

void sum(int *mrtxA, int *mrtxB, int rws, int cls){
    int *newMatrix = malloc( rws * cls * sizeof(int));
    
    if(newMatrix == NULL){
        return;
    }
    
    int i = 0, j = 0;
    while(i<rws){
    j  = 0;
    while(j < cls){
            int index = i * cls + j;
            newMatrix[index] = mrtxA[index] + mrtxB[index];
        j++;
    }
        i++;
    }
    display(newMatrix, rws, cls);
    free(newMatrix);
}

int main(){
    int rws1, cls1, rws2,cls2;
    printf("==== Note : Matrix[i][j] = MatrixA[i][j] + MatrixB[i][j] ====\n");
    printf("Matrix A : \n");
    printf("rows : ");
    scanf("%d", &rws1);
    printf("columns : ");
    scanf("%d", &cls1);
    
    printf("Matrix B : \n");
    printf("rows : ");
    scanf("%d", &rws2);
    printf("columns : ");
    scanf("%d", &cls2);
    if(rws1!=rws2 || cls1!=cls2){
        printf("Read the Note !");
        return 1;
    }
    
    int *matrixA = malloc(rws1 * cls1 *sizeof(int));
    int *matrixB = malloc(rws2 * cls2 *sizeof(int));
    
    printf("\n====> matrixA\n");
    felling(matrixA, rws1,cls1);
    printf("\n====> matrixB\n");
    felling(matrixB, rws2,cls2);
    
    printf("\n====>matrixA\n");
    display(matrixA, rws1,cls1);
    printf("\n====>matrixB\n");
    display(matrixB, rws2,cls2);
     printf("MatrixA + matrixB ==>\n");
    sum(matrixA, matrixB,rws2,cls2);
   
    
      free(matrixA);
      free(matrixB);
      
    return 0;
}