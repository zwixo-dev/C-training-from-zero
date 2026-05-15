#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

int matriX(int size, int matrix[size][size]) {
    int i = 0, j = 0;
    while (i < size) {
        j = 0;
        while (j < size) {
            printf("[%d][%d] : ", i, j);
            scanf("%d", &matrix[i][j]);
            j++;
        }
        i++;
    }
    return 0;
}

int degree(int size, int matrix[size][size], int sommet) {
    int deg = 0, j = 0;
    while (j < size) {
        if (matrix[sommet][j] == 1) {
            deg += 1;
        }
        j++;
    }
    return deg;
}

int nombre_Aretes(int size, int matrix[size][size]) {
    int total_degree = 0, i = 0, j = 0;
    while (i < size) {
        j = 0;
        while (j < size) {
            if (matrix[i][j] == 1) {
                total_degree += 1;
            }
            j++;
        }
        i++;
    }
    return total_degree / 2;
}

int chaine_Eulerienne(int size, int matrix[size][size]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (degree(size, matrix, i) % 2 != 0) {
            count++;
        }
    }
    if (count == 0 || count == 2) {
        printf("chaine eulerienne existe\n");
        return 1;
    } else {
        printf("chaine eulerienne n'existe pas\n");
        return 0;
    }
}

int cycle_Eulerienne(int size, int matrix[size][size]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (degree(size, matrix, i) % 2 != 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("cycle eulerienne existe\n");
        return 1;
    } else {
        printf("cycle eulerienne n'existe pas\n");
        return 0;
    }
}

// si vide
int estVide(Node *head) {
    return (head == NULL);
}

void enfiler(Node **head, Node **tail, int valeur) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = valeur;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int defiler(Node **head, Node **tail) {
    if (estVide(*head)) {
        return -1;
    }
    Node *temp = *head;
    int val = temp->data;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);
    return val;
}

void parcours_En_Largeur(int size, int matrix[size][size], int sommet_init){
    Node *head = NULL;
    Node *tail = NULL;
   
    int visit[size];
   
    for(int i =0; i<size; i++){
        visit[i] = 0;
    }
   
    visit[sommet_init] = 1;
   
    enfiler(&head, &tail, sommet_init);
   
    printf("Parcours en largeur");
   
    while(!estVide(head)){
        int acteul = defiler(&head, &tail);
        printf("%d", acteul);
       
        for(int v = 0; v<size; v++){
            if(matrix[acteul][v]==1 && visit[v]==0){
                visit[v] = 1;
                enfiler(&head, &tail, v);
            }
        }
    }
    printf("\n");
}


int main() {
    int size;
    printf("enterz le size de matrice : ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("size n'est pas >0\n");
        return 0;
    }

    int matrix[size][size];
    matriX(size, matrix);

    int sommet;
   
    printf("degree d'un sommet : ");
   
    scanf("%d", &sommet);

    if (sommet >= 0 && sommet < size) {
        printf("Le degre du sommet %d est : %d\n", sommet, degree(size, matrix, sommet));
    } else {
        printf("Sommet invalide\n");
    }

   
    printf("Nombre d'aretes : %d\n", nombre_Aretes(size, matrix));

    chaine_Eulerienne(size, matrix);
    cycle_Eulerienne(size, matrix);
   
    int sommet_init;
    printf("Entrez le sommet de depart : ");
    scanf("%d", &sommet_init);
   
    if (sommet_init>= 0 && sommet_init< size) {
        parcours_En_Largeur(size, matrix, sommet_init);
    } else {
        printf("Sommet BFS invalide\n");
    }
   

    return 0;
}


// enterz le size de matrice : 3
// 0 1 1 0
// 1 0 0 1
// 1 0 0 1
// 0 1 1 0