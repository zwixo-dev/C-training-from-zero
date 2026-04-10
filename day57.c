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
        return NULL;
    }
}

Node *insert(Node *root, int getVal){
    if(root==NULL){
        return cree(getVal);
    }

    if(getVal < root->data){
        root->left = insert(root->left, getVal);
    } else if(getVal > root->data){
        root->right = insert(root->right, getVal);
    } 

    return root;
}



int main(){

    int size, choice, i;

    do{
        printf("\n1°Insert");
        printf("\n2° all Noedes Total");
        printf("\n3° all  Childs Total ");
        printf("\n4° all Internal Nodes Total");

        printf("choice : ");

        scanf("%d",&choice);


    switch (choice){
            case 1:
            break;

            default:
                printf("Cmd Not found");
            break;
        }

    }while(choice != 0 );

        
    return 0;
}