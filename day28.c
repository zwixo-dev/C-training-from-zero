#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

int main() {

    Node *head   = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third  = malloc(sizeof(Node));

    if (!head || !second || !third) {
        return EXIT_FAILURE;
    }

    printf("first  : ");
    scanf("%d", &head->value);

    printf("second : ");
    scanf("%d", &second->value);

    printf("third  : ");
    scanf("%d", &third->value);

    /* link nodes */
    head->next = second;
    second->next = third;
    third->next = NULL;

    Node *current = head;

    while (current != NULL) {
        bool isPrime = true;

        if (current->value <= 1) {
            isPrime = false;
        } else {
            for (int i = 2; i * i <= current->value; i++) {
                if (current->value % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            printf("%d -> prime num\n", current->value);
        } else {
            printf("%d -> not a prime num\n", current->value);
        }

        current = current->next;
    }

    free(head);
    free(second);
    free(third);

    return 0;
}
