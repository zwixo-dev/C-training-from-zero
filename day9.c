#include <stdio.h>
#include <string.h>
#include <unistd.h>

// pushing the words
void pushingWords(char words[][30], int size){
    printf("===> Let's push your words <===\n");
    int i = 0;
    while (i < size){
        printf("The word number %d: ", i + 1);
        scanf("%s", words[i]);
        i++;
    }
}

// display function
void display(char words[][30], int size){
    printf("=====================================================\n");
    int i = 0;
    while (i < size){
        printf("%s | ", words[i]);
        i++;
    }
    printf("\n=====================================================\n");
}

// the length of the words
void wordLength(char words[][30], int size){
    printf("Fetching Data ...\n");
    sleep(4); // sleeping 4s as delay lol ;=}
    size_t length;
    int i = 0;
    while (i < size){
        length = strlen(words[i]);
        printf("==> %s <== : %zu\n", words[i], length);
        i++;
    }
}

// the main function here !
int main(){
    int size;
    printf("How many words do you want to push: ");
    scanf("%d", &size);

    // My 2D array
    char words[size][30];

    // =================== functions ==================
    pushingWords(words, size);
    display(words, size);
    wordLength(words, size);

    return 0;
}