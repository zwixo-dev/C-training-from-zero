#include <stdio.h>


int  calcul(int n){
    
    if(n==0){
        return 0;
    }
    
    return n+calcul(n-1);
}

int main(){
    int n; 
    
    printf("Enterz un Nombre : ");
    scanf("%d", &n);
    
    calcul(n);
    printf("Resulat = %d", calcul(n));
    
    return 0;
}