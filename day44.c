#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

typedef struct file {
    Node *nodeTree;
    struct file *next;
} File;

Node *cree(int val) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = val;
    newNode->left =NULL;
    newNode->right = NULL;
   
    return newNode;
}
// insert fonction
Node *inserer(Node *racine, int val){
    if(racine == NULL){
       return cree(val);
    }
   
    Node *current = racine;
    Node *parent = NULL;

    while(current != NULL){
        parent = current;
        if(val < current->data){
           current = current->left;
        }else if(val > current->data){
            current = current->right;
        } else {
            return racine;
        }
    }
   
    if(val < parent->data){
        parent->left = cree(val);
    } else {
        parent->right = cree(val);
    }
   
    return racine;
}

//si Vide
int isEmpty(File *head) {
    return (head== NULL);
}
// enfiler
void enfiler(File **head, Node *n) {
    if (n == NULL){
        return;
    }
   
    File *newNode = malloc(sizeof(File));
    newNode->nodeTree = n;
    newNode->next = NULL;
   
    if (*head == NULL) {
        *head = newNode;
    } else {
        File *tail = *head;
        while (tail->next != NULL){
             tail = tail->next;
        }
        tail->next = newNode;
    }
}

Node* defiler(File **head) {
   
    if (isEmpty(*head)){
        return NULL;
    }
   
    File *temp = *head;
    Node *n = temp->nodeTree;
    *head = (*head)->next;
   
    free(temp);
   
    return n;
}

// affichage
void affichageLargeur(Node *racine) {
    if (racine == NULL){
        printf("la racine est Vide ! ");
        return;
    };
   
    File *maFile  = NULL;
    enfiler(&maFile , racine);

    while (!isEmpty(maFile )) {
        Node *current = defiler(&maFile );
        printf("%d ", current->data);

        if (current->left != NULL){
            enfiler(&maFile , current->left);
        }
       
        if (current->right != NULL){
            enfiler(&maFile , current->right);
        }
    }
   
    printf("\n");
}

// min
int min(Node *racine){
    if(racine == NULL){
        return -1;
    }
    while(racine->left != NULL){
        racine = racine->left;
    };
    return racine->data;
}

// max
int max(Node *racine){
    if(racine == NULL){
        return -1;
    }
    while(racine->right != NULL){
        racine = racine->right;
    }
    return racine->data;
}

// rechrche
int search(Node *racine, int toSearch){
    if(racine == NULL){
        printf("racine est Vide");
        return 0;
    }
    Node *current = racine;
    while(current != NULL){
       if(toSearch == current->data){
            printf("\nla valeur %d exist\n", toSearch);
            return 0;
       }
       
       if(toSearch < current->data){
           current = current->left;
       } else{
           current = current->right;
       }
       
    }
   
    printf("la valeur n'exist pas");
    return 0;
}

// supprime
Node *supprime(Node *racine){
    if(racine==NULL){
        printf("racine est Vide ");
    }
   
    Node *current = racine;
   
    while(current != NULL){
        if(current->left == NULL && current->right == NULL){
            free(racine);
            return NULL;
        }
    }
   
}


int main() {
    Node *racine = NULL;
     int i, n, val,choice,toSearch;
   
    do {
        printf("\n1) Insert");
        printf("\n2) Min");
        printf("\n3) Max");
        printf("\n4) cherche");
        printf("\n5) supprime");
        printf("\n6) Affichage");
        printf("\nEntrez Votre Choix :");
       
        scanf("%d", &choice);
       
        switch(choice) {
            case 1:
                printf("Give it a size : ");
                scanf("%d", &n);
               
                i = 0;
                while(i<n){
                    printf("Write the value %d : ", i+1);
                        scanf("%d", &val);
                        racine = inserer(racine, val);
                         i++;
                }
               
            break;
           
            case 2:
                if(min(racine) != -1){
                    printf("\n ==> Min = %d ", min(racine));
                } else{
                    printf("racine est Vide");
                }
            break;
           
            case 3:
                if(max(racine) != -1){
                    printf("\n ==> Min = %d ", max(racine));
                } else{
                    printf("racine est Vide");
                }
            break;

            case 4:
                printf(" Entrez pour rechercher : ");
                scanf("%d", &toSearch);
                search(racine, toSearch);
            break;
           
            case 5:
                supprime(racine);
                affichageLargeur(racine);
            break;
           
            case 6:
                printf("======= Affichage =======");
                affichageLargeur(racine);
            break;
           
            default:
            printf("\n Choice n'exist pas ! \n");
            break;
        }
       
    } while(choice != 6);
   
    return 0;
}