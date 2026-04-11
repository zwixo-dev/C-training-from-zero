#include <stdio.h>
#include <stdlib.h>


// =====================================       AVL in tree        =====================================


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;


Node *cree(int getVal){
    Node *newNode =  malloc(sizeof(Node));
    if(newNode==NULL) return NULL;

    newNode->data = getVal;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


Node *insert(Node *root, int getVal){
    if(root==NULL){
        return cree(getVal);
    }
    
    if(getVal<root->data){
        root->left = insert(root->left, getVal);
    }   else if(getVal<root->data){
        root->right = insert(root->right, getVal);
    } 

    return root;

}

// rotation Left Left

Node *rotationLL(Node *root){

    Node *child = root->left;
    root->left = child->right;

    child->right = root;

    return child;
}


// rotattion Right Right

Node *rotationRR(Node *root){

    Node *child = root->right;
    root->right = child->left;

    child->left = root;

    return child;
}




int main(){

    Node *root = NULL;


    return 0;
}