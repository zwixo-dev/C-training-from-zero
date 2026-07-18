#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void felling(int size, double *arr){
    printf("\nFell your Vectors :\n");
    
    for(int i=0; i<size; i++){
        printf("|%d|", i);
        scanf("%lf", &arr[i]);
    }
    
}
double vector_magnitude(int size, double *vector){
    
    if(size<=0 || vector == NULL) return 0.0;
    
    double vectors_result = 0.0;
    
    for(int i=0; i<size; i++){
        vectors_result += vector[i]*vector[i];
    }
    
    return sqrt(vectors_result);
}

void vector_normalize(int size, double *vector, double *result_vectors){
    if (size<=0 || vector == NULL || result_vectors == NULL) return;

    double Vmagnitude = vector_magnitude(size, vector);
    
    for(int i=0; i<size; i++){
        result_vectors[i] = ( vector[i] / Vmagnitude);
    }
}

double vector_dot_product(int size, double *vectorA, double *vectorB){
    
    if(size<=0 || vectorA == NULL || vectorB == NULL) return 0.0;
    
    double vector_dot_product_result = 0.0;
    
    for(int i=0; i<size; i++){
        vector_dot_product_result += vectorA[i] * vectorB[i]; 
    }
    
    return vector_dot_product_result;
}

void vector_cross_product(double *vector1, double *vector2, double *result){
    
    
    
}

// display 
void display(int size, double *arr){
    
    for(int i=0; i<size; i++){
        printf("%lf | ", arr[i]);
    }
}
int main(){
    int size;

    printf("Enter the size : ");
    scanf("%d", &size);
    
    double *arr = malloc(size * sizeof(double) );
    double *arr_b = malloc(size * sizeof(double));
    double *result = malloc(size * sizeof(double) );
    
    printf("\nvectors A \n");
    felling(size, arr);
    printf("\nvectors B \n");
    felling(size, arr_b);
    printf("\nVectors A");
    display(size, arr);
    printf("\nVectors A");
    display(size, arr_b);
    
    printf("\n===================== execution =====================\n");
    
    printf("vector_magnitude : %lf ", vector_magnitude(size, arr));
    printf("\nvector_normalize\n");
    vector_normalize(size, arr, result);
    display(size, result);
    
    printf("vector_dot_product = %lf", vector_dot_product(size, arr, arr_b));
    
    
    
    
    
    free(arr);
    return 0;
}