#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
   
    int data;
    struct Graph *next;
   
} Graph;

Graph *felling(Graph *head, int n) {
   
    Graph *curr = NULL;
   
    for (int i = 0; i < n; i++) {
        Graph *newNode = malloc(sizeof(Graph));
       
        if (!newNode) {
            return NULL;
        }
       
        printf("Entrez la valeur pour l'element %d : ", i + 1);
        scanf("%d", &newNode->data);
       
        newNode->next = NULL;
       
        if (head == NULL) {
            head = newNode;
            curr = newNode;
           
        } else {
            curr->next = newNode;
            curr = newNode;
           
        }
    }
   
    return head;
}

int main() {
    Graph *head = NULL;
    int size;
   
    printf("donne une size de list : ");
    scanf("%d", &size);
   
    if (size <= 0) {
        return 0;
    }
   
    head = felling(head, size);
   
    return 0;
}