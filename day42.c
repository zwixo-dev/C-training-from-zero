#include <stdio.h>
#include <stdlib.h>

// initai treee in c programming 

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

// create
Node *cree(int val){
    Node *newNode = malloc(sizeof(Node));
    
    if(newNode == NULL){
        return 0;
    }
    
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// insert 
Node *insert(Node *root , int val){
    if(root ==  NULL){
        return cree(val);
    }
    
    Node *current = root;
    Node *parent = NULL;
    
    while(current != NULL){
        parent = current;
        if(val<current->data){
            current = current->left;
        } else if(val > current->data){
            current = current->right;
        } else{
            return root;
        }
    }
    
    if(val < parent->data){
        parent->left = cree(val);    
    } else{
        parent->right = cree(val);
    }
    
}

int main(){
    Node *root = NULL;
    int i=0, x, val; 
    
    printf("Give the tree a size : ");
    scanf("%d", &x);
    
    if(x>=1){
        while(i<x){
            printf("%d)==> ", i+1);
            scanf("%d", &val);
            root = insert(root, val);
            i++;
        }
    }
    
    return 0;
}