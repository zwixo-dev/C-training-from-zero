#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} Node;


void display(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("%d |", current->value);
        current = current->next;
    }
}


int main() {
    
    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));
        
        if(head == NULL || second == NULL || third == NULL){
            return EXIT_FAILURE;
        }
        
        // push the values
        head->value = 17;
        second->value = 18;
        third->value = 19;
        
        // linking 
        head->next = second;
        second->next = third;
        third->next = NULL;
        display(head);
        
        free(head);
        free(second);
        free(third);
        
    return 0;
}