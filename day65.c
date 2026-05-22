#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int data;
    struct Graph *next;
} Graph;

Graph *fillList(Graph *pp, int n) {
    Graph *curr = NULL;

    if (pp != NULL) {
        curr = pp;
        while (curr->next != NULL) {
            curr = curr->next;
        }
    }

    for (int i = 0; i < n; i++) {
        Graph *newNode = malloc(sizeof(Graph));
        if (newNode == NULL) {
            return NULL;
        }

        printf("   Entrez la valeur du voisin %d : ", i + 1);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (pp == NULL) {
            pp = newNode;
            curr = newNode;
        } else {
            curr->next = newNode;
            curr = newNode;
        }
    }

    return pp;
}

void display(Graph *pp) {
    Graph *curr = pp;
    while (curr != NULL) {
        printf("[ %d ] -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int degree(Graph *pp[], int sommet) {
    Graph *curr = pp[sommet]; 
    int degeree = 0;
    
    while (curr != NULL) {
        degeree += 1;
        curr = curr->next;
    }
    
    return degeree;
}

int numAretes(Graph *pp[], int numSommet){
    
    int numAretes = 0;
    
    for(int i =0; i< numSommet; i++){
        numAretes += degree(pp, i);
    }
    return numAretes/2;
}

 int chaineEulerienne(Graph *pp[], int numSommet){
     int count=0;
     for(int i=0; i<numSommet; i++){
         if(degree(pp, i) % 2 != 0){
             count++;
         }
     }
     
     if(count == 0 || count == 2){
        printf("chaine eulerienne existe\n");
        return 1;
     } else {
        printf("chaine eulerienne n'existe pas\n");
        return 0;
    }
    
 }
 
 int cycle_eulerinne(Graph *pp[], int numSommet){
     int count=0;
     
     for(int i=0; i<numSommet; i++){
         if(degree(pp, i) %2 !=0){
             count ++;
         }
     }
     
     if(count==0){
         printf("cycle eulerienne existe\n");
         return 1;
     } else{
         printf("cycle eulerienne n'existe pas\n");
         return 1;
     }
     
 }

// parcours en largeur
// si vide 
int estVide(Graph *head) {
    return (head == NULL);
}

void enfiler(Graph **head, Graph **tail, int valeur) {
    Graph *newNode = malloc(sizeof(Graph));
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

int defiler(Graph **head, Graph **tail) {
    if (estVide(*head)) {
        return -1;
    }
    Graph *temp = *head;
    int val = temp->data;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);
    return val;
}
// parcours en largeur
void parcourEn_Largeur(Graph *pp[], int numSommet, int sommet_init){
    Graph *head = NULL;
    Graph *tail = NULL;
    
    int visit[numSommet];
    for (int i = 0; i < numSommet; i++) {
        visit[i] = 0;
    }
    
    visit[sommet_init] = 1;
    enfiler(&head, &tail, sommet_init);

    printf("Resultat du parcours eN Largeur : ");

    while(!estVide(head)){
        int actuel = defiler(&head, &tail);
        printf("%d ", actuel); 
        
        Graph *curr = pp[actuel];
        while(curr != NULL){
            int v = curr->data;
            if(visit[v] == 0){
                
                visit[v] = 1;
                enfiler(&head, &tail, v);
                
            }
            
            curr = curr->next;
        }
        
    }
    printf("\n");
}
int main() {
    Graph *pp[30]; 
    for(int i = 0; i < 30; i++) {
        pp[i] = NULL;
    }

    int numSommet;
    printf("Entrez le nombre de sommets: ");
    scanf("%d", &numSommet);

    for (int i = 0; i < numSommet; i++) {
        int numVoisins;
        printf("\nSommet %d -> Combien de voisins ? : ", i);
        scanf("%d", &numVoisins);

        pp[i] = fillList(pp[i], numVoisins);
    }

    printf("\n--- Liste d'Adjacence du Graphe ---\n");
    for (int i = 0; i < numSommet; i++) {
        printf("Sommet %d : ", i);
        display(pp[i]);
    }
    
    int sommetCherche; 
    printf("\nEntrez le numéro du sommet pour calculer son degré : ");
    scanf("%d", &sommetCherche);
    
    printf("Le degre de %d = %d\n", sommetCherche, degree(pp, sommetCherche));
    
    printf("\n le nombre des des Aretes du Graph = %d ", numAretes(pp, numSommet));
    
    
    printf("\n-------------- Chiane eulerienne --------------\n");
    chaineEulerienne(pp, numSommet);
    
    printf("\n-------------- Cycle eulerienne --------------\n");
    cycle_eulerinne(pp, numSommet);
    
    // parcours largeur
    
     printf("\n-------------- Parcours en Largeur --------------\n");
    
    int sommet_init;
    printf("Entrez le sommet de depart : ");
    scanf("%d", &sommet_init);
    
    if (sommet_init>= 0 && sommet_init< numSommet) {
        parcourEn_Largeur(pp,numSommet, sommet_init);
    } else {
        printf("Sommet init invalide\n");
    }
    

    return 0;
}

