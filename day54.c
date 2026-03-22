// EX : ecrire une fonction qui compte le nombre de noeuds d'un arbre binaire 

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

Node *cree(int getVal){
    Node *newNode = malloc(sizeof(Node));
    
    if(newNode == NULL){
        return 0;
    }
    
    newNode->data = getVal;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

Node *insert(Node *root , int val){
    if(root == NULL){
        return cree(val);
    }
    
    Node *current = root;
    Node *parent = NULL;
    
    while(current != NULL){
        parent = current;
        if(val < current->data){
            current = current->left;
        } else if(val > current->data){
            current = current->right;
        } else {
            return root; 
        }
    }
    
    if(val < parent->data){
        parent->left = cree(val);    
    } else {
        parent->right = cree(val);
    }

    return root;
}

int NodeCompte(Node *root){
    if(root == NULL){
        return 0;
    }
   
   return  1 + NodeCompte(root->left) + NodeCompte(root->right);
}


int main(){
    Node *root = NULL;
    
    int size, val;
        
    printf("give the tree a size ; ");    
    scanf("%d",&size);
    
    int i =0;
    while(i<size){
            printf("%d) ==> ", i+1);
            scanf("%d", &val);
            root = insert(root, val);
        i++;
    }
    
    printf("\n the number is %d ", NodeCompte(root));
     
    return 0;
}