#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *cree(int getVal){
    Node *newNode = malloc(sizeof(Node));
    if(newNode==NULL){
        return 0;
    }
 
    newNode->data=getVal;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}

// inserstion 
Node *insert(Node *root, int getVal){
    if(root==NULL){
        return cree(getVal);
    }

    if(getVal<root->data){
        root->left = insert(root->left, getVal); 
    } else if(getVal>root->data){
        root->right = insert(root->right, getVal);
    }
    
    return root;
}

// recherche
int search(Node *root, int getVal){
    if(root==NULL){
        printf("la valeur n'exist pas !");
        return 0;
    }
    
    if(getVal==root->data){
        printf("La valeur %d exist ");
    } else if(getVal<root->data){
        return search(root->left, getVal);
    } else{
        return search(root->right, getVal); 
    }
    
}

// somme tous Les noeuds
int calcul(Node *root){
    if(root==NULL){
        return 0;
    }
    
    return root->data+calcul(root->left)+calcul(root->right);
}

// somme tous les feuilles 
int calcuFils(Node *root){
    if(root==NULL){
        return 0;
    }
    
    if(root->left==NULL&&root->right==NULL){
        return root->data;
    }
    return calcuFils(root->left)+calcuFils(root->right);
}

// somme nodes internes
int calculNodes(Node *root){
    if(root==NULL){
        return 0;
    }
    
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    return root->data+calculNodes(root->left)+calculNodes(root->right);
}

//trouve le pere
int trouvePere(Node *root, int findPere){
    if(root==NULL || root->data==findPere){
        return 0;
    }
    
    if( (root->left!=NULL && root->left->data==findPere) 
    || (root->right!=NULL && root->right->data==findPere)){
        printf("le pere d %d c'est %d ", findPere, root->data);
    }
    trouvePere(root->left, findPere);
    trouvePere(root->right, findPere);
}

// EVEN numbers
int isEven(Node *root){
    if(root==NULL){
        return 0;
    }
    
    if(root->data%2==0){
        printf("nombre pair =<%d>=\n", root->data);
    }
    isEven(root->left);
    isEven(root->right);
}

// afficer les noauds a distnac k 

int distanceK(Node *root, int getK){
    if(root==NULL || getK<0){
        printf("Invalid distance");
        return 0;
    }
    
    if(getK==0){
        printf("\nles Noauds a distance k  : ");
        printf("%d", root->data);
        return 0;
    }
    
    distanceK(root->left, getK-1);
    distanceK(root->right, getK-1);
}

int main(){
    Node *root=NULL;
    int choice, val, size, findVal, i;    
    
    do{
        printf("\n1)Insert");
        printf("\n2)Search");
        printf("\n3)Somme tous les noeuds");
        printf("\n4)Somme tous les feuilles");
        printf("\n5)somme nodes internes");
        printf("\n6)trouve le pere d'une valeurs");
        printf("\n7)Les nombres pair");
        printf("\n8)Les noeuds a distance k");
        printf("\nVotre choix : ");
        scanf("%d", &choice);
        
        switch(choice){
        
            case 1:
                i=0;
                printf("Donner une Size : ");
                scanf("%d", &size);
                if(size<=0) printf("entrer un size > %d", size);
                
                while(i<size){
                    printf("%d ==> ", i+1);
                    scanf("%d", &val);
                    root = insert(root, val);
                    i++;
                }
            break;
            
            case 2:
                if(root==NULL){ 
                    printf("Arbre Vide");
                } else{
                printf("Chercher : ");
                scanf("%d", &findVal);
                search(root, findVal);
                }
            break;
            
            case 3:
                if(root==NULL){
                    printf("Arbre Vide");
                } 
                printf("La somme = %d", calcul(root));
            break;
            
            case 4:
                if(root==NULL){
                    printf("Arbre Vide");
                }
                printf("La somme feuilles = %d", calcuFils(root));
            break;
            
            case 5:
                if(root==NULL){
                    printf("Arbre Vide");
                }
                printf("La somme nodes internes = %d",calculNodes(root));
            break;
            
            case 6:
                if(root==NULL){
                    printf("Arbre Vide");
                }
                int pere;
                printf("Entrer une valeur : ");
                scanf("%d", &pere);
                printf("%d", trouvePere(root, pere));
            break;
            
            case 7:
                if(root==NULL){
                    return 0;
                }
                isEven(root);
            break;
            
            case 8:
                if(root==NULL){
                    return 0;    
                }
                int k;
                printf("Enter un distance k :");
                scanf("%d", &k);
                distanceK(root, k);
            break;
            
            default:
                printf("CMD not found ! ");
            break;
        }}while(choice!=0);
    
    return 0;
}