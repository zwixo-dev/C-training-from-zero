#include <stdio.h>
#include<unistd.h>

// Enter values
void matrix(int size, int getMatrix[size][size]){
    int i = 0, k = 0;  // you had k and i confusion
    while(i < size){
        k= 0;
        while(k < size){
            printf("write the element [%d][%d]: ", i, k);
            scanf("%d", &getMatrix[i][k]);  // need & to store input
            k++;
        }
        i++;
    }
}

// display the matrix; 
void displayMatrix(int size, int getMatrix[size][size]) {
    int i = 0,  k = 0;
    while(i<size){
        k=0;
        while(k<size){
            printf("%d ", getMatrix[i][k]);
            k++;
        }
        printf("\n");
        i++;
    }
}
//sum of two Matrix

void sum(int size, int M1[size][size], int M2[size][size] ){
    int i =0, k=0, sum = 0;
    int R[size][size]; // result
    while(i<size){
        k=0;
        while(k<size){
            R[i][k] = M1[i][k]+M2[i][k];
            k++;
        }
        i++;
    }
    printf("\nThe sum of two matrix eqaul : \n");
    displayMatrix(size, R);
}

int main() {
    int size; 
    printf("⚠️ Your matrix should be for now 2 columns & rows\n");
    printf("write the number 2 to complete the process: ");
    scanf("%d", &size);
    printf("checking process ...\n");
    sleep(3);
    if(size == 0 || size > 2 || size<2){
        printf("For now this programme doesn't accept more or less than 2 rows and columns!\n");
        return 0;  // stop execution
    }
    
    int A[size][size], B[size][size];  // only 2D 
    printf("====>The first matrix\n");
    matrix(size, A);  // pass size first, then array
    displayMatrix(size, A);
    
    printf("\n====>The second matrix\n");
    matrix(size, B);  // pass size first, then array
    displayMatrix(size, B);
    
    // sum 
    sleep(2);
    sum(size, A,B);
    return 0;
}
