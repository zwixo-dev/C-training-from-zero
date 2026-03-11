// rewrite the day 44.c with  ==========recursive version============= 


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
    
    newNode->data = getVal;
    newNode->left = NULL;
    newNode->right = NULL;    
}

Node *insert(Node *root, int getVal){
    if(root == NULL){
        return cree(getVal);
    }

        if(getVal < root->data){
            root->left = insert(root->left, getVal);
        } else if(getVal>root->data){
            root->right = insert(root->right, getVal);
        } else{
            return root;
        }
    
  return root;  
}




int main(){
   
    Node *root = NULL;
    int i, size, choice, val; 


    do{
        
        printf("1) Insert \n");
        printf("2) Search \n");
        printf("3) min \n");
        printf("4) max \n");
        
        printf( "==> Entere a Choice : ");
        scanf("%d", &choice);
        
    switch(choice){
        case 1:
            i =0;
            printf("Give the TREE a size :");
            scanf("%d", &size);
            
            if(size<1){
                printf("\ngive the tree a size > 1\n");
            }
            
            while(i<size){
                printf("value %d :", i+1);
                scanf("%d",&val);
                root = insert(root, val);
                i++;
            }
        
        break;
        
        default:
            if(choice != 5){
                printf("\n choice Not found");
            }
        break;
            
    }}while(choice!=5);
    
    
    return 0;
}