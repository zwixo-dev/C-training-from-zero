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

Node *equilibre(Node *root){
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


Node *insert(Node *root, int getVal){
    if(root == NULL){
        return cree(getVal);
    }
    
    if(getVal < root->data){
        root->left = insert(root->left, getVal);
    } else if(getVal > root->data){
        root->right = insert(root->right, getVal);
    }
    
    root = equilibre(root);
    
    return root;
}

Node *deleteNode(Node *root, int getTo_Delete ){
    
    if(root==NULL){
        return NULL;
    }
    
    if(getTo_Delete < root->data){
        root->left =  deleteNode(root->left, getTo_Delete);
    } else if(getTo_Delete > root->data){
        root->right =  deleteNode(root->right, getTo_Delete);
    } else{
        
        if(root->left == NULL){
            Node *temp  = root->right;
            free(temp);
            return temp;
        } else if(root->right == NULL){
            Node *temp = root->left;
            free(temp);
            return temp;
        }else{
            Node *temp = root->right;
            while(temp && temp->left!=NULL){
                temp = temp->left;
            }
            
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            
        }
        
    }
    
    return equilibre(root);
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

int main(){
    Node *root = NULL;
    int val, choice, size, toDelete,i = 0;
    
    do{
        printf("\n1° Insert ");
        printf("\n2° Affichage ");
        printf("\n3° delete ");
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
                    printf("\n===========Affichage===========\n");
                    display(root, 0);
                break;
                
                case 3:
                    printf("Entrer un Nombre : ");
                    scanf("%d", &toDelete);
                    root = deleteNode(root, toDelete );
                    printf("Delete avec succes");
                break;
                
            default:
                printf("cmd not found");
                break;
        }
    } while(choice != 0); 
    
    return 0; 
}