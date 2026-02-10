#include <stdio.h>
#include <stdlib.h>


typedef struct pile{
    int data;
    struct pile *next;
}Pile;

// is empty 

int isEmpty(Pile *top){
    return(top == NULL);    
}

// empiler 

Pile *empiler(Pile *top, int val){
    
    Pile *newNode = malloc(sizeof(Pile));
    
    newNode->data = val;
    newNode->next = top;
    
    top = newNode;
    
    return top;
}

// depiler 

Pile *depiler(Pile *top, int *val){
        
        if(isEmpty(top)){
            return 0;
        }
        
    Pile *toDelete = NULL;
    *val = toDelete->data;
    top = toDelete->next;
    
    
    printf("%d removed", *val);
    free(toDelete);
    return top;    
}

int main(){
    Pile *top = NULL;
    
    
    
    
    
    
    return 0;
}