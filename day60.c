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
    if(root == NULL){
        return cree(getVal);
    }
    
    if(getVal < root->data){
        root->left = insert(root->left, getVal);
    } else if(getVal > root->data){
        root->right = insert(root->right, getVal);
    }
    
    return root;
}

Node *rotationLL(Node *root){
    if(root==NULL || root->left==NULL){
        return root;
    }
    
    Node *child = root->left;
    root->left = child->right;
    child->right = root; 
    return child;
}

Node *rotationRR(Node *root){
    if(root==NULL || root->right==NULL){
        return root;
    }
    
    Node *child = root->right;  
    root->right = child->left;  
    child->left = root;  
    
    return child;           
}

Node *rotationLR(Node *root){
    if(root == NULL || root->left == NULL){
        return root;
    }
    Node *child = root->left;
    root->left = rotationRR(child); 
    
    return rotationLL(root);
}

Node *rotationRL(Node *root){
    if(root == NULL || root->right == NULL){
        return root;
    }
    Node *child = root->right;
    root->right = rotationLL(child);
    
    return rotationRR(root);
}


void display(Node *root, int space){
    if(root == NULL) return;

    space += 10;

    display(root->right, space);

    printf("\n");
    for(int i = 10; i < space; i++) printf(" ");
    printf("%d\n", root->data);

    display(root->left, space);
}

int hauteur(Node *root){
    if(root==NULL){
        return -1;
    }
    int hLeft = hauteur(root->left);
    int hRight = hauteur(root->right);

    if(hLeft>hRight){
        return 1 + hLeft;
    } else {
        return 1 + hRight;
    }
}

int bf(Node *root){
    if(root == NULL){
        return 0;
    }
    return hauteur(root->left) - hauteur(root->right);
}

Node *equilbre(Node *root){
    if(root==NULL){
        return NULL;
    }
    
    int calculBF = bf(root);
    
    if(calculBF>1){
        if(bf(root->left)>=0){
           root= rotationLL(root);
        } else {
           root= rotationLR(root);
        }
    } 
    
    if(calculBF<-1){
        if(bf(root->right)<=0){
         root = rotationRR(root);
        } else {
            root = rotationRL(root);
        }
    }
    
    return root;
}

int main(){
    Node *root = NULL;
    int val, choice, size, i = 0;
    
    do{
        printf("\n1° Insert ");
        printf("\n2° Rotation LL");
        printf("\n3° Rotation RR ");
        printf("\n4° Rotation LR");
        printf("\n5° Rotation RL");
        printf("\n6° Equilibre");
        printf("\nvotre Choix : ");
        
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("donner une size : ");
                scanf("%d", &size);
                if(size<=0){
                    printf("donner une size > 0");
                } else {
                    i = 0;
                    while(i<size){
                        printf("%d)===>", i+1);
                        scanf("%d",&val);
                        root = insert(root , val);
                        i++;
                    }
                    // affichage(root, 0);
                }
                break;
            
            case 2: 
                root = rotationLL(root);
                display(root, 0);
                printf("\nrotation LL succes");
                break;
            
            case 3:
                root = rotationRR(root);
                display(root, 0);
                printf("\nrotation RR succes");
                break;
            
            case 4:
                root = rotationLR(root);
                display(root, 0);
                printf("\nrotation LR succes");
                break;
            
            case 5:
                root = rotationRL(root);
                display(root, 0);
                printf("\nrotation RL succes");
            break;
            
            case 6:
            root = equilbre(root);
             display(root, 0);
            break;

            default:
                printf("cmd not found");
                break;
        }
    } while(choice != 0); 
    
    return 0; 
}