#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next; 
    struct node *prvs;
} Node;

int main(){
    int N;
    printf("give it size : ");
    scanf("%d", &N);
    
    if(N <= 0){
        printf(";[");
        return 1;
    }
    
    Node *head = NULL;
    Node *current = NULL;
    
    for(int i = 0; i < N; i++){
        
        Node *newNode = malloc(sizeof(Node));
        
        printf("%d)=> ", i+1);
        scanf("%d", &newNode->value); 
        
        newNode->next = NULL;
        newNode->prvs = NULL;
        
        if(head == NULL){
            head = newNode;
            current = newNode;
        } else{
            current->next = newNode;
            newNode->prvs = current;
            current = newNode;
        }
    }

    // display the numbers
    
    current = head; 
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    // reverse 
    // moving to the end of the lsit  
    current = head;
    while(current->next != NULL){
    current = current->next;
    }
    printf("\nreversing..\n");
    // printing
    while(current != NULL){
        printf("%d ", current->value);
        current = current->prvs;
    }


    // free m_m
    current = head;
    while(current != NULL){
        Node *tmp = current;
        current = current->next;
        free(tmp);
    }
    
    return 0;
}
