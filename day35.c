#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display(char *getWord[], int getCount) {
    for (int i = 0; i < getCount; i++) {
        printf("-%s\t", getWord[i]);
    }
    printf("\n");
}

void displayByIndex(char *getWord[], int getCount) {
    int userInput;

    printf("==> ");
    scanf("%d", &userInput);

    int actualIndex = userInput - 1;

    if (actualIndex < 0 || actualIndex >= getCount) {
        printf("Item number %d does not exist!\n", userInput);
        return;
    }

    printf("Item #%d: %s\n", userInput, getWord[actualIndex]);
}

int main() {
    char cli[10];
    char *word[10];
    int count = 0;

    do {
        printf("user$/> ");
        scanf("%9s", cli);

        if (strcmp(cli, "add") == 0) {
            if (count < 10) {
                char temp[100];

                printf("add: ");
                scanf("%99s", temp);

                word[count] = strdup(temp);
                count++;
            } else {
                printf("full!\n");
            }
        } 
        else if (strcmp(cli, "ls") == 0) {
            display(word, count);
        } 
        else if (strcmp(cli, "ls-i") == 0) {
            displayByIndex(word, count);
        } 
        else {
            printf("$$$$$$$$$$$$$ commande does not exist yet $$$$$$$$$$$$$\n");
        }

    } while (strcmp(cli, "exit") != 0);

    for (int i = 0; i < count; i++) {
        free(word[i]);
    }

    return 0;
}

