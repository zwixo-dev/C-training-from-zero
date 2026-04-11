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
    }   else if(getVal>root->data){
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


// rotation Right Right

Node *rotationRR(Node *root){

    Node *child = root->right;
    root->right = child->left;

    child->left = root;

    return child;
}


// rotation Left Right

Node *rotationLR(Node *root){

    root->left = rotationRR(root->left);

    return rotationLL(root);
}

// roatation Right Left 

Node *rotationRL(Node *root){
    root->right = rotationLL(root->right);

    return rotationRR(root);
}


void display(Node *root, int space){
    if(root==NULL){
        return;
    }

    if(root!=NULL){
        display(root->left , space+5);
        printf("\n \n %d*", space, root->data);
        display(root->right, space+5);
    }

}


int main(){

    Node *root = NULL;

    int choice, val , size, i;


    do{
       
        printf("\n1) Insert");
        printf("\n2) Rotation Left Left");
        printf("\n3) Rotation Right Right");
        printf("\n4) Rotation Left Right");
        printf("\n5) Rotation Right Left");
        printf("\n6) Display");
        printf("\nchoice : ");
            scanf("%d", &choice);

        switch(choice){

            case 1:
                i = 0 ;
                printf("size : ");
                scanf("%d", &size);

                if(size<=0){
                    printf("\n root = null \n");
                } else{
                    while(i<size){
                        printf("%d ) ===> ", i+1);
                        scanf("%d", &val);
                        root = insert(root, val);
                        i++;
                    }
                }
            break;

            case 2:
            printf("rotationLL Applied");
                if(root!=NULL){
                    root  = rotationLL(root);
                }
            break;

            case 3:
            printf("rotationRR Applied");
                if(root!=NULL){
                    root  = rotationRR(root);
                }
            break;

            case 4:
            printf("rotationLR Applied");
                if(root!=NULL){
                    root  = rotationLR(root);
                }
            break;

            case 5:
            printf("rotationRL Applied");
                if(root!=NULL){
                    root = rotationRL(root);
                }
            break;

            case 6:
                printf("=============== Display ===============");

            break;

            default:
                printf("cmd not found");
                display(root, 0);
            break;

        }}while(choice!=0);



    return 0;
}