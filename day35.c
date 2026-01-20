#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

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

 // clear screen 
 void clear_screen() {
    // Windows
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        //Linux Unix, macOs
        system("clear");
    #endif
}

void deletingByIndex(char *getWord[], int *getCount) { 
    int index_to_delete;
    printf("===> ");
    scanf("%d", &index_to_delete);
    
    if (index_to_delete < 0 || index_to_delete >= *getCount) {
        printf("Invalid index to delete!\n");
        return; 
    }

    free(getWord[index_to_delete]);

    int i = index_to_delete;
    while (i < *getCount - 1) {
        getWord[i] = getWord[i + 1];
        i++;
    }

    (*getCount)--; // update the count in the main 
    printf("Item deleted successfully.\n");
}

// --help 

void help(){
    char *help[] = {"add", "ls", "ls-i", "del-i", "cls"};
    char *helpDescription[] = {
                "-> add a word",
                "-> list all words", " -> show by index", 
                "-> delete by index", "-> clear screen"};
                

  
    size_t length = sizeof(help) / sizeof(help[0]);
    for(int i = 0; i< length; i++){
        printf("\t %s \t %s \n", help[i], helpDescription[i]);
    }
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
        }  else if( (strcmp(cli, "cls") == 0) || (strcmp(cli, "clear") == 0)){
            clear_screen();
        } else if(strcmp(cli, "del-i") == 0){
            deletingByIndex(word,&count);
        } else if(strcmp(cli, "--help") == 0){
            help();
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

