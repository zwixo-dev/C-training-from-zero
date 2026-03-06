#include <stdio.h>


void affichage(int n){
    if(n==0){
        return;
    }
    printf("%d \n", n);
    return affichage(n - 1);
}

int main(){
    int n;
    printf("Enterz un Nombre : ");
    scanf("%d", &n);
    affichage(n);
    
    return 0;
}