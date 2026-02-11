#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int data;
    struct queue *next;
} Queue;



// is empty
int isEmpty(Queue *head) {
    return head == NULL;
}

// Enqueu
void enqueue(Queue **head, Queue **tail, int val) {
    Queue *newNode = malloc(sizeof(Queue));
    if (!newNode) return;

    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("%d added to Queue\n", val);
}

// Dequeue
int dequeue(Queue **head, Queue **tail) {
    if (isEmpty(*head)) {
        printf("Queue is Empty!\n");
        return -1; // sentinel value
    }

    Queue *temp = *head;
    int val = temp->data;

    *head = (*head)->next;
    if (*head == NULL) *tail = NULL;

    free(temp);
    return val;
}

// Display
void displayQueue(Queue *head) {
    if (isEmpty(head)) {
        printf("Queue is Empty!\n");
        return;
    }

    Queue *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//MERGE FUNCTION
Queue* mergeQueues(Queue *head1, Queue *head2) {
    Queue *mergedHead = NULL, *mergedTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        int val;
        if (head1->data < head2->data) {
            val = head1->data;
            Queue *tmp = head1;
            head1 = head1->next;
            free(tmp);
        } else {
            val = head2->data;
            Queue *tmp = head2;
            head2 = head2->next;
            free(tmp);
        }

        Queue *newNode = malloc(sizeof(Queue));
        newNode->data = val;
        newNode->next = NULL;

        if (mergedHead == NULL) mergedHead = mergedTail = newNode;
        else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }


    while (head1 != NULL) {
        Queue *newNode = malloc(sizeof(Queue));
        newNode->data = head1->data;
        newNode->next = NULL;

        if (mergedHead == NULL) mergedHead = mergedTail = newNode;
        else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }

        Queue *tmp = head1;
        head1 = head1->next;
        free(tmp);
    }

    while (head2 != NULL) {
        Queue *newNode = malloc(sizeof(Queue));
        newNode->data = head2->data;
        newNode->next = NULL;

        if (mergedHead == NULL) mergedHead = mergedTail = newNode;
        else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }

        Queue *tmp = head2;
        head2 = head2->next;
        free(tmp);
    }

    return mergedHead;
}


int main() {
    Queue *head1 = NULL, *tail1 = NULL;
    Queue *head2 = NULL, *tail2 = NULL;
    Queue *mergedHead = NULL;

    int choice, val;

    do {
        printf("\n--- MENU ---\n");
        printf("1) Add to Queue 1\n");
        printf("2) Add to Queue 2\n");
        printf("3) Display Queue 1\n");
        printf("4) Display Queue 2\n");
        printf("5) Merge Queues\n");
        printf("6) Display Merged Queue\n");
        printf("0) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&head1, &tail1, val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&head2, &tail2, val);
                break;

            case 3:
                printf("Queue 1: ");
                displayQueue(head1);
                break;

            case 4:
                printf("Queue 2: ");
                displayQueue(head2);
                break;

            case 5:
                mergedHead = mergeQueues(head1, head2);
                head1 = tail1 = head2 = tail2 = NULL; 
                printf("Queues Merged!\n");
                break;

            case 6:
                printf("Merged Queue: ");
                displayQueue(mergedHead);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 0);

    return 0;
}