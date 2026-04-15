#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data; 
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return NULL;

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int height(Node *root){
    if(root == NULL) return -1;

    int hLeft = height(root->left);
    int hRight = height(root->right);

    return 1 + (hLeft > hRight ? hLeft : hRight);
}

int balanceFactor(Node *root){
    if(root == NULL) return 0;
    return height(root->left) - height(root->right);
}

Node *rotationLL(Node *root){
    Node *child = root->left;
    root->left = child->right;
    child->right = root;

    return child;
}

Node *rotationRR(Node *root){
    Node *child = root->right;
    root->right = child->left;
    child->left = root;

    return child;
}

Node *insert(Node *root, int val){
    if(root == NULL){
        return createNode(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    } else if(val > root->data){
        root->right = insert(root->right, val);
    } else {
        return root;
    }

    int bf = balanceFactor(root);

    if(bf > 1 && val < root->left->data){
        printf("Rotation LL\n");
        return rotationLL(root);
    }

    if(bf < -1 && val > root->right->data){
        printf("Rotation RR\n");
        return rotationRR(root);
    }

    if(bf > 1 && val > root->left->data){
        printf("Rotation LR\n");
        root->left = rotationRR(root->left);
        return rotationLL(root);
    }

    if(bf < -1 && val < root->right->data){
        printf("Rotation RL\n");
        root->right = rotationLL(root->right);
        return rotationRR(root);
    }

    return root;
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
    int choice, val, size, i;

    do{
        printf("\n1° Insert");
        printf("\n0° Exit");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Give number of elements: ");
                scanf("%d", &size);

                for(i = 0; i < size; i++){
                    printf("%d) => ", i+1);
                    scanf("%d", &val);
                    root = insert(root, val);
                }

                printf("\nTree:\n");
                display(root, 0);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 0);

    return 0;
}