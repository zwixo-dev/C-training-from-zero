#include <stdio.h>

// push function
void push(int tab[], int size){
    int i = 0;
    while(i< size){
        printf("Enter value for element %d: ", i+1);
        scanf("%d", &tab[i]);
        i++;
    }
}

// show function
void show(int tab[], int size){
    int i = 0;
    printf("===============Array values=====================\n");
    while(i<size){
        printf("%d ,", tab[i]);
        i++;
    }
    printf("\n================================================\n");
}

//total 
void total(int tab[], int size){
    int i = 0, total = 0;
     while(i<size){
         total += tab[i];
         i++;
     }
     printf("The total sum of array elements is: %d\n", total);
     printf("\n");
}
// max and min value
void MaxAndMain(int tab[], int size){
    int max = tab[0];
    int min = tab[0];

    for (int i = 1; i < size; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
        if (tab[i] < min) {
            min = tab[i];
        }
    }

    printf("\n=====>Maximum value in the array: %d\n", max);
    printf("=====>Minimum value in the array: %d\n", min);   
}
void search(int tab[], int size){
 int srch;
 printf("Enter a number to search in the array:"); 
 scanf("%d",&srch);
 int i = 0;
 while(i< size){
     if(tab[i] == srch){
         printf("Number %d found at position %d.",srch, i+1); 
         return;
     }
     i++;}
     printf("Number %d does not exist in the array.", srch);
 }
int main() {
    int size;
    printf("give the array a size : ");
    scanf("%d", &size);
    int tab[size];
    // 
    if(size!= 0){
            // push function
    push(tab, size);
    // show function
    show(tab, size);
    // calculate total
    total(tab, size);
    // max value and min value
    MaxAndMain(tab, size);
    // search value
    search(tab, size);
    }  else{printf("Sorry, the array size must be at least 1.");}
    return 0;
}