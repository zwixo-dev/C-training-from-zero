#include <stdio.h>
#include <stdlib.h>


void felling(int *mtrx, int rws , int cls){
    int i = 0, j = 0;
    
    while(i<rws){
        j  = 0;
        while(j<cls){
            printf("==>[%d][%d]", i,j);
            scanf("%d",&mtrx[i * cls +j]);
            j++;
        }
        i++;
    }
    
}

void display(int *mtrx, int rws, int cls){
    int i = 0, j = 0;
    while(i<rws){
        j = 0;
        while(j<cls){
            printf("  %d ", mtrx[i * cls + j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int multiplyMatrix(int *mtrxA, int *mtrxB, int rws1, int cls1, int cls2) {
    // Result matrix size: rows of A (rws1) x columns of B (cls2)
    int *mtrx = malloc(rws1 * cls2 * sizeof(int));
    
    if(mtrx== NULL){
      return 0;
    }
    
    int i = 0;
    while (i < rws1) {
        int j = 0; // Reset j for every new row
        while (j < cls2) {
            mtrx[i * cls2 + j] = 0;
            int k = 0; // Reset k for every new element
            while (k < cls1) { // k iterates through A's columns / B's rows
                mtrx[i * cls2 + j] += mtrxA[i * cls1 + k] * mtrxB[k * cls2 + j];
                k++;
            }
            j++;
        }
        i++;
    }

    display(mtrx, rws1, cls2);
    free(mtrx);
}



int main() {
    int rws1, rws2, cls1, cls2;
    
    printf("Matrix A \nrows: "); scanf("%d", &rws1);
    printf("columns: "); scanf("%d", &cls1);
    printf("Matrix B \nrows: "); scanf("%d", &rws2);
    printf("columns: "); scanf("%d", &cls2); 
    
    // Correct condition for matrix multiplication
    if (cls1 != rws2) {
       printf("Error: Matrix A columns must match Matrix B rows!\n");
       return 1; 
    }
    
    int *matrixA = malloc(rws1 * cls1 * sizeof(int));
    int *matrixB = malloc(rws2 * cls2 * sizeof(int));
    
    
    if(matrixA == NULL || matrixB == NULL){
      return 0;
    }
    
    printf("\nMatrix A:\n");
    felling(matrixA, rws1, cls1);
    
    printf("\nMatrix B:\n");
    felling(matrixB, rws2, cls2); 

    printf("\nMatrix A:\n");
    display(matrixA, rws1, cls1);
    
    printf("\nMatrix B:\n");
    display(matrixB, rws2, cls2);

    printf("\nResult of nMatrixA * nMatrixB:\n");
    multiplyMatrix(matrixA, matrixB, rws1, cls1, cls2);

    free(matrixA);
    free(matrixB);
    return 0;
}