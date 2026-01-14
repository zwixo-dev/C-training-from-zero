#include <stdio.h>
#include <stdlib.h>


void felling(int *mtrx, int rws, int cls) {
	int i = 0, j = 0;
	while(i<rws) {
		j =0;
		while(j < cls) {
			printf("==>[%d][%d] : ", i, j);
			scanf("%d", &mtrx[i * cls + j]);
			j++;
		}
		i++;
	}
}

void display(int *mtrx, int rws, int cls) {
	int i = 0, j =0;
	while(i<rws) {
		j = 0;
		while(j<cls) {
			printf("%d ", mtrx[i * cls + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// Sparse representation

int SparseRepresentation(int *mtrx, int rws, int cls){
   

    
    int i =0, j = 0, count =0;
    // nan zero number mtrx[i *cls +j] !=0
    while(i<rws){
        j =0;
        while(j<cls){
            if(mtrx[i * cls + j] !=0){
                count++;
            }
            j++;
        }
        i++;
    }
    
     printf(" %d numbers ! = 0\n", count); 
     
     int *sparse = malloc(count * 3  * sizeof(int)); 
    
        if(sparse ==NULL) return 0;
        
    
    // 
    int idx = 0; i = 0 , j =0;
    
    while(i<rws){
        j =0;
        while(j<cls){
            if(mtrx[i * cls + j] !=0){
                sparse[idx * 3 + 0] = i; // rows 
                sparse[idx * 3 + 1] = j; // columns
                sparse[idx * 3 + 2] = mtrx[i * cls + j]; // the value 
                idx++;
            }
            j++;
        }
        i++;
    }
    // display SparseRepresentation
    
    printf("Sparse Representation:\n");
    for(int k = 0; k < count; k++){
        printf("%d %d %d\n", sparse[k*3], sparse[k*3+1], sparse[k*3+2]);
    }
    
    free(sparse);
    return 0;
}   



int main() {

	int rws, cls;
	printf("Matrix : \n");
	printf("rows : ");
	scanf("%d", &rws);
	printf("columns : ");
	scanf("%d", &cls);

	int *mtrx = malloc(rws * cls * sizeof(int));

	if(mtrx == NULL) {
		return EXIT_FAILURE;
	}

	felling(mtrx, rws, cls);
	display(mtrx, rws, cls); SparseRepresentation(mtrx, rws, cls); 
	free(mtrx);
	return 0;
}