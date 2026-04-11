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

    newNode->data = getVal;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
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


int allNodesTotal(Node *root ){
    if(root == NULL ){
        return 0;
    }

    return root->data+allNodesTotal(root->left)+allNodesTotal(root->right);

}

int allChildTotal(Node *root){
    if(root==NULL){
       return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    return allChildTotal(root->left) + allChildTotal(root->right);
}


int allInternalNodes(Node *root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return 0;
    }

    return root->data + allInternalNodes(root->left) + allInternalNodes(root->right);
}

int main(){

    Node *root = NULL;

    int size, choice, val, i;

    do{
        printf("\n1°Insert");
        printf("\n2° all Noedes Total");
        printf("\n3° all  Childs Total ");
        printf("\n4° all Internal Nodes Total");

        printf("\nchoice : ");

        scanf("%d",&choice);


    switch (choice){
            case 1:
            printf("Give it a Size");
            scanf("%d",&size);
            if(size<=0) return 0;

                    i = 0;
                
                    while(i<size){
                        printf("%d == > ", i+1);
                        scanf("%d", &val);
                        root = insert(root, val);
                        i++;
                    }   

            break;

            case 2:
            if(root==NULL){
                printf("root = null");
            } else{
                printf("%d",allNodesTotal(root));
            }
            break;

            case 3:

            if(root==NULL){
                printf("root = null");
            } else{
                printf("%d",allChildTotal(root));
            }

            break;
            

            case 4:
                if(root==NULL){
                    return 0;
                } else {
                    printf("%d", allInternalNodes(root));
                }
            break;

            default:
                printf("Cmd Not found");
            break;
        }

    }while(choice != 0 );

        
    return 0;
}