#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;


Node *cree(int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

Node *insert(Node *root, int getVal) {
    if (root == NULL) return cree(getVal);
    if (getVal < root->data) {
        root->left = insert(root->left, getVal);
    } else if (getVal > root->data) {
        root->right = insert(root->right, getVal);
    }
    return root;
}

int compteNodes(Node *root) {
    if (root == NULL) return 0;
    return 1 + compteNodes(root->left) + compteNodes(root->right);
}


int compteInternes(Node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + compteInternes(root->left) + compteInternes(root->right);
}


int compteFeuilles(Node *root) {
    if (root == NULL){
         return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return compteFeuilles(root->left) + compteFeuilles(root->right);
}


int sontIdentiques(Node *a, Node *b) {
    if (a == NULL && b == NULL) return 1;
    if (a != NULL && b != NULL) {
        return (a->data == b->data && 
                sontIdentiques(a->left, b->left) && 
                sontIdentiques(a->right, b->right));
    }
    return 0;
}


int  hauteur(Node *root){
    if(root == NULL){
        return -1;
    }
    
    int hauteurLeft = hauteur(root->left);
    int hauteurRight = hauteur(root->right);
    
    if(hauteurLeft > hauteurRight){
        return 1 + hauteurLeft;
    } else{
        return 1 + hauteurRight; 
    }
    
}

// valeur d'un arabre selon le parcours 

void affichageNiveau(Node *root, int niveau){
    if(root == NULL){
        return;
    }
    
    if(niveau == 0){
        printf("%d ", root->data);
    } else{
        affichageNiveau(root->left, niveau-1);
        affichageNiveau(root->right, niveau-1);
    }
}

int parcoursLargeur(Node *root){
    if(root == NULL){
          printf("Arbre Vide\n");
          return 0;
    }
    int h = hauteur(root);
    
    int i =0;
    
    while(i<=h){
         affichageNiveau(root, i);
        i++;
    }
    printf("\n");
    
    return 1;
}

// Supprime
Node* supprimer(Node* root) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    root->left = supprimer(root->left);
    root->right = supprimer(root->right);

    return root;
}

// un seul enfant 

int seulENfant(Node *root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return 1;
    }
    
    if(root->left != NULL && root->right != NULL){
        return 0;
    }
    
    if(root->left  != NULL){
        return seulENfant(root->left);
    } else{
        return seulENfant(root->right);
    }
    
}

void afficherSansFrere(Node *root) {
    
    if(root == NULL){
        return;
    }
    
    if(root->left != NULL && root->right == NULL) {
        printf("%d ", root->left->data);
    }
    

    if(root->right != NULL && root->left == NULL) {
        printf("%d ", root->right->data);
    }


    afficherSansFrere(root->left);
    afficherSansFrere(root->right);
} 



int main() {
    Node *root = NULL;
    Node *root1 = NULL;
    int choice, i, val, size;

    do {
        printf("\n--- MENU ---");
        printf("\n1- Remplir Arbre 1");
        printf("\n2- Remplir Arbre 2");
        printf("\n3- Nombre total de noeuds (Arbre 1)");
        printf("\n4- Nombre de noeuds internes (Arbre 1)");
        printf("\n5- Nombre de feuilles (Arbre 1)");
        printf("\n6- Comparer Arbre 1 et Arbre 2");
        printf("\n7- Hauteur de l'arbre");
        printf("\n8- (6) Arbre Selon le parcours en largeur");
        printf("\n9- (7) suppression");
        printf("\n10- (8) si chaque noeud a un seul enfant");
        printf("\n11- (9) affichage Sans Frere");
        
        
        printf("\nVotre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("size Arbre 1 : ");
                scanf("%d", &size);
                for(i = 0; i < size; i++) {
                    printf("Val %d : ", i + 1);
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                break;

            case 2:
                printf("size Arbre 2 : ");
                scanf("%d", &size);
                for(i = 0; i < size; i++) {
                    printf("Val %d : ", i + 1);
                    scanf("%d", &val);
                    root1 = insert(root1, val);
                }
                break;

            case 3:
                printf("Total noeuds : %d\n", compteNodes(root));
                break;

            case 4:
                printf("Noeuds internes : %d\n", compteInternes(root));
                break;

            case 5:
                printf("Feuilles : %d\n", compteFeuilles(root));
                break;

            case 6:
            
                if (sontIdentiques(root, root1)){
                    printf("Les arbres sont IDENTIQUES.\n");
                }
                
                else{
                    printf("Les arbres sont DIFFERENTS.\n");
                }
                break;
            
            case 7:
            
                if(hauteur(root) != -1){
                    printf("Hauteur = %d", hauteur(root));
                }else{
                    printf("Arbre Vide\n");
                }
            break;
            
            case 8:
                int vAL = parcoursLargeur(root); 
                printf("\nCode de retour du parcours : %d\n", vAL);
            break;
            
            case 9:
                root = supprimer(root);
                printf("Succès de la suppression ");
            break;
            
            case 10:
              if (seulENfant(root)) {
                    printf("Chaque noeud interne a exactement UN SEUL enfant.\n");
                } else {
                 printf("Certains noeuds ont deux enfants (ou l'arbre est different).\n");
            }
            break;
            
            case 11:
                    printf("Noeuds sans frere : ");
                if (root == NULL || (root->left == NULL && root->right == NULL)) {
                         printf("Aucun (Arbre vide ou seulement racine)");
                } else {
                     afficherSansFrere(root);
                 }
                printf("\n");
            break;
            
            default:
                printf("Choix invalide.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
