#include <stdio.h>
#include <stdlib.h>

void push(int *n, int size){
    int i =0;
    printf("===> push the numbers in the array : \n");
    while(i<size){
        printf("write the %d in the array : ", i+1);
        scanf("%d", &n[i]);
        i++;
    }
}

void maxValue(int *n, int size){
    int i =1, max = n[0];
    while(i<size){
        if(n[i]>max){
            max = n[i];
        }
        i++;
    }
    printf("the max Value : %d", max);
};

void min(int *n, int size){
    int i=1, min = n[0];
    
    while(i<size){
        if(n[i] < min){
            min = n[i];
        }
        i++;
    }
    printf("\nthe min value : %d", min);
}

int main() {
  int size;
  
  printf("give this array a size: ");
  scanf("%d", &size);
  
  int *n = malloc(sizeof(int) * size);
  if(n == NULL){
      printf("Error");
      return EXIT_FAILURE;
  }
  push(n, size);
  maxValue(n, size);
  min(n, size);
  free(n);
    return 0;
}