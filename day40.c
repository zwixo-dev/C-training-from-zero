#include <stdio.h>
#include <stdlib.h>

// Structures
typedef struct file {
    int data;
    struct file *next;
} File;

typedef struct pile {
    int data;
    struct pile *next;
} Pile;

//FIFO

int isEmpty(File *head) {
    return (head == NULL);
}

void push(File **head, File **tail, int val) {
    File *newNode = malloc(sizeof(File));
    if (!newNode) return;
    
    newNode->data = val;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    printf("%d added to Queue\n", val);
}

void removing(File **head, File **tail) {
    if (isEmpty(*head)) {
        printf("Status : Queue Empty !");
        return;
    }
    
    File *toDelete = *head;
    int val = toDelete->data;
    
    *head = (*head)->next;
    
    if (*head == NULL) {
        *tail = NULL;
    }
    
    printf("%d removed from Queue", val);
    free(toDelete);
}

void desplayQueue(File *head) {
    if (isEmpty(head)) {
        printf("Queue Status : Empty");
        return;
    }
    
    File *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//LIFO

Pile *empiler(Pile *top, int val) {
    Pile *newNode = malloc(sizeof(Pile));
    if (!newNode) return top;
    
    newNode->data = val;
    newNode->next = top;
    
    printf("%d added to Stack\n", val);
    return newNode; // Return the NEW top
}

void displayAndClearPile(Pile **top) {
    if (*top == NULL) {
        printf("Stack Status : Empty");
        return;
    }

    Pile *current = *top;
    Pile *nextNode;

    while (current != NULL) {
        printf("%d -> ", current->data);
        nextNode = current->next; // Save next node
        free(current);            // Delete current
        current = nextNode;       // Move forward
    }
    
    printf("NULL (Stack Cleared)\n");
    *top = NULL; // Reset 
}

// --- MAIN ---

int main() {
    File *head = NULL;
    File *tail = NULL;    
    Pile *top = NULL;
        
    int choice, val;    
    
    do {
        printf("\n--- MENU ---\n");
        printf("1 ====> Is Empty (Queue)\n");
        printf("2 ====> Add (Both)\n");
        printf("3 ====> Dequeue\n");
        printf("4 ====> Display Queue\n");
        printf("5 ====> Display & Clear Stack\n");
        printf("0 ====> Exit\n");
        printf("Choice : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (isEmpty(head)) printf("Status : Empty !");
                else printf("Status : Not Empty !");
                break;
            
            case 2:
                printf("Enter a value : ");
                scanf("%d", &val);
                push(&head, &tail, val);
                top = empiler(top, val);
                break;
            
            case 3:
                removing(&head, &tail);
                break;
            
            case 4:
                desplayQueue(head);
                break;
            
            case 5:
                displayAndClearPile(&top); 
                break;
            
            case 0:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice !");
                break;
        }
    } while (choice != 0);
    
    return 0;
}