#include <stdio.h>
#include <stdlib.h>


typedef struct file{
    int data;
    struct file *next;
}File;



int isEmpty(File *head){
    return(head == NULL);
}

void enfiler(File **head, File **tail, int val){
    File *newNode = malloc(sizeof(File));
    
    newNode->data = val;
    newNode->next =  NULL;
    
    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    } else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void defiler(File **head, File **tail){
    if(isEmpty(*head)){
        printf("Queue : is Empty ! ");
        return;
    }
    
    File *toDelete = *head;
    int val = toDelete->data;
    *head = (*head)->next;
    
    printf("%d removed ! ",val);
    
    if(*head == NULL){
        *tail = NULL;
    }    
    free(toDelete);
}

int main(){
    File *head = NULL;
    File *tail = NULL;
    
    
    
    
    
    return 0;
}
