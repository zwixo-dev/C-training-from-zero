#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, i =0; 
    int *n, *m, *r; // r = rsult array 
    printf("give the first array a ==N== size: ");
    scanf("%d", &N);
    printf("give the first array a ==M== size: ");
    scanf("%d", &M);
    
    n = malloc(sizeof(int) * N); m = malloc(sizeof(int)*M); r = malloc(sizeof(int) * (N + M));
    
    if(n== NULL || m == NULL || r == NULL){
        printf("Error");
        return EXIT_FAILURE;
    }
    
    printf("\n==>complete the first Array \n\n");
    
    while(i<N){
        printf("write the %d in the array: ", i+1);
        scanf("%d", &n[i]);
        i++;
    }
    
    printf("\n==> complete the second Array \n\n");
    i=0;
    while(i<M){
        printf("write the %d in the array: ", i+1);
        scanf("%d", &m[i]);
        i++;
    }
    
    // Copy all elements of n
    for (i = 0; i < N; i++) {
        r[i] = n[i];
    }

    // Add all elements of m after n
    for (i = 0; i < M; i++) {
        r[N + i] = m[i];
    }
    
    printf("\n==> after adding the the second array in the first one\n\n");
    
    i=0;
    while(i<N+M){
        printf("%d", r[i]);
        i++;
    }
    free(n); free(m); free(r);
    return 0;
}