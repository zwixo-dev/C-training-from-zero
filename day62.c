// intro to graphs in c programming 
//EX : 

/*
Soit un graphe connexe non orienté donné par l'utilisateur :

1- Lire sa matrice d'adjacence.
2- Écrire une fonction qui renvoie le degré d’un sommet donné.
3- Écrire une fonction qui retourne le nombre d’arêtes du graphe.
4- Vérifier s’il existe une chaîne eulérienne.
5- Vérifier s’il existe un cycle eulérien.
*/



#include <stdio.h>
#include <stdlib.h>


int readMatrix_Adjc(int getSize, int matrix[getSize][getSize]){
    int i = 0, j = 0;
    
    while(i<getSize){
        j=0;
        while(j<getSize){
                printf("[%d][%d] ", i, j);
                scanf("%d", &matrix[i][j]);
                j++;
        }
        printf("\n");
        i++;
    }
    
}

void display(int getSize, int matrix[getSize][getSize]){
    int i =0, j = 0; 
    
    while(i<getSize){
        printf("| ");
        j=0;
        while(j<getSize){
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("|\n");
        i++;
    }   
    
}


int main(){
    
    int size;
    
    printf("entrez un size d'une matrice Adjc: ");
    scanf("%d", &size);
    
    if(size<=0){
        return 0;
    }
    
    int matrix[size][size];
    
    readMatrix_Adjc(size, matrix);
    printf("display adjc Matrix : \n");
    display(size, matrix);
    
    
    return 0;
}