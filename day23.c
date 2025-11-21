#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

int main(){
    int N;
    printf("How many nodes do you want to create? ");
    scanf("%d", &N);

    if(N <= 0){
        printf("N should be > 0\n");        
        return 1;
    }

    Node *head = NULL;
    Node *current = NULL;

    for(int i = 0; i < N; i++){
        Node *newNode = malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Memory allocation error!\n");
            return EXIT_FAILURE;
        }

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &newNode->value);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

 
    int sum = 0;
    printf("\nDisplay:\n");
    current = head;
    while(current != NULL){
        printf("%d | ", current->value);
        sum += current->value;
        current = current->next;
    }
    printf("\nSum of values: %d\n", sum);

   
    current = head;
    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
