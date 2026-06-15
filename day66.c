#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double array_mean(int size, double *arr){
    double count = 0.0;
    
    for(int i=0; i<size; i++){
        count += arr[i];
    }
    
    return count / size;
}

double array_median(int size, double *arr){
    double temp;
    double tempArr[size];
    
    for(int i = 0; i < size; i++) {
    tempArr[i] = arr[i];
    }

    // sorting
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) { 
            if (tempArr[i] > tempArr[j]) {   
                temp = tempArr[i]; 
                tempArr[i] = tempArr[j];
                tempArr[j] = temp;
            }
        }
    }
    
    int middle = size / 2; 
    
    if (size % 2 != 0) {
        return tempArr[middle];
    } else {
        return (tempArr[middle - 1] + tempArr[middle]) / 2.0; 
    }
}

// array_variance
double array_variance(int size, double *arr){
    if (size <= 1) {
        return 0.0; 
    }
    
    double mean = array_mean(size, arr);
    
    double sum_of_subtruct_squares = 0.0;
    
    for(int i=0; i<size; i++){
        sum_of_subtruct_squares+= (arr[i]-mean) * (arr[i]-mean);
    }
    
    return sum_of_subtruct_squares/(size-1);
}
// array_stddev
double array_stddev(int size, double *arr){
    
    double variance = array_variance(size, arr); 
    
    return sqrt(variance);
}

// array mode 
double array_mode(int size, double *arr) {
    int count = 0;
    int maxCount = 0; 
    double maxValue = 0.0;
    
    for(int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        
        if(count > maxCount) {
            maxCount = count;
            maxValue = arr[i];
        }
    }
    
    if(maxCount == 1) {
        return -1.0; 
    }
    
    return maxValue;
}

int main(){
    
    int size ; 
    
    printf("give it a Size : ");
    scanf("%d", &size);
    
    if(size<=0){
        return 0;
    }
    
    double *arr = malloc(size * sizeof(double));
    
    for(int i=0; i<size; i++){
        printf("%d) ==> ", i);
        scanf("%lf", &arr[i]);
    }    
    
    
    printf("\nmean = %lf\n", array_mean(size, arr));
    printf("\nmedian =%lf", array_median(size, arr));
    
    printf("\nvar = %lf", array_variance(size, arr));
    
    printf("\n mode = %lf",array_mode(size, arr));
    
    
    free(arr);
    return 0;
}