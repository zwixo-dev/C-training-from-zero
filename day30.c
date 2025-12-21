#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next; 
    struct node *prvs;
} Node;

// filling the list
Node* filling(Node *head, int N) {
    Node *current = NULL;

    for(int i = 0; i < N; i++) {
        Node *newNode = malloc(sizeof(Node));
        if(!newNode) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("%d) => ", i + 1);
        scanf("%d", &newNode->value);

        newNode->next = NULL;
        newNode->prvs = NULL;

        if(head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            newNode->prvs = current;
            current = newNode;
        }
    }

    return head;
}

// displaying the list
void display(Node *head) {
    Node *current = head;
    printf("List: ");
    while(current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// displaying list in reverse
void reversing(Node *head) {
    if(head == NULL) return;

    Node *current = head;
    while(current->next != NULL) {
        current = current->next;
    }

    printf("Reversing: ");
    while(current != NULL) {
        printf("%d ", current->value);
        current = current->prvs;
    }
    printf("\n");
}

// deleting a value from the list
Node* deleting(Node *head) {
    int check, delValue;
    printf("\nNote: 1 = yes / 0 = no\n");
    printf("Do you want to delete a number? 1/0: ");
    scanf("%d", &check);

    if(check != 1) {
        printf("You will see the old list...\n");
        return head;
    }

    printf("Number to delete: ");
    scanf("%d", &delValue);

    Node *current = head;

    while(current != NULL) {
        if(current->value == delValue) {
            Node *toDelete = current;

            // if deleting head
            if(toDelete == head) {
                head = toDelete->next;
                if(head != NULL) head->prvs = NULL;
            } else {
                if(toDelete->prvs != NULL)
                    toDelete->prvs->next = toDelete->next;
                if(toDelete->next != NULL)
                    toDelete->next->prvs = toDelete->prvs;
            }

            current = toDelete->next; // move to next node
            free(toDelete);           // free memory
        } else {
            current = current->next;
        }
    }

    return head;
}

// freeing the list
void liberation(Node *head) {
    Node *current = head;
    while(current != NULL) {
        Node *tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main() {
    int N;
    printf("Enter the size of the list: ");
    scanf("%d", &N);

    if(N <= 0) {
        printf("Invalid size :[\n");
        return 1;
    }

    Node *head = NULL;

    head = filling(head, N);
    display(head);
    reversing(head);

    head = deleting(head);
    display(head);

    liberation(head);

    return 0;
}