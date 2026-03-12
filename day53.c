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


int search(Node *root, int getValToSearch){
    if(root == NULL){
        printf("Value not found  !\n");
        return 0;
    }

        if(getValToSearch == root->data){
            printf("the value %d exist !");
            return 1;
        }
        
        
    if(getValToSearch < root->data){
        return search(root->left, getValToSearch);
    } else {
        return search(root->right, getValToSearch);
    }
}

int main(){
   
    Node *root = NULL;
    int i, size, choice, val, toSearch; 


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
          
        case 2:
            printf("searching ... : ");
            scanf("%d", &toSearch);
            search(root, toSearch);
        break;
    
        default:
            if(choice != 5){
                printf("\n choice Not found");
            }
        break;
            
    }}while(choice!=5);
    
    
    return 0;
}